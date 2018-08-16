#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkArticle.h"

#include "Utils.h"
#include "Separate.h"

void doSeparation(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage)
{
  printf("\nBegin Separation\n");

  IplImage* segmentImg;
  IplImage* separatedImg;

  string* inFileName = new string(*inImageFileName);
  inFileName->append(".Segmented.txt");
  string* outFileName = new string(*inImageFileName);
  outFileName->append(".Separated.txt");

  list<RkSegment*> segmentList = getSegmentList(inFileName);

  segmentImg = cvCreateImage(cvSize(inOrigImage->width, inOrigImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inOrigImage, inOrigImage, inOrigImage, NULL, segmentImg);
  segmentImg = displayBoundaries(segmentImg, segmentList, THIN_LINE);
  cvNamedWindow("Segments", CV_WINDOW_AUTOSIZE);
  cvShowImage("Segments", segmentImg);

  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=segmentList.begin(); segmentIter!=segmentList.end(); segmentIter++)
  {
	(*segmentIter)->determineType(inCleanedImage, inRunMode);
  }

  dumpSeparatedSegmentList(segmentList, outFileName);

  separatedImg = cvCreateImage(cvSize(inOrigImage->width, inOrigImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inOrigImage, inOrigImage, inOrigImage, NULL, separatedImg);
  separatedImg = displayBoundaries(separatedImg, segmentList, THICK_LINE);
  cvNamedWindow("SeparatedSegments", CV_WINDOW_AUTOSIZE);
  cvShowImage("SeparatedSegments", separatedImg);

  string* saveImgFileName = new string(*inImageFileName);
  saveImgFileName->append(".separated.jpg");
  cvSaveImage(saveImgFileName->c_str(), separatedImg);

  cvWaitKey(0);

  cvReleaseImage(&segmentImg);
  cvDestroyWindow("Segments");

  cvReleaseImage(&separatedImg);
  cvDestroyWindow("SeparatedSegments");

  for (segmentIter=segmentList.begin(); segmentIter!=segmentList.end(); segmentIter++)
	free(*segmentIter);

  free(inFileName);
  free(outFileName);
}

list<RkSegment*> getSegmentList(string* inFileName)
{
  int* top = new int; int* left = new int;
  int* bottom = new int; int* right = new int;
  list<RkSegment*> segmentList;
  RkBoundingRectangle* tmpRect;

  FILE* segmentFile;
  segmentFile = fopen(inFileName->c_str(), "r");

  while ( ! feof (segmentFile) )
  {
	fscanf(segmentFile, "%d,%d,%d,%d\n", top, left, bottom, right);
	tmpRect = new RkBoundingRectangle(*top, *left, *bottom, *right);
	segmentList.push_back(new RkSegment(tmpRect, 0));
  }

  fclose(segmentFile);
  return segmentList;
}

void dumpSeparatedSegmentList(list<RkSegment*> inSegmentList, string* inFileName)
{
  FILE* segmentFile;
  segmentFile = fopen(inFileName->c_str(), "w");

  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	(*segmentIter)->printString(segmentFile);
  }

  fclose(segmentFile);
}
