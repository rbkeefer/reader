#include "pyramid.h"
#include "cleanImage.h"

IplImage* cleanImage(IplImage* inImage, int inThreshold)
{
  IplImage* outImg;
  printf("Cleaning Image ...\n");

  outImg = cvCloneImage(inImage);

  cvThreshold(inImage, outImg, inThreshold, 255, CV_THRESH_BINARY);

  return outImg;
}

