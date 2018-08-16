#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "ColumnLine.h"
#include "RowLine.h"
#include "findParts.h"
#include "reduceImage.h"

IplImage* reduceImage(IplImage* inImage, int inWidth)
{
  IplImage* tmpImage = cvCloneImage(inImage);

  while (tmpImage->width > inWidth)
  {
    tmpImage = reduceImage(tmpImage);
  }

  list<ColumnLine*> columnLineList = findColumns(tmpImage, WHITE);
  list<RowLine*> rowLineList = findRows(tmpImage, WHITE);

  list<ColumnLine*> expandedColumnLineList = accelerateColumns(tmpImage, columnLineList, rowLineList, WHITE);
  list<RowLine*> expandedRowLineList = accelerateRows(tmpImage, columnLineList, rowLineList, WHITE);

  tmpImage = cleanReducedImage(tmpImage, expandedColumnLineList, expandedRowLineList, WHITE);

  return tmpImage;
}

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

IplImage* expandImage(IplImage* inImage, int inWidth)
{
  IplImage* tmpImage = cvCloneImage(inImage);

  while (tmpImage->width < inWidth)
  {
    tmpImage = expandImage(tmpImage);
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
    if ((*columnIter)->height() > MIN_HEIGHT)
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
    if ((*rowIter)->width() > MIN_WIDTH)
    {
      for (int column=(*rowIter)->left; column < (*rowIter)->right; column++)
      {
        tmpImageData[( ((*rowIter)->row) *imageStep ) + column] = inColor;
      }
    }
  }

  return inImage;
}

