/*
 * RkSize.cpp
 *
 */
#include "Frame.h"
#include "RkBoundingRectangle.h"
#include "RkColumn.h"
#include "RkRow.h"
#include "RkArticle.h"
#include "RkUtils.h"
#include "RkSize.h"

/* LOCAL METHODS */

IplImage* cleanReducedImage(IplImage* inImage, list<RkColumn*> inColumnList, list<RkRow*> inRowList, int inColor);

list<RkColumn*> findColumns(IplImage* inImage, int inColor);
list<RkRow*> findRows(IplImage* inImage, int inColor);

list<RkColumn*> accelerateColumns(IplImage* inImage, list<RkColumn*> inColumnList, list<RkRow*> inRowList, int inColor);
list<RkRow*> accelerateRows(IplImage* inImage, list<RkColumn*> inColumnList, list<RkRow*> inRowList, int inColor);

bool isInColumn(int column, int row, list<RkColumn*> RkColumnList);
bool isInRow(int column, int row, list<RkRow*> RkRowList);

RkColumn* findColumn(int inColumn, int inRow, IplImage* inImage, int inColor);
RkRow* findRow(int inColumn, int inRow, IplImage* inImage, int inColor);

int lookUp(IplImage* inImage, int inColumn, int inRow, int inDistance,
           list<RkRow*> inRowList, int inColor);
int lookDown(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<RkRow*> inRowList, int inColor);
int lookLeft(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<RkColumn*> inColumnList, int inColor);
int lookRight(IplImage* inImage, int inColumn, int inRow, int inDistance,
              list<RkColumn*> inColumnList, int inColor);


int MIN_SIZE = 3;

/****************/


/* METHOD IMPLEMENTATIONS*/
IplImage* reduceImage(IplImage* inImage, int inWidth)
{
  IplImage* tmpImage = cvCloneImage(inImage);

  while (tmpImage->width > inWidth)
  {
    tmpImage = reduceImage(tmpImage);
  }

  list<RkColumn*> RkColumnList = findColumns(tmpImage, WHITE);
  list<RkRow*> RkRowList = findRows(tmpImage, WHITE);

  list<RkColumn*> expandedRkColumnList = accelerateColumns(tmpImage, RkColumnList, RkRowList, WHITE);
  list<RkRow*> expandedRkRowList = accelerateRows(tmpImage, RkColumnList, RkRowList, WHITE);

  tmpImage = cleanReducedImage(tmpImage, expandedRkColumnList, expandedRkRowList, WHITE);

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

IplImage* cleanReducedImage(IplImage* inImage, list<RkColumn*> inColumnList,
                            list<RkRow*> inRowList, int inColor)
{
  uchar* tmpImageData = (uchar *) inImage->imageData;
  int imageStep = inImage->widthStep;

  list<RkColumn*>::iterator columnIter;
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

  list<RkRow*>::iterator rowIter;
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

list<RkColumn*> findColumns(IplImage* inImage, int inColor)
{
  int column, row;

  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  list<RkColumn*> RkColumnList;
  RkColumn* RkColumn;

  printf("Finding Columns ...\n");
  for( row=0; row<imageHeight; row++ )
  {
    for(column=0; column<imageWidth; column++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        if (! isInColumn(column, row, RkColumnList))
        {
          RkColumn = findColumn(column, row, inImage, inColor);
          if (RkColumn->height() > MIN_HEIGHT)
            RkColumnList.push_back(RkColumn);
        }
      }
    }
  }

  return RkColumnList;
}

list<RkRow*> findRows(IplImage* inImage, int inColor)
{
  int column, row;

  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  list<RkRow*> RkRowList;
  RkRow* RkRow;

  printf("Finding Rows ...\n");
  for( column=0; column<imageWidth; column++ )
  {
    for(row=0; row<imageHeight; row++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        if (! isInRow(column, row, RkRowList))
        {
          RkRow = findRow(column, row, inImage, inColor);
          if (RkRow->width() > MIN_WIDTH)
          RkRowList.push_back(RkRow);
        }
      }
    }
  }

  return RkRowList;
}

bool isInColumn(int column, int row, list<RkColumn*> RkColumnList)
{
  RkColumn* line;
  list<RkColumn*>::iterator iter;
  for (iter=RkColumnList.begin(); iter!=RkColumnList.end(); iter++)
  {
    line = (*iter);
    if (line->column == column)
    {
      if ((line->top <= row) && (line->bottom >= row))
        return true;
    }
  }

  return false;
}

bool isInRow(int column, int row, list<RkRow*> RkRowList)
{
  RkRow* line;
  list<RkRow*>::iterator iter;
  for (iter=RkRowList.begin(); iter!=RkRowList.end(); iter++)
  {
    line = (*iter);
    if (line->row == row)
    {
      if ((line->left <= column) && (line->right >= column))
        return true;
    }
  }

  return false;
}

RkColumn* findColumn(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;
  int row = inRow;

  while ((row < imageHeight) && (inImageData[(row*imageStep)+inColumn] == inColor))
    row++;


  return new RkColumn(inColumn, inRow, row);
}

