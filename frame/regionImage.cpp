#include "pyramid.h"
#include "regionImage.h"
#include "utils.h"

int imageWidth;
int imageHeight;

BoundingRectangle* greedyFindRegion(int inColumn, int inRow, IplImage* inImage, int inColor);

list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor)
{
  int column, row;

  IplImage* tmpImage = cvCloneImage(inImage);
  imageWidth = tmpImage->width;
  imageHeight = tmpImage->height;

  list<BoundingRectangle*> boundingRectList; 
  BoundingRectangle* boundingRect;

  CvPoint point;

  printf("Finding Regions ...\n");
  for( row=0; row<imageHeight; row++ )
  {
    for(column=0; column<imageWidth; column++)
    {
      point.x = column;
      point.y = row;
      if (isColoredRegion(column, row, inImage, 1, inColor))
      {
        if (! isBoundByRectangle(point, boundingRectList, 0))
        {
          if (inColor == BLACK)
            boundingRect = greedyFindRegion(column, row, inImage, inColor);
          if (inColor == WHITE)
            boundingRect = findRegion(point, inImage, inColor);
          if (NULL != boundingRect)
            boundingRectList.push_back(boundingRect);
        }
      }
    }
  }

  return boundingRectList;
}

BoundingRectangle* greedyFindRegion(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  int left = inColumn;
  int top = inRow;
  int right = inColumn;
  int bottom = inRow;

  int currentRight = inColumn;
  int currentBottom = inRow;
  int startColumn = inColumn;
  int startRow = inRow;

  int columnCounter = inColumn;
  int rowCounter = inRow;
  bool foundRight = false;
  bool foundBottom = false;

  int currentArea;
  BoundingRectangle* newRectangle;

  // --  find initial bottom 
  rowCounter = top;
  while ((rowCounter < imageHeight) &&
         (isColoredRegion(startColumn, rowCounter, inImage, 1, inColor)))
    rowCounter++;
  currentBottom = rowCounter-1;

  // --  find initial right 
  columnCounter = left;
  while ((columnCounter < imageWidth) &&
         (isColoredRegion(columnCounter, startRow, inImage, 1, inColor)))
    columnCounter++;
  currentRight = columnCounter-1;  

  newRectangle = new BoundingRectangle(top, currentBottom, left, currentRight);
  currentArea = newRectangle->area() - 1;

  // --  grow recantle to it's edges
  /*
  while (currentArea < newRectangle->area())
  {
    currentArea = newRectangle->area();
    newRectangle->right = findRight(newRectangle, inImage, inColor);
    newRectangle->bottom = findBottom(newRectangle, inImage, inColor);
  }
  */
  return newRectangle;
}

int findBottom(BoundingRectangle* inRectangle, IplImage* inImage, int inColor)
{
  int imageHeight = inImage->height;
  int row = inRectangle->bottom;
  int newBottom = inRectangle->bottom;
  int column;

  while (row < imageHeight)
  {
    for(column=inRectangle->left; column<inRectangle->right; column++)
    {
      if (isColoredRegion(column, row, inImage, 1, inColor))
      {
        newBottom = row;
        break;
      }
    }
    if (column == inRectangle->right) break;
    row++;
  }

  return newBottom;
}

int findRight(BoundingRectangle* inRectangle, IplImage* inImage, int inColor)
{
  int imageWidth = inImage->width;
  int column = inRectangle->right;
  int newRight = inRectangle->right;
  int row;

  while (column < imageWidth)
  {
    for(row=inRectangle->top; row<inRectangle->bottom; row++)
    {
      if (isColoredRegion(column, row, inImage, 1, inColor))
      {
        newRight = column;
        break;
      }
    }
    if (row == inRectangle->bottom) break;
    column++;
  }

  if ((inRectangle->right * 1.1) > newRight)
    return inRectangle->right;

  return newRight;
}


