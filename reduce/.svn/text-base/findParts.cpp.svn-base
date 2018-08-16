#include "pyramid.h"
#include "ColumnLine.h"
#include "RowLine.h"
#include "findParts.h"

bool isInColumn(int column, int row, list<ColumnLine*> columnLineList);
bool isInRow(int column, int row, list<RowLine*> rowLineList);

ColumnLine* findColumn(int inColumn, int inRow, IplImage* inImage, int inColor);
RowLine* findRow(int inColumn, int inRow, IplImage* inImage, int inColor);

int lookUp(IplImage* inImage, int inColumn, int inRow, int inDistance,
           list<RowLine*> inRowList, int inColor);
int lookDown(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<RowLine*> inRowList, int inColor);
int lookLeft(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<ColumnLine*> inColumnList, int inColor);
int lookRight(IplImage* inImage, int inColumn, int inRow, int inDistance,
              list<ColumnLine*> inColumnList, int inColor);

list<ColumnLine*> findColumns(IplImage* inImage, int inColor)
{
  int column, row;

  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  list<ColumnLine*> columnLineList;
  ColumnLine* columnLine;

  printf("Finding Columns ...\n");
  for( row=0; row<imageHeight; row++ )
  {
    for(column=0; column<imageWidth; column++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        if (! isInColumn(column, row, columnLineList))
        {
          columnLine = findColumn(column, row, inImage, inColor);
          if (columnLine->height() > MIN_HEIGHT)
            columnLineList.push_back(columnLine);
        }
      }
    }
  }

  return columnLineList;
}

list<RowLine*> findRows(IplImage* inImage, int inColor)
{
  int column, row;

  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  list<RowLine*> rowLineList;
  RowLine* rowLine;

  printf("Finding Rows ...\n");
  for( column=0; column<imageWidth; column++ )
  {
    for(row=0; row<imageHeight; row++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        if (! isInRow(column, row, rowLineList))
        {
          rowLine = findRow(column, row, inImage, inColor);
          if (rowLine->width() > MIN_WIDTH)
          rowLineList.push_back(rowLine);
        }
      }
    }
  }

  return rowLineList;
}

bool isInColumn(int column, int row, list<ColumnLine*> columnLineList)
{
  ColumnLine* line;
  list<ColumnLine*>::iterator iter;
  for (iter=columnLineList.begin(); iter!=columnLineList.end(); iter++)
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

bool isInRow(int column, int row, list<RowLine*> rowLineList)
{
  RowLine* line;
  list<RowLine*>::iterator iter;
  for (iter=rowLineList.begin(); iter!=rowLineList.end(); iter++)
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

ColumnLine* findColumn(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;
  int row = inRow;

  while ((row < imageHeight) && (inImageData[(row*imageStep)+inColumn] == inColor))
    row++;

  
  return new ColumnLine(inColumn, inRow, row);  
}

RowLine* findRow(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageStep = inImage->widthStep;
  int column = inColumn;

  while ((column < imageWidth) && (inImageData[(inRow*imageStep)+column] == inColor))
    column++;
  
  return new RowLine(inRow, inColumn, column);  
}

list<ColumnLine*> accelerateColumns(IplImage* inImage, list<ColumnLine*> inColumnList,
                                    list<RowLine*> inRowList, int inColor)
{
  list<ColumnLine*> newList;
  ColumnLine* newColumn;
  list<ColumnLine*>::iterator iter;
  for (iter=inColumnList.begin(); iter!=inColumnList.end(); iter++)
  {
     if ((*iter)->height() > 15)
     {
       newColumn = new ColumnLine();
       newColumn->column = (*iter)->column;
       newColumn->bottom = lookDown(inImage, (*iter)->column, (*iter)->bottom,
                                  sqrt((*iter)->height()), inRowList, inColor);
       newColumn->top = lookUp(inImage, (*iter)->column, (*iter)->top,
                                  sqrt((*iter)->height()), inRowList, inColor);

       newList.push_back(newColumn);
     }
  }

  return newList;
}

list<RowLine*> accelerateRows(IplImage* inImage, list<ColumnLine*> inColumnList,
                              list<RowLine*> inRowList, int inColor)
{
  list<RowLine*> newList;
  RowLine* newRow;
  list<RowLine*>::iterator iter;
  for (iter=inRowList.begin(); iter!=inRowList.end(); iter++)
  {
     if ((*iter)->width() > 15)
     {
       newRow = new RowLine();
       newRow->row = (*iter)->row;
       newRow->right = lookRight(inImage, (*iter)->right, (*iter)->row,
                                  sqrt((*iter)->width()), inColumnList, inColor);
       newRow->left = lookLeft(inImage, (*iter)->left, (*iter)->row,
                                  sqrt((*iter)->width()), inColumnList, inColor);

       newList.push_back(newRow);
     }
  }

  return newList;
}

int lookDown(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<RowLine*> inRowList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  int column;
  int row = ((inRow - inDistance) > 0) ? (inRow - inDistance) : 0;
  int bottom = row;

  while ((row < inRow+inDistance) && (row <= imageHeight))
  {
    if (isInRow(inColumn, row, inRowList))
      break;

    for (column = inColumn-1; column <= inColumn+1; column++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        bottom = row;
      }
    }
    row++;
  }

  if (bottom == imageHeight-1) bottom = imageHeight;

  return bottom;
}

int lookUp(IplImage* inImage, int inColumn, int inRow, int inDistance,
           list<RowLine*> inRowList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  int row = ((inRow + inDistance) < imageHeight) ? (inRow + inDistance) : imageHeight;
  int top = row;
  int column;

  while ((row > inRow-inDistance) && (row >= 0))
  {
    if (isInRow(inColumn, row, inRowList))
      break;

    for (column = inColumn-1; column <= inColumn+1; column++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        top = row;
      }
    }
    row--;
  }

  if (top == 1) top = 0;

  return top;
}

int lookRight(IplImage* inImage, int inColumn, int inRow, int inDistance,
              list<ColumnLine*> inColumnList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  int row;
  int column = ((inColumn - inDistance) > 0) ? (inColumn - inDistance) : 0;
  int right = column;

  while ((column < inColumn+inDistance) && (column <= imageWidth))
  {
    if (isInColumn(column, inRow, inColumnList))
      break;

    for (row = inRow-1; row < inRow+2; row++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        right = column;
      }
    }
    column++;
  }

  if (right == imageWidth-1) right = imageWidth;

  return right;
}

int lookLeft(IplImage* inImage, int inColumn, int inRow, int inDistance,
             list<ColumnLine*> inColumnList, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int imageWidth = inImage->width;
  int imageHeight = inImage->height;
  int imageStep = inImage->widthStep;

  int row;
  int column = ((inColumn + inDistance) < imageWidth) ? (inColumn + inDistance) : imageWidth;
  int left = column;

  while ((column > inColumn-inDistance) && (column >= 0))
  {
    if (isInColumn(column, inRow, inColumnList))
      break;

    for (row = inRow-1; row < inRow+2; row++)
    {
      if (inImageData[(row*imageStep)+column] == inColor)
      {
        left = column;
      }
    }
    column--;
  }

  if (left == 1) left = 0;

  return left;
}

