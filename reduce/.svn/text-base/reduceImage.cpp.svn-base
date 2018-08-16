#include "pyramid.h"
#include "ColumnLine.h"
#include "RowLine.h"
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
      origRow = row*BOX_SIZE;
      origColumn = column*BOX_SIZE;

      if (isColoredRegion(origColumn, origRow, inImage, BOX_SIZE, BLACK))
        tmpImageData[tmpImageStep*row+column] = BLACK;
      else
        tmpImageData[tmpImageStep*row+column] = WHITE;
    }
  }

  return tmpImage;
}

IplImage* expandImage(IplImage* inImage)
{
  int column, row;
  int origColumn, origRow;

  IplImage *tmpImage = cvCreateImage(
                         cvSize(inImage->width*BOX_SIZE, inImage->height*BOX_SIZE),
                         IPL_DEPTH_8U, inImage->nChannels);
  uchar* tmpImageData = (uchar *) tmpImage->imageData;
  int tmpImageStep = tmpImage->widthStep;
  int tmpImageWidth = tmpImage->width;
  int tmpImageHeight = tmpImage->height;

  printf("Expanding Image ...\n");

  for(column=0; column<tmpImageWidth; column++)
  {
    for( row=0; row<tmpImageHeight; row++ )
    {
      origRow = row/BOX_SIZE;
      origColumn = column/BOX_SIZE;

      if (isColoredRegion(origColumn, origRow, inImage, 1, BLACK))
      {
        tmpImageData[tmpImageStep*row+column] = BLACK;
      }
      else
        tmpImageData[tmpImageStep*row+column] = WHITE;
    }
  }

  return tmpImage;
}

IplImage* cleanReducedImage(IplImage* inImage, list<ColumnLine*> inColumnList,
                            list<RowLine*> inRowList, int inColor)
{
  uchar* tmpImageData = (uchar *) inImage->imageData;
  int imageStep = inImage->widthStep;

  list<ColumnLine*>::iterator columnIter;
  for (columnIter=inColumnList.begin(); columnIter!=inColumnList.end(); columnIter++)
  {
    if ((*columnIter)->height() > 15)
    {
      for (int row=(*columnIter)->top; row < (*columnIter)->bottom; row++)
      {
        tmpImageData[(row*imageStep) + (*columnIter)->column] = inColor;
      }
    }
  }

  list<RowLine*>::iterator rowIter;
  for (rowIter=inRowList.begin(); rowIter!=inRowList.end(); rowIter++)
  {
    if ((*rowIter)->width() > 15)
    {
      for (int column=(*rowIter)->left; column < (*rowIter)->right; column++)
      {
        tmpImageData[( ((*rowIter)->row) *imageStep ) + column] = inColor;
      }
    }
  }

  return inImage;
}

bool isColoredRegion(int inColumn, int inRow, IplImage* inImage, int inRegionSize, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int inImageStep = inImage->widthStep;
  int columnCounter = 0;
  int rowCounter = 0;
  int pixel;

  if (inRegionSize == 0)
  {
    pixel = inColumn + (inRow * inImageStep);
    if ( inImageData[pixel] == inColor )
      return true;

    return false;
  }

  for( rowCounter=0; rowCounter<inRegionSize; rowCounter++ )
  {
    for( columnCounter=0; columnCounter<inRegionSize; columnCounter++ )
    {
      pixel = (columnCounter + inColumn) + ((rowCounter+inRow) * inImageStep);

      if ( inImageData[pixel] == inColor )
      {
        return true;
      }
    }
  }

  return false;
}

