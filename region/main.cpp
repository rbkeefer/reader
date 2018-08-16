#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "mergeRectList.h"
#include "ColumnLine.h"
#include "RowLine.h"
#include "cleanImage.h"
#include "reduceImage.h"
#include "regionImage.h"

// Local functions
IplImage* displayBoundaries(IplImage* inImage, list<BoundingRectangle*> inRectangleList, CvScalar inColor, int inSize);
void processArguments(int argc, char** argv);
IplImage* loadImage(int argc, char** argv);
void expandBoundingRectList(list<BoundingRectangle*> inRectangleList);
void cleanup();

// Constants
static char* DEFAULT_IMAGE_NAME = "/Users/rob/Research/Images/NewsPaper/NYpy128magClean.bmp";

// Local variables
IplImage* origImg;
IplImage* cleanedImg;
IplImage* reducedImg;
IplImage* expandedImg;
IplImage* redExpImg;
IplImage* regionImg;

int threshold = 128;
int tolerance = 0;
int timesReduced;

int main(int argc, char** argv)
{
  processArguments(argc, argv);

  origImg = loadImage(argc, argv);
  cleanedImg = cleanImage(origImg, threshold);

  reducedImg = reduceImage(cleanedImg, 128);
  expandedImg = expandImage(reducedImg, cleanedImg->width);
  timesReduced = cleanedImg->width / 128;

  list<BoundingRectangle*> foundBoundingRectList = regionizeImage(reducedImg, BLACK);
  expandBoundingRectList(foundBoundingRectList);

  regionImg = cvCreateImage(cvSize(cleanedImg->width, cleanedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(cleanedImg, cleanedImg, cleanedImg, NULL, regionImg);
  regionImg = displayBoundaries(regionImg, foundBoundingRectList, cvScalar(0, 0, 255), 1);
 
  redExpImg = cvCreateImage(cvSize(expandedImg->width, expandedImg->height), IPL_DEPTH_8U, 3);
  cvMerge(expandedImg, expandedImg, expandedImg, NULL, redExpImg);
  redExpImg = displayBoundaries(redExpImg, foundBoundingRectList, cvScalar(0, 0, 255), 1);
 
  cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
  cvShowImage("Original", origImg);

  cvNamedWindow("ReducedExpanded Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("ReducedExpanded Regions", redExpImg);

  cvNamedWindow("Found Regions", CV_WINDOW_AUTOSIZE);
  cvShowImage("Found Regions", regionImg);
  cvMoveWindow("Found Regions", 525, 1);

  cvWaitKey(0);

  cleanup();
}

void expandBoundingRectList(list<BoundingRectangle*> inRectangleList)
{
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    rectangle->top = rectangle->top * timesReduced;
    rectangle->bottom = (rectangle->bottom * timesReduced);
    rectangle->left = rectangle->left * timesReduced;
    rectangle->right = (rectangle->right * timesReduced);
  }
}

IplImage* displayBoundaries(IplImage* inImage, list<BoundingRectangle*> inRectangleList, CvScalar inColor, int inSize)
{
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    cvRectangle(inImage, rectangle->topLeft(), rectangle->bottomRight(), inColor, inSize);
  }

  return inImage;
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
  cvReleaseImage(&redExpImg);
  cvReleaseImage(&regionImg);

  cvDestroyWindow("Original");
  cvDestroyWindow("ReducedExpanded Regions");
  cvDestroyWindow("Found Regions");
}

void processArguments(int argc, char** argv)
{
  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-threshold") == 0)
    {
      threshold = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-tolerance") == 0)
    {
      tolerance = atoi(argv[i+1]);
    }
    else if (strcmp(argv[i], "-h") == 0)
    {
      printf("Usage [-options] filename\n  -threshold [val] -tolerance [val]\n");
    }
  }
}


