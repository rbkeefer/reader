
#include <iostream>

#include "Reader.h"
#include "RkBoundingRectangle.h"
#include "RkUtils.h"
#include "RkRegions.h"
#include "RkColumn.h"
#include "RkSize.h"

IplImage* cleanImage(IplImage* inImage, int inThreshold);

// *** TEST CLASSES ***
void testRkColumn();
void testRkRow();
void testRkBoundingRect();
void testRkRegions();
void testRkFrames();
void testRkUtils();
void testRkCharacter();
void testRkTextFrame();
void testRkArticle();

// *** Local functions ***
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
void dumpRectangleList(list<RkBoundingRectangle*>, const char* inFileName);
const char* outFileName();
void cleanup();

// Constants
int REDUCTION_WIDTH = 128;

// Local variables
string* imageFileName = new string("/Users/rob/Research/Images/test/CloseTest.bmp");
IplImage* origImg;
IplImage* cleanedImg;
IplImage* reducedImg;
IplImage* regionImg;

int threshold = 128;

int main(int argc, char** argv) {
  /* RUN TESTS FIRST */
  testRkColumn();
  testRkRow();
  testRkBoundingRect();
  testRkUtils();
  testRkRegions();

  /* MAIN */
  /* */
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);
  reducedImg =  reduceImage(cleanedImg, REDUCTION_WIDTH);

  list<RkBoundingRectangle*> regionList = regionizeImage(reducedImg, BLACK);
  expandBoundingRectList(regionList, (cleanedImg->width/REDUCTION_WIDTH)/2);

  dumpRectangleList(regionList, outFileName());

  regionImg = cvCreateImage(cvSize(cleanedImg->width, cleanedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(origImg, origImg, origImg, NULL, regionImg);
  regionImg = displayBoundaries(regionImg, regionList, cvScalar(0, 0, 255), 1);
  cvNamedWindow("Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Regions", regionImg);

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

void dumpRectangleList(list<RkBoundingRectangle*> inRectangleList, const char* inFileName)
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

void cleanup()
{
  cvReleaseImage(&origImg);
  cvReleaseImage(&cleanedImg);
  cvReleaseImage(&reducedImg);
  cvReleaseImage(&regionImg);

  cvDestroyWindow("Regions");
}

const char* outFileName()
{
  string* out = imageFileName;
  out->append(".txt");
  return out->c_str();
}

