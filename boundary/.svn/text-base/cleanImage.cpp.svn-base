#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "cleanImage.h"

IplImage* cleanImage(IplImage* inImage, int inThreshold)
{
  IplImage* outImg = cvCloneImage(inImage);
  cvThreshold(inImage, outImg, inThreshold, 255, CV_THRESH_BINARY);

  int column, row, pixel;
  uchar* tmpImageData = (uchar*) outImg->imageData;
  int imgStep = outImg->widthStep;
  int imgWidth = outImg->width;
  int imgHeight = outImg->height;

  for(column=0; column<imgWidth; column++)
  {
    for( row=0; row<imgHeight; row++ )
    {
      pixel = column + (row * imgStep);

      if ( tmpImageData[pixel] == BLACK )
      {
        if (! isColoredRegion(column, row, outImg, 1, BLACK))
        {
          tmpImageData[pixel] = WHITE;
        }
      }
    }
  }

  return outImg;
}

