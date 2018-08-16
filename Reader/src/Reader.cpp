
#include <iostream>

#include "Reader.h"
#include "RkBoundingRectangle.h"
#include "RkCharacter.h"
#include "RkTextFrame.h"
#include "RkArticle.h"
#include "RkUtils.h"
#include "RkSize.h"
#include "RkRegions.h"
#include "RkFrames.h"

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
void cleanup();

// Constants
char* DEFAULT_IMAGE_NAME = "/Users/rob/Research/Images/test/FarTest.bmp";
int REDUCTION_WIDTH = 128;

// Local variables
IplImage* origImg;
IplImage* cleanedImg;
IplImage* reducedImg;
IplImage* regionImg;

int threshold = 128;

int main(int argc, char** argv) {
  /* RUN TESTS FIRST */
//  testRkColumn();
//  testRkRow();
//  testRkBoundingRect();
//  testRkCharacter();
//  testRkTextFrame();
//  testRkArticle();
//  testRkUtils();
//  testRkRegions();
  testRkFrames();

  /* MAIN */
/* */
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);
  reducedImg =  reduceImage(cleanedImg, REDUCTION_WIDTH);

  list<RkBoundingRectangle*> regionList = regionizeImage(reducedImg, BLACK);
  expandBoundingRectList(regionList, (cleanedImg->width/REDUCTION_WIDTH)/2);

  list<RkArticle*> articleList = getArticleList(regionList, cleanedImg);

  regionImg = cvCreateImage(cvSize(cleanedImg->width, cleanedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(cleanedImg, cleanedImg, cleanedImg, NULL, regionImg);
  regionImg = displayBoundaries(regionImg, articleList, cvScalar(0, 0, 255), 1);
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
    img = cvLoadImage(argv[argc-1], IPL_DEPTH_8U);
  else
    img = cvLoadImage(DEFAULT_IMAGE_NAME, IPL_DEPTH_8U);

  return img;
}

void cleanup()
{
  cvReleaseImage(&origImg);
  cvReleaseImage(&cleanedImg);
  cvReleaseImage(&reducedImg);
  cvReleaseImage(&regionImg);

  cvDestroyWindow("Regions");
}

