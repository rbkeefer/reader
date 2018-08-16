/*
 * ReduceExpand.cpp
 *
 */
#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkColumn.h"
#include "RkRow.h"
#include "RkSegment.h"
#include "RkArticle.h"

#include "Utils.h"
#include "ReduceExpand.h"

/* LOCAL METHODS */
IplImage* cleanImageLines(IplImage* inImage, list<RkColumn*> inColumnList, list<RkRow*> inRowList, int inColor,
		  int inMinHeight, int inMinWidth);

void displayLines(IplImage* inImage, int inWidth, int inMultiplier, list<RkColumn*> inColumnList,
		list<RkColumn*> inExpColumnList, list<RkRow*> inRowList, list<RkRow*> inExpRowList, string* inImageFileName);

list<RkColumn*> accelerateColumns(IplImage* inImage, list<RkColumn*> inColumnList, list<RkRow*> inRowList, int inColor, int inMinHeight);
list<RkRow*> accelerateRows(IplImage* inImage, list<RkColumn*> inColumnList, list<RkRow*> inRowList, int inColor, int inMinWidth);

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

list<RkColumn*> columnList;
list<RkRow*> rowList;
list<RkColumn*> expandedRkColumnList;
list<RkRow*> expandedRkRowList;

int MIN_LINE_SIZE = 3;

/****************/


/* METHOD IMPLEMENTATIONS*/
IplImage* reduceImage(IplImage* inImage, int inWidth, int inMinHeight, int inMinWidth, int inDemoMode, string* inImageFileName)
{
  IplImage* tmpImage = cvCloneImage(inImage);
  int origWidth = tmpImage->width;

  while (tmpImage->width > inWidth)
  {
    tmpImage = reduceImage(tmpImage, inMinHeight, inMinWidth, inDemoMode);
  }

  if (inDemoMode)
	displayLines(tmpImage, origWidth, origWidth/inWidth, columnList, expandedRkColumnList, rowList, expandedRkRowList, inImageFileName);

  // Cleanup
  list<RkColumn*>::iterator columnIter;
  for (columnIter=columnList.begin(); columnIter!=columnList.end(); columnIter++)
	free(*columnIter);
  for (columnIter=expandedRkColumnList.begin(); columnIter!=expandedRkColumnList.end(); columnIter++)
	free(*columnIter);

  list<RkRow*>::iterator rowIter;
  for (rowIter=rowList.begin(); rowIter!=rowList.end(); rowIter++)
	free(*rowIter);
  for (rowIter=expandedRkRowList.begin(); rowIter!=expandedRkRowList.end(); rowIter++)
	free(*rowIter);

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

IplImage* reduceImage(IplImage* inImage, int inMinHeight, int inMinWidth, int inDemoMode)
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

      if (isColoredRegion(origColumn, origRow, BOX_SIZE, inImage, BLACK))
        tmpImageData[tmpImageStep*row+column] = BLACK;
      else
        tmpImageData[tmpImageStep*row+column] = WHITE;
    }
  }

  columnList = findColumns(tmpImage, inMinHeight, WHITE);
  rowList = findRows(tmpImage, inMinWidth, WHITE);

  expandedRkColumnList = accelerateColumns(tmpImage, columnList, rowList, WHITE, inMinHeight);
  expandedRkRowList = accelerateRows(tmpImage, columnList, rowList, WHITE, inMinWidth);

  tmpImage = cleanImageLines(tmpImage, expandedRkColumnList, expandedRkRowList, WHITE, inMinHeight, inMinWidth);

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

      if (isColoredRegion(origColumn, origRow, BOX_SIZE, inImage, BLACK))
      {
        tmpImageData[tmpImageStep*row+column] = BLACK;
      }
      else
        tmpImageData[tmpImageStep*row+column] = WHITE;
    }
  }

  return tmpImage;
}

IplImage* cleanImageLines(IplImage* inImage, list<RkColumn*> inColumnList,
                            list<RkRow*> inRowList, int inColor, int inMinHeight, int inMinWidth)
{
  uchar* tmpImageData = (uchar *) inImage->imageData;
  int imageStep = inImage->widthStep;

  list<RkColumn*>::iterator columnIter;
  for (columnIter=inColumnList.begin(); columnIter!=inColumnList.end(); columnIter++)
  {
    if ((*columnIter)->height() > inMinHeight)
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
    if ((*rowIter)->width() > inMinWidth)
    {
      for (int column=(*rowIter)->left; column < (*rowIter)->right; column++)
      {
        tmpImageData[( ((*rowIter)->row) *imageStep ) + column] = inColor;
      }
    }
  }

  return inImage;
}

list<RkColumn*> findColumns(IplImage* inImage, int inMinHeight, int inColor)
{
  int column, row;

  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  list<RkColumn*> RkColumnList;
  RkColumn* rkColumn;

  printf("Finding Columns ...\n");
  for( row=0; row<imageHeight; row++ )
  {
    for(column=0; column<imageWidth; column++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        if (! isInColumn(column, row, RkColumnList))
        {
        	rkColumn = findColumn(column, row, inImage, inColor);
          if (rkColumn->height() > inMinHeight)
            RkColumnList.push_back(rkColumn);
        }
      }
    }
  }

  return RkColumnList;
}

