#include "pyramid.h"
#include "cleanImage.h"

bool isSurrounding(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor);

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
        if (! isSurrounding(column, row, outImg, 1, BLACK))
        {
          tmpImageData[pixel] = WHITE;
        }
      }
    }
  }

  return outImg;
}

bool isSurrounding(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor)
{
  uchar* tmpImageData = (uchar*) inImage->imageData;
  int inImageStep = inImage->widthStep;
  int columnCounter = 0;
  int rowCounter = 0;
  int pixel;

  for( rowCounter=0; rowCounter<inRegionSize; rowCounter++ )
  {
    for( columnCounter=0; columnCounter<inRegionSize; columnCounter++ )
    {
      pixel = (columnCounter + inColumn) + ((rowCounter+inRow) * inImageStep);

      if ( tmpImageData[pixel] == inColor )
      {
        return true;
      }
    }
  }

  return false;

}