RkRow* findRow(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageStep = inImage->widthStep;
  int column = inColumn;

  while ((column < imageWidth) && (inImageData[(inRow*imageStep)+column] == inColor))
    column++;

  return new RkRow(inRow, inColumn, column);
}

list<RkColumn*> accelerateColumns(IplImage* inImage, list<RkColumn*> inColumnList,
                                    list<RkRow*> inRowList, int inColor)
{
  int expandSize = 0;
  list<RkColumn*> newList;
  RkColumn* newColumn;
  list<RkColumn*>::iterator iter;
  for (iter=inColumnList.begin(); iter!=inColumnList.end(); iter++)
  {
     if ((*iter)->height() > MIN_HEIGHT)
     {
       expandSize = (MIN_SIZE < sqrt((*iter)->height())) ? sqrt((*iter)->height()) : MIN_SIZE;
       newColumn = new RkColumn();
       newColumn->column = (*iter)->column;
       newColumn->bottom = lookDown(inImage, (*iter)->column, (*iter)->bottom,
                                    expandSize, inRowList, inColor);
       newColumn->top = lookUp(inImage, (*iter)->column, (*iter)->top,
                                    expandSize, inRowList, inColor);

       newList.push_back(newColumn);
     }
  }

  return newList;
}

list<RkRow*> accelerateRows(IplImage* inImage, list<RkColumn*> inColumnList,
                              list<RkRow*> inRowList, int inColor)
{
  int expandSize = 0;
  list<RkRow*> newList;
  RkRow* newRow;
  list<RkRow*>::iterator iter;
  for (iter=inRowList.begin(); iter!=inRowList.end(); iter++)
  {
     if ((*iter)->width() > MIN_WIDTH)
     {
    expandSize = (MIN_SIZE < sqrt((*iter)->width())) ? sqrt((*iter)->width()) : MIN_SIZE;
       newRow = new RkRow();
       newRow->row = (*iter)->row;
       newRow->right = lookRight(inImage, (*iter)->right, (*iter)->row,
                                    expandSize, inColumnList, inColor);
       newRow->left = lookLeft(inImage, (*iter)->left, (*iter)->row,
                                    expandSize, inColumnList, inColor);

       newList.push_back(newRow);
     }
  }

  return newList;
}

int lookDown(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<RkRow*> inRowList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  int column;
  int row = ((inRow - inDistance) > 0) ? (inRow - inDistance) : 0;
  int bottom = row;

  while ((row < inRow+inDistance) && (row <= imageHeight))
  {
    if (isInRow(inColumn, row, inRowList))
    {
      if (row == imageHeight) break;

      if (isInRow(inColumn, row+1, inRowList))
        break;

      if (! inImageData[((row+1)*imageStep)+inColumn] == inColor)
        break;
    }

    for (column = inColumn-1; column <= inColumn+1; column++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        bottom = row;
      }
    }
    row++;
  }

  if (bottom > imageHeight-3) bottom = imageHeight;

  return bottom;
}

int lookUp(IplImage* inImage, int inColumn, int inRow, int inDistance,
           list<RkRow*> inRowList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  int row = ((inRow + inDistance) < imageHeight) ? (inRow + inDistance) : imageHeight;
  int top = row;
  int column;

  while ((row > inRow-inDistance) && (row >= 0))
  {
    if (isInRow(inColumn, row, inRowList))
    {
      if (row == 0) break;

      if (isInRow(inColumn, row-1, inRowList))
        break;

      if (! inImageData[((row-1)*imageStep)+inColumn] == inColor)
        break;
    }

    for (column = inColumn-1; column <= inColumn+1; column++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        top = row;
      }
    }
    row--;
  }

  if (top < 3) top = 0;

  return top;
}

int lookRight(IplImage* inImage, int inColumn, int inRow, int inDistance,
              list<RkColumn*> inColumnList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageStep = inImage->widthStep;

  int row;
  int column = ((inColumn - inDistance) > 0) ? (inColumn - inDistance) : 0;
  int right = column;

  while ((column < inColumn+inDistance) && (column <= imageWidth))
  {
    if (isInColumn(column, inRow, inColumnList))
    {
      if (column == imageWidth) break;

      if (isInColumn(column+1, inRow, inColumnList))
        break;

      if (! inImageData[(inRow*imageStep)+(column+1)] == inColor)
        break;
    }

    for (row = inRow-1; row <= inRow+1; row++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        right = column;
      }
    }
    column++;
  }

  if (right > imageWidth-3) right = imageWidth;

  return right;
}

int lookLeft(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<RkColumn*> inColumnList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageStep = inImage->widthStep;

  int row;
  int column = ((inColumn + inDistance) < imageWidth) ? (inColumn + inDistance) : imageWidth;
  int left = column;

  while ((column > inColumn-inDistance) && (column >= 0))
  {
    if (isInColumn(column, inRow, inColumnList))
    {
      if (column == 0) break;

      if (isInColumn(column-1, inRow, inColumnList))
        break;

      if (! inImageData[(inRow*imageStep)+(column-1)] == inColor)
        break;
    }

    for (row = inRow-1; row <= inRow+1; row++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        left = column;
      }
    }
    column--;
  }

  if (left < 3) left = 0;

  return left;
}



