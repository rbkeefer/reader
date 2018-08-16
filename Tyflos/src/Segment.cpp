#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkColumn.h"
#include "RkRow.h"
#include "RkSegment.h"
#include "RkArticle.h"

#include "Utils.h"
#include "ReduceExpand.h"
#include "Regions.h"
#include "Segment.h"

void doSegmentation(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage)
{
  printf("\nBegin Segmentation\n");

  IplImage* reducedImg;
  IplImage* regionImg;

  int reductionWidth = inOrigImage->width / inReduction;
  reducedImg =  reduceImage(inCleanedImage, reductionWidth, MIN_SEGMENTATION_HEIGHT, MIN_SEGMENTATION_WIDTH, inDemoMode, inImageFileName);

  list<RkBoundingRectangle*> regionList = getRegionBoundaries(reducedImg, BLACK);
  regionList = groupRegions(regionList);
  expandBoundingRectList(regionList, (inOrigImage->width/reductionWidth)/2);

  string* outFileName = new string(*inImageFileName);
  outFileName->append(".Segmented.txt");
  dumpSegmentList(regionList, outFileName->data());

  regionImg = cvCreateImage(cvSize(inCleanedImage->width, inCleanedImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inOrigImage, inOrigImage, inOrigImage, NULL, regionImg);
  regionImg = displayBoundaries(regionImg, regionList, COLOR_RED, THICK_LINE);
  cvNamedWindow("Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Regions", regionImg);

  string* saveImgFileName = new string(*inImageFileName);
  saveImgFileName->append(".boundaries.jpg");
  cvSaveImage(saveImgFileName->c_str(), regionImg);

  cvWaitKey(0);

  cvReleaseImage(&reducedImg);
  cvReleaseImage(&regionImg);
  cvDestroyWindow("Regions");

  list<RkBoundingRectangle*>::iterator iter;
  for (iter=regionList.begin(); iter!=regionList.end(); iter++)
	free(*iter);

  free(outFileName);

}

list<RkBoundingRectangle*> groupRegions(list<RkBoundingRectangle*> inRegionList)
{
  RkBoundingRectangle* region;
  RkBoundingRectangle* regGrp;
  list<RkBoundingRectangle*> regionList;
  list<RkBoundingRectangle*> colRegionList;
  list<RkBoundingRectangle*> rowRegionList;
  list<RkBoundingRectangle*> retRegionList;
  list<RkBoundingRectangle*>::iterator regionIter;

  for (regionIter=inRegionList.begin(); regionIter!=inRegionList.end(); regionIter++)
  {
	region = (*regionIter);
	if (! isRectangleInRectangleList(region, regionList))
	{
	  regGrp = groupRegions(region, inRegionList);
	  regionList.push_back(regGrp);
	}
  }

  regionList.reverse();

  for (regionIter=regionList.begin(); regionIter!=regionList.end(); regionIter++)
  {
	region = (*regionIter);
	if (! isRectangleInRectangleList(region, retRegionList))
	{
	  regGrp = groupRegions(region, regionList);
	  retRegionList.push_back(regGrp);
	}
  }

  return retRegionList;
}

RkBoundingRectangle* groupRegions(RkBoundingRectangle* inRegion, list<RkBoundingRectangle*> inRegionList)
{
  RkBoundingRectangle* baseRectangle = inRegion;
  bool testedAllRegions = false;
  RkBoundingRectangle* rectangle;

  if (inRegionList.size() > 0)
  {
	  int baseArea = baseRectangle->area() - 1;
	  list<RkBoundingRectangle*>::iterator regionIter = inRegionList.begin();

	  while (! ((baseArea == baseRectangle->area()) && (testedAllRegions)))
	  {
		testedAllRegions = false;
		baseArea = baseRectangle->area();
		rectangle = (*regionIter);

		if (baseRectangle->isNear(rectangle))
		  baseRectangle->join(rectangle);

		regionIter++;

		if (regionIter == inRegionList.end())
		{
		  regionIter = inRegionList.begin();
		  testedAllRegions = true;
		}
	  }
  }
  return baseRectangle;
}

void dumpSegmentList(list<RkBoundingRectangle*> inRectangleList, const char* inFileName)
{
  RkBoundingRectangle* boundingRect;
  list<RkBoundingRectangle*>::iterator iter;

  FILE* rectFile;
  rectFile = fopen(inFileName, "w");

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
	boundingRect = (*iter);
	boundingRect->printString(rectFile);
  }

  fclose(rectFile);
}

