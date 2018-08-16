
#include <iostream>

#include "Classify.h"
#include "RkBoundingRectangle.h"
#include "RkCharacter.h"
#include "RkTextFrame.h"
#include "RkSegment.h"
#include "RkSize.h"
#include "RkRegions.h"
#include "RkUtils.h"
#include "RkClassifySegments.h"

// *** TEST CLASSES ***
void testRkColumn();
void testRkRow();
void testRkBoundingRect();
void testRkRegions();
void testRkCharacter();
void testRkTextFrame();
void testRkSegment();
void testRkUtils();
void testRkClassifySegments();

// *** Local functions ***
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
IplImage* cleanImage(IplImage* inImage, int inThreshold);
void dumpSegmentList(list<RkSegment*> inSegmentList, const char* inFileName);
void cleanup();
list<RkBoundingRectangle*> getRectangleList(const char* inFileName);
const char* inputFileName();
const char* outputFileName();
list<RkSegment*> getSegmentList(const char* inFileName);


// Constants
int threshold = 128;

// Local variables
int mode = AUTOMATIC_MODE;
string* imageFileName = new string("/Users/rob/Research/Images/test/CloseTest.bmp");
IplImage* origImg;
IplImage* cleanedImg;
IplImage* segmentImg;


int main(int argc, char** argv) {
  /* RUN TESTS FIRST */
  testRkColumn();
  testRkRow();
  testRkBoundingRect();
  testRkCharacter();
  testRkTextFrame();
  testRkUtils();
  testRkRegions();
  testRkSegment();
//   exit(0);

  /* MAIN */
/* */
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);

  list<RkSegment*> segmentList = getSegmentList(inputFileName());
  if (mode == AUTOMATIC_MODE)
    classifySegments(segmentList, cleanedImg);
  else
	manualClassifySegments(segmentList, cleanedImg);

  dumpSegmentList(segmentList, outputFileName());
  segmentImg = cvCreateImage(cvSize(origImg->width, origImg->height), IPL_DEPTH_8U, 3);
  cvMerge(origImg, origImg, origImg, NULL, segmentImg);
  segmentImg = displayBoundaries(segmentImg, segmentList, 1);
  cvNamedWindow("ClassifiedSegments", CV_WINDOW_AUTOSIZE);
  cvShowImage("ClassifiedSegments", segmentImg);

  cvWaitKey(0);
  cleanup();
/* */
}

void processArguments(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-threshold") == 0)
    {
      threshold = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-m") == 0)
    {
    	mode = MANUAL_MODE;
    }
    else if (strcmp(argv[i], "-h") == 0)
    {
      printf("Usage [-options] filename\n  -threshold [val]\n");
    }
  }
}

IplImage* loadImage(int argc, char** argv)
{
  IplImage* img;

  if (argc > 1)
  {
    imageFileName = new string(argv[argc-1]);
  }

  img = cvLoadImage(imageFileName->c_str(), IPL_DEPTH_8U);

  return img;
}

list<RkSegment*> getSegmentList(const char* inFileName)
{
  int* top = new int; int* left = new int;
  int* bottom = new int; int* right = new int;
  int* type = new int;

  list<RkSegment*> segmentList;
  RkBoundingRectangle* tmpRect;

  FILE* segmentFile;
  segmentFile = fopen(inFileName, "r");

  while ( ! feof (segmentFile) )
  {
	fscanf(segmentFile, "%d,%d,%d,%d, %d\n", top, left, bottom, right, type);
	tmpRect = new RkBoundingRectangle(*top, *left, *bottom, *right);
	segmentList.push_back(new RkSegment(tmpRect, *type));
  }

  fclose(segmentFile);
  return segmentList;
}

void dumpSegmentList(list<RkSegment*> inSegmentList, const char* inFileName)
{
  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;

  FILE* segmentFile;
  segmentFile = fopen(inFileName, "w");

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	  segment = (*segmentIter);
	  segment->printString(segmentFile);
  }

  fclose(segmentFile);
}

void cleanup()
{
  cvReleaseImage(&origImg);
  cvReleaseImage(&cleanedImg);
  cvReleaseImage(&segmentImg);

  cvDestroyWindow("ClassifiedSegments");
}

const char* inputFileName()
{
  string* out = new string(*imageFileName);
  out->append(".Separated.txt");
  return out->c_str();
}

const char* outputFileName()
{
  string* out = new string(*imageFileName);
  out->append(".Classified.txt");
  return out->c_str();
}
