#include "pyramid.h"
#include "cleanImage.h"
#include "reduceImage.h"
#include "regionImage.h"
#include "utils.h"
#include "mapImage.h"
#include "frameImage.h"
#include "growRects.h"
#include "combineRects.h"
#include "combineTouchingRects.h"
#include "eliminateOverlappingRects.h"

// Local functions
IplImage* displayBoundaries(IplImage* inImage, list<BoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize, IplImage* outImage);
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
void cleanup();
list<BoundingRectangle*> getWhiteRectList();

// Constants
static char* DEFAULT_IMAGE_NAME = "/Users/rob/Research/Images/NewsPaper/NYpy128magClean.bmp";
static int REDUCTION_WIDTH = 128;

// Local variables
IplImage* origImg;
IplImage* cleanedImg;
IplImage* reducedImg;
IplImage* regionImg;
IplImage* mappedImg;

int main(int argc, char** argv)
{
  list<BoundingRectangle*>::iterator iter;
  int timesReduced = 0;
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);
  reducedImg =  cvCloneImage(cleanedImg);

  /*** Reduce ***/
  while (reducedImg->width > REDUCTION_WIDTH)
  {
    reducedImg = reduceImage(reducedImg);
    timesReduced++;
  }



  /*** Find Regions ***/
  list<BoundingRectangle*> blackRectList = regionizeImage(reducedImg, BLACK);
  // list<BoundingRectangle*> whiteRectList = regionizeImage(reducedImg, WHITE);

  blackRectList = cleanupList(blackRectList, REDUCTION_WIDTH/32, REDUCTION_WIDTH);
  // whiteRectList = cleanupList(whiteRectList, REDUCTION_WIDTH/16, REDUCTION_WIDTH/2);

  blackRectList = growRectangles(reducedImg, blackRectList, 1, BLACK);

  // blackRectList = cleanupList(blackRectList, 13);

  regionImg = cvCreateImage(cvSize(reducedImg->width, reducedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(reducedImg, reducedImg, reducedImg, NULL, regionImg);
  regionImg = displayBoundaries(reducedImg, blackRectList, cvScalar(0, 255, 0), 1, regionImg);

  
  

  /*** Frame regions ***/
  // whiteRectList = frameImage(whiteRectList, blackRectList);
  // blackRectList = frameImage(blackRectList, whiteRectList);




  /*** Map back to original ***/
  for (int reductionCounter = 0; reductionCounter < timesReduced; reductionCounter++)
  {
    blackRectList = mapImage(blackRectList);
    // whiteRectList = mapImage(whiteRectList);
  }

  // blackRectList = combineTouchingRectangles(blackRectList, 1);

  mappedImg = cvCreateImage(cvSize(cleanedImg->width, cleanedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(cleanedImg, cleanedImg, cleanedImg, NULL, mappedImg);
  // mappedImg = displayBoundaries(cleanedImg, whiteRectList, cvScalar(0, 255, 0), 1, mappedImg);
  mappedImg = displayBoundaries(cleanedImg, blackRectList, cvScalar(0, 0, 255), 1, mappedImg);




  cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
  cvShowImage("Original", origImg);

  cvNamedWindow("First Reduced", CV_WINDOW_AUTOSIZE);
  cvShowImage("First Reduced", reducedImg);

  cvNamedWindow("Found Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Found Regions", regionImg);

  cvNamedWindow("Mapped Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Mapped Regions", mappedImg);

  cvWaitKey(0);

  cleanup();
}


IplImage* displayBoundaries(IplImage* inImage, list<BoundingRectangle*> inRectangleList,
                            CvScalar inColor, int inSize, IplImage* outImage)
{
  list<BoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
     cvRectangle(outImage, (*iter)->topLeft(), (*iter)->bottomRight(), inColor, inSize);
  }

  return outImage;
}

IplImage* loadImage(int argc, char** argv)
{
  IplImage* img;
  printf("Loading image ...\n");

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
  cvReleaseImage(&mappedImg);

  cvDestroyWindow("Original");
  cvDestroyWindow("First Reduced");
  cvDestroyWindow("Found Regions");
  cvDestroyWindow("Mapped Regions");
}

void processArguments(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-threshold") == 0)
    {
      threshold = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-accuracy") == 0)
    {
      accuracy = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-tolerance") == 0)
    {
      tolerance = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-h") == 0)
    {
      printf("Usage [-options] filename\n  -threshold [val] -tolerance [val] -accuracy [val]\n");
    }
  }
}