list<RkRow*> findRows(IplImage* inImage, int inMinWidth, int inColor)
{
  int column, row;

  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  list<RkRow*> RkRowList;
  RkRow* rkRow;

  printf("Finding Rows ...\n");
  for( column=0; column<imageWidth; column++ )
  {
    for(row=0; row<imageHeight; row++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        if (! isInRow(column, row, RkRowList))
        {
          rkRow = findRow(column, row, inImage, inColor);
          if (rkRow->width() > inMinWidth)
          RkRowList.push_back(rkRow);
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
                                    list<RkRow*> inRowList, int inColor, int inMinHeight)
{
  int expandSize = 0;
  list<RkColumn*> newList;
  RkColumn* newColumn;
  list<RkColumn*>::iterator iter;
  for (iter=inColumnList.begin(); iter!=inColumnList.end(); iter++)
  {
     if ((*iter)->height() > inMinHeight)
     {
       expandSize = (MIN_LINE_SIZE < sqrt((*iter)->height())) ? sqrt((*iter)->height()) : MIN_LINE_SIZE;
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
                              list<RkRow*> inRowList, int inColor, int inMinWidth)
{
  int expandSize = 0;
  list<RkRow*> newList;
  RkRow* newRow;
  list<RkRow*>::iterator iter;
  for (iter=inRowList.begin(); iter!=inRowList.end(); iter++)
  {
     if ((*iter)->width() > inMinWidth)
     {
       expandSize = (MIN_LINE_SIZE < sqrt((*iter)->width())) ? sqrt((*iter)->width()) : MIN_LINE_SIZE;
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

void displayLines(IplImage* inImage, int inWidth, int inMultiplier, list<RkColumn*> inColumnList,
		list<RkColumn*> inExpColumnList, list<RkRow*> inRowList, list<RkRow*> inExpRowList, string* inImageFileName)
{
  IplImage* expImage = expandImage(inImage, inWidth);
  IplImage* tmpImage = cvCreateImage(cvSize(expImage->width, expImage->height), IPL_DEPTH_8U, 3);
  cvMerge(expImage, expImage, expImage, NULL, tmpImage);

  int width = tmpImage->width;
  int height = tmpImage->height;
  int top, bottom, col;
  CvPoint topPoint;
  CvPoint bottomPoint;

  RkColumn* column;
  list<RkColumn*>::iterator columnIter;
  for (columnIter=inExpColumnList.begin(); columnIter!=inExpColumnList.end(); columnIter++)
  {
    column = (*columnIter);
    bottom = column->bottom * inMultiplier;
    top = column->top * inMultiplier;
    col = column->column * inMultiplier;

    if (bottom >= height) bottom = height-1;
    if (col >= width) col = width-1;

    topPoint.x = col; topPoint.y = top;
    bottomPoint.x = col; bottomPoint.y = bottom;
    cvLine(tmpImage, topPoint, bottomPoint, COLOR_BLUE, THICK_LINE);
  }

  for (columnIter=inColumnList.begin(); columnIter!=inColumnList.end(); columnIter++)
  {
    column = (*columnIter);
    bottom = column->bottom * inMultiplier;
    top = column->top * inMultiplier;
    col = column->column * inMultiplier;

    if (bottom >= height) bottom = height-1;
    if (col >= width) col = width-1;

    topPoint.x = col; topPoint.y = top;
    bottomPoint.x = col; bottomPoint.y = bottom;
    cvLine(tmpImage, topPoint, bottomPoint, COLOR_GREEN, THICK_LINE);
  }

  int left, right, r;
  CvPoint leftPoint;
  CvPoint rightPoint;

  RkRow* row;
  list<RkRow*>::iterator rowIter;
  for (rowIter=inExpRowList.begin(); rowIter!=inExpRowList.end(); rowIter++)
  {
	row = (*rowIter);
	left = row->left * inMultiplier;
	right = row->right * inMultiplier;
	r = row->row * inMultiplier;

    if (right >= width) right = width-1;
    if (r >= height) r = height-1;

    leftPoint.x = left; leftPoint.y = r;
    rightPoint.x = right; rightPoint.y = r;
    cvLine(tmpImage, leftPoint, rightPoint, COLOR_GREEN, THICK_LINE);
  }

  for (rowIter=inRowList.begin(); rowIter!=inRowList.end(); rowIter++)
  {
	row = (*rowIter);
	left = row->left * inMultiplier;
	right = row->right * inMultiplier;
	r = row->row * inMultiplier;

    if (right >= width) right = width-1;
    if (r >= height) r = height-1;

    leftPoint.x = left; leftPoint.y = r;
    rightPoint.x = right; rightPoint.y = r;
    cvLine(tmpImage, leftPoint, rightPoint, COLOR_BLUE, THICK_LINE);
  }

  cvNamedWindow("Accelerated Lines", CV_WINDOW_AUTOSIZE);
  cvShowImage("Accelerated Lines", tmpImage);

  string* regImgFileName = new string(*inImageFileName);
  regImgFileName->append(".regions.jpg");
  cvSaveImage(regImgFileName->c_str(), tmpImage);

  cvWaitKey(0);
  cvReleaseImage(&tmpImage);
  cvDestroyWindow("Accelerated Lines");
}



