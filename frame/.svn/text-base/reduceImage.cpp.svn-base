#include "pyramid.h"
#include "utils.h"
#include "reduceImage.h"

IplImage* reduceImage(IplImage* inImage)
{
  int column, row;
  int origColumn, origRow;

  IplImage *tmpImage = cvCreateImage(
                         cvSize(inImage->width/BOX_SIZE, inImage->height/BOX_SIZE),
                         IPL_DEPTH_8U, inImage->nChannels);
  uchar* tmpImageData = (uchar *) tmpImage->imageData;
  int tmpImageStep = tmpImage->widthStep;
  int tmpImageWidth = tmpImage->width;
  int tmpImageHeight = tmpImage->height;

  printf("Reducing Image ...\n");

  for(column=0; column<tmpImageWidth; column++)
  {
    for( row=0; row<tmpImageHeight; row++ )
    {
      origRow = BOX_SIZE*row;
      origColumn = BOX_SIZE*column;

      if (isColoredRegion(origColumn, origRow, inImage, BOX_SIZE, BLACK))
        tmpImageData[tmpImageStep*row+column] = BLACK;
      else
        tmpImageData[tmpImageStep*row+column] = WHITE;
    }
  }

  return tmpImage;
}

