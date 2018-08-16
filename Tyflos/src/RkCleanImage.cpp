/*
 * RkCleanImage.cpp
 *
 */

#include "Reader.h"
#include "RkBoundingRectangle.h"
#include "RkUtils.h"

IplImage* cleanImage(IplImage* inImage, int inIllumination)
{
  IplImage* outImage = cvCloneImage(inImage);
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

	  if (tmpImageData[pixel] > avgPixels - inIllumination)
	  {
		  tmpImageData[pixel] = WHITE;
	  }
	  else
	  {
		  tmpImageData[pixel] = BLACK;
	  }
	}
  }

  for(column=0; column<imgWidth; column++)
  {
	for( row=0; row<imgHeight; row++ )
	{
	  pixel = column + (row * imgStep);
      if ( tmpImageData[pixel] == BLACK )
      {
        if (! isColoredRegion(column, row, BOX_SIZE, outImage, BLACK))
        {
          tmpImageData[pixel] = WHITE;
        }
      }
	}
  }

  return outImage;
}

