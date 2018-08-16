#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkArticle.h"

#include "Utils.h"
#include "Classify.h"

void doClassification(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage)
{
  printf("\nBegin Classification\n");

  IplImage* segmentImg;
  IplImage* classifiedImg;

  string* inFileName = new string(*inImageFileName);
  inFileName->append(".Separated.txt");
  string* outFileName = new string(*inImageFileName);
  outFileName->append(".Classified.txt");

  list<RkSegment*> segmentList = getSeparatedSegmentList(inFileName);

  segmentImg = cvCreateImage(cvSize(inOrigImage->width, inOrigImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inOrigImage, inOrigImage, inOrigImage, NULL, segmentImg);
  segmentImg = displayBoundaries(segmentImg, segmentList, THIN_LINE);
  cvNamedWindow("Segments", CV_WINDOW_AUTOSIZE);
  cvShowImage("Segments", segmentImg);

  if (inRunMode == AUTOMATIC_MODE)
      classifySegments(segmentList, inCleanedImage);
  else
      manualClassifySegments(segmentList, inCleanedImage);

  dumpClassifiedSegmentList(segmentList, outFileName);

  classifiedImg = cvCreateImage(cvSize(inOrigImage->width, inOrigImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inOrigImage, inOrigImage, inOrigImage, NULL, classifiedImg);
  classifiedImg = displayBoundaries(classifiedImg, segmentList, THICK_LINE);
  cvNamedWindow("ClassifiedSegments", CV_WINDOW_AUTOSIZE);
  cvShowImage("ClassifiedSegments", classifiedImg);

  string* saveImgFileName = new string(*inImageFileName);
  saveImgFileName->append(".classified.jpg");
  cvSaveImage(saveImgFileName->c_str(), classifiedImg);

  cvWaitKey(0);

  cvReleaseImage(&segmentImg);
  cvDestroyWindow("Segments");

  cvReleaseImage(&classifiedImg);
  cvDestroyWindow("ClassifiedSegments");

  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=segmentList.begin(); segmentIter!=segmentList.end(); segmentIter++)
	free(*segmentIter);

  free(inFileName);
  free(outFileName);
}

void classifySegments(list<RkSegment*> inSegmentList, IplImage* inImage)
{
  map<int, int> fontHeights;
  int avgHeight;

  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    avgHeight = segment->getAvgHeight(inImage);
    fontHeights[avgHeight] = fontHeights[avgHeight] + 1;
  }

  for(map<int, int>::iterator iter = fontHeights.begin(); iter != fontHeights.end(); iter++)
  {
    printf("Avg Height: %d   Value: %d\n", (*iter).first, (*iter).second);
  }

  int histogramBreak = findBreak(fontHeights);

  printf("BREAK: %d\n", histogramBreak);

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    if (segment->getAvgHeight(inImage) > histogramBreak)
    	segment->segmentType = HEADLINE_TYPE;
  }

  return;
}

void manualClassifySegments(list<RkSegment*> inSegmentList, IplImage* inImage)
{
  int key;
  IplImage* segmentImg;
  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    cvSetImageROI(inImage, segment->boundingRectangle->toRect());
    segmentImg = cvCreateImage(cvGetSize(inImage), inImage->depth, inImage->nChannels);
    cvCopy(inImage, segmentImg, NULL);
    cvNamedWindow("segment", CV_WINDOW_AUTOSIZE);
    cvShowImage("segment", segmentImg);

    key = cvWaitKey(0);
    switch(key)
    {
	case 'h':
	  segment->segmentType = HEADLINE_TYPE;
	  break;
	case 't':
	  segment->segmentType = CONTENT_TYPE;
	  break;
	case 'l':
	  segment->segmentType = LINE_TYPE;
	  break;
	case 'i':
	  segment->segmentType = IMAGE_TYPE;
	  break;
    }

    cvReleaseImage(&segmentImg);
    cvDestroyWindow("segment");
  }

  cvResetImageROI(inImage);

}

int findBreak(map<int, int> inHeights)
{
  int histBreak = 1;
  int prevKey = 0;

  for(map<int, int>::iterator iter = inHeights.begin(); iter != inHeights.end(); iter++)
  {
	  if ((*iter).first > prevKey + 2)
	  {
		  histBreak = (*iter).first;
		  break;
	  }

	  prevKey = (*iter).first;
  }

  return histBreak;
}

list<RkSegment*> getSeparatedSegmentList(string* inFileName)
{
  int* top = new int; int* left = new int;
  int* bottom = new int; int* right = new int;
  int* type = new int;

  list<RkSegment*> segmentList;
  RkBoundingRectangle* tmpRect;

  FILE* segmentFile;
  segmentFile = fopen(inFileName->c_str(), "r");

  while ( ! feof (segmentFile) )
  {
	fscanf(segmentFile, "%d,%d,%d,%d, %d\n", top, left, bottom, right, type);
	tmpRect = new RkBoundingRectangle(*top, *left, *bottom, *right);
	segmentList.push_back(new RkSegment(tmpRect, *type));
  }

  fclose(segmentFile);
  return segmentList;
}

void dumpClassifiedSegmentList(list<RkSegment*> inSegmentList, string* inFileName)
{
  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;

  FILE* segmentFile;
  segmentFile = fopen(inFileName->c_str(), "w");

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	  segment = (*segmentIter);
	  segment->printString(segmentFile);
  }

  fclose(segmentFile);
}
