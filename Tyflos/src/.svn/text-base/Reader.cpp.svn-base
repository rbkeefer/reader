
#include <iostream>

#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "Regions.h"
#include "RkColumn.h"
#include "RkRow.h"
#include "RkSegment.h"
#include "RkArticle.h"

#include "Utils.h"
#include "CleanImage.h"
#include "ReduceExpand.h"
#include "Segment.h"
#include "Separate.h"
#include "Classify.h"
#include "Frame.h"

// *** TEST CLASSES ***
void testRkColumn();
void testRkRow();
void testRkBoundingRect();
void testRegions();
void testUtils(IplImage* origImg);

// *** Local functions ***
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
void dumpSegmentList(list<RkBoundingRectangle*>, const char* inFileName);

// Local Variables
IplImage* origImg;
IplImage* cleanedImg;

// Default Values
string* imageFileName = new string("/Users/rob/Research/Experiments/Manual/NYTfp2.jpg");
int illumination = 0;
int reduction = 4;
int demoMode = OFF;
int runMode = MANUAL_MODE;

int main(int argc, char** argv) {
  /* MAIN */
  processArguments(argc, argv);
  origImg = loadImage(argc, argv);

  /* RUN TESTS FIRST */
  testRkColumn();
  testRkRow();
  testRkBoundingRect();
  testUtils(origImg);
  testRegions();
// exit(0);

  cleanedImg = cleanImage(origImg, illumination);

  printf("Original Image Dims: [%dx%d]\n", origImg->width, origImg->height);
  printf("Reduction: %d   Reduction Width: %d\n", reduction, origImg->width/reduction);
  printf("Illumination Constant: %d\n\n", illumination);

  doSegmentation(demoMode, runMode, illumination, reduction, imageFileName, origImg, cleanedImg);

  doSeparation(demoMode, runMode, illumination, reduction, imageFileName, origImg, cleanedImg);

  doClassification(demoMode, runMode, illumination, reduction, imageFileName, origImg, cleanedImg);

  doFraming(demoMode, runMode, illumination, reduction, imageFileName, origImg, cleanedImg);

  cvReleaseImage(&origImg);
  cvReleaseImage(&cleanedImg);
  free(imageFileName);
}

void processArguments(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-i") == 0)
    {
      illumination = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-d") == 0)
    {
      demoMode = ON;
    }
    else if (strcmp(argv[i], "-a") == 0)
    {
      runMode = AUTOMATIC_MODE;
    }
    else if (strcmp(argv[i], "-r") == 0)
    {
      reduction = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-h") == 0)
    {
      printf("Usage [-options] filename\n  -i [illuminationCoef]\n  -r [reductionConst]\n  -a (Automatic Mode)\n  -d (for demo mode)\n");
    }
  }
}

IplImage* loadImage(int argc, char** argv)
{
  IplImage* img;

  if (argc > 1)
  {
	free(imageFileName);
    imageFileName = new string(argv[argc-1]);
  }

  img = cvLoadImage(imageFileName->c_str(), IPL_DEPTH_8U);

  return img;
}