BoundingRectangle* findRegion(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  int left = inColumn;
  int top = inRow;
  int right = inColumn;
  int bottom = inRow;
  int currentRight = inColumn;
  int startColumn = inColumn;
  int startRow = inRow;
  int columnCounter = 0;
  int rowCounter = 0;
  bool foundRight = false;
  
  for (rowCounter = startRow; rowCounter < imageHeight; rowCounter++)
  {
    if (! isColoredRegion(startColumn, rowCounter, inImage, 1, inColor))
    {
      bottom = (bottom > rowCounter) ? bottom : rowCounter;
      break;
    }

    for (columnCounter = startColumn; columnCounter < imageWidth; columnCounter++)
    {
      if (! isColoredRegion(columnCounter, rowCounter, inImage, 1, inColor))
      {
        currentRight = (currentRight > columnCounter) ? currentRight : columnCounter;
        break;
      }
    }

    if (! foundRight)
    {
      foundRight = true;
      right = currentRight;
    }
    else if ((right * 1.05) > currentRight)
    {
      right = currentRight;
    }
    else
    {
      break;
    }
  }
  
  bottom = (bottom > rowCounter) ? bottom : rowCounter;
  return new BoundingRectangle(top, bottom-1, left, right-1);
}

BoundingRectangle* findRegion(CvPoint inPoint, IplImage* inImage, int inColor)
{
  int left = inPoint.x;
  int top = inPoint.y;
  int currentColumn = left;
  int currentRow = top;

  bool foundBottom = false;
  bool foundRight = false;

  IplImage* tmpImage = cvCloneImage(inImage);
  uchar* tmpImageData = (uchar *) tmpImage->imageData;


  while ((isColoredRegion(currentColumn, currentRow, inImage, 1, inColor)) &&
         (currentColumn < imageWidth) && (currentRow < imageHeight))
  {
    currentColumn++;
    currentRow++;
    if (! isColoredRegion(left, currentRow, inImage, 1, inColor))
      break;
    if (! isColoredRegion(currentColumn, top, inImage, 1, inColor))
      break;
    if (! isColoredRegion(currentColumn, currentRow, inImage, 1, inColor))
      break;
  }

  if ((! isColoredRegion(left, currentRow, inImage, 1, inColor)) ||
      (imageHeight == currentRow))
    return findRight(top, left, currentRow-1, currentColumn-1, inImage, inColor);

  if ((! isColoredRegion(currentColumn, top, inImage, 1, inColor)) ||
      (imageWidth == currentColumn))
    return findBottom(top, left, currentRow-1, currentColumn-1, inImage, inColor);

  BoundingRectangle* returnRect =  new BoundingRectangle();
  returnRect->top = top;
  returnRect->left = left;
  returnRect->bottom = currentRow-1;
  returnRect->right = currentColumn-1;

  return returnRect;
}

BoundingRectangle* findRight(int inTop, int inLeft, int inBottom, int inRight, IplImage* inImage, int inColor)
{
  int pixel;
  int newRight = imageWidth;
  int currentColumn = inLeft;
  int currentRow = inTop;

  for (currentRow = inTop; currentRow <= inBottom; currentRow++)
  {
    currentColumn = inLeft;

    while ((isColoredRegion(currentColumn, currentRow, inImage, 0, inColor)) &&
           (currentColumn < imageWidth))
    {
      currentColumn++;
    }

    newRight = (newRight > currentColumn) ? newRight : currentColumn;
  }
  
  BoundingRectangle* returnRect =  new BoundingRectangle();
  returnRect->top = inTop;
  returnRect->left = inLeft;
  returnRect->bottom = inBottom;
  returnRect->right = newRight-1;

  return returnRect;
}

BoundingRectangle* findBottom(int inTop, int inLeft, int inBottom, int inRight, IplImage* inImage, int inColor)
{
  int pixel;
  int newBottom = imageHeight;
  int currentColumn = inLeft;
  int currentRow = inTop;
  bool myColor = true;

  for (currentColumn = inLeft; currentColumn <= inRight; currentColumn++)
  {
    currentRow = inTop;

    while ((isColoredRegion(currentColumn, currentRow, inImage, 0, inColor)) &&
           (currentRow < imageHeight))
    {
      currentRow++;
    }

    newBottom = (newBottom > currentRow) ? newBottom : currentRow;
  }

  BoundingRectangle* returnRect =  new BoundingRectangle();
  returnRect->top = inTop;
  returnRect->left = inLeft;
  returnRect->bottom = newBottom-1;
  returnRect->right = inRight;

  return returnRect;
}

