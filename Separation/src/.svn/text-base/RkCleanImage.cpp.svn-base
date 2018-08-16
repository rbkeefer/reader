/*
 * RkCleanImage.cpp
 *
 */

#include "Separate.h"
#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkTextFrame.h"
#include "RkUtils.h"

IplImage* cleanImage(IplImage* inImage, int inThreshold)
{
  IplImage* outImage = cvCloneImage(inImage);
  //  cvThreshold(inImage, outImage, inThreshold, 255, CV_THRESH_BINARY);

  long pixelValue = 0;
  int avgPixels = 0;

  int column, row, pixel;
  uchar* tmpImageData = (uchar*) outImage->imageData;
  int imgStep = outImage->widthStep;
  int imgWidth = outImage->width;
  int imgHeight = outImage->height;

  for(column=0; column<imgWidth; column++)
  {
	for( row=0; row<imgHeight; row++ )
	{
	  pixel = column + (row * imgStep);
	  pixelValue += tmpImageData[pixel];
	}
  }

  avgPixels = pixelValue/(imgWidth*imgHeight);

  printf("\nAVERAGE PIXEL VALUE: %d\n", avgPixels);

  for(column=0; column<imgWidth; column++)
  {
	for( row=0; row<imgHeight; row++ )
	{
	  pixel = column + (row * imgStep);

	  if (tmpImageData[pixel] > avgPixels - 7)
	  {
		  tmpImageData[pixel] = WHITE;
	  }
	  else
	  {
		  tmpImageData[pixel] = BLACK;
	  }
	}
  }

  return outImage;
}
