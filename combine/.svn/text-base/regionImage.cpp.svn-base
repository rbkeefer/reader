#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "RowLine.h"
#include "ColumnLine.h"
#include "findParts.h"
#include "regionImage.h"

int imageWidth;
int imageHeight;


/***** Find Regions based on combining the found columns and rows *****/
list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor,
                                        list<ColumnLine*> inColumnLines, list<RowLine*> inRowLines)
{
  CvPoint point;
  int column, row;

  IplImage* tmpImage = cvCloneImage(inImage);
  imageWidth = tmpImage->width;
  imageHeight = tmpImage->height;

  list<BoundingRectangle*> boundingRectList; 
  BoundingRectangle* boundingRect;

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
          boundingRect = rectFromLines(column, row, inColumnLines, inRowLines);
          if (NULL != boundingRect)
            boundingRectList.push_back(boundingRect);
        }
      }
    }
  }

  return boundingRectList;
}

BoundingRectangle* rectFromLines(int inColumn, int inRow, 
                              list<ColumnLine*> inColumnLines, list<RowLine*> inRowLines)
{
  int top = findTop(inColumn, inRow, inRowLines);
  int bottom = findBottom(inColumn, inRow, inRowLines);
  int left = findLeft(inColumn, inRow, inColumnLines);
  int right = findRight(inColumn, inRow, inColumnLines);

  return new BoundingRectangle(top, bottom, left, right);
}

int findTop(int inColumn, int inRow, list<RowLine*> inRowLines)
{
  int newTop = 0;
  int currentRow = inRow;

  list<RowLine*>::iterator rowIter;
  RowLine* rowLine;

  while (currentRow > 0)
  {
    for (rowIter=inRowLines.begin(); rowIter!=inRowLines.end(); rowIter++)
    {
      rowLine = (*rowIter);
      if (rowLine->pointIn(inColumn, currentRow))
      {
        newTop = currentRow;
        break;
      }
    }

    if (newTop != 0) break;

    currentRow--;
  }

  return newTop;
}

int findBottom(int inColumn, int inRow, list<RowLine*> inRowLines)
{
  int newBottom = imageHeight;
  int currentRow = inRow;

  list<RowLine*>::iterator rowIter;
  RowLine* rowLine;

  while (currentRow < imageHeight)
  {
    for (rowIter=inRowLines.begin(); rowIter!=inRowLines.end(); rowIter++)
    {
      rowLine = (*rowIter);
      if (rowLine->pointIn(inColumn, currentRow))
      {
        newBottom = currentRow;
        break;
      }
    }

    if (newBottom != imageHeight) break;

    currentRow++;
  }

  return newBottom;

}


int findLeft(int inColumn, int inRow, list<ColumnLine*> inColumnLines)
{
  int newLeft = 0;
  int currentColumn = inColumn;

  list<ColumnLine*>::iterator columnIter;
  ColumnLine* columnLine;

  while (currentColumn > 0)
  {
    for (columnIter=inColumnLines.begin(); columnIter!=inColumnLines.end(); columnIter++)
    {
      columnLine = (*columnIter);
      if (columnLine->pointIn(currentColumn, inRow))
      {
        newLeft = currentColumn;
        break;
      }
    }

    if (newLeft != 0) break;

    currentColumn--;
  }

  return newLeft;
}

int findRight(int inColumn, int inRow, list<ColumnLine*> inColumnLines)
{
  int newRight = imageWidth;
  int currentColumn = inColumn;

  list<ColumnLine*>::iterator columnIter;
  ColumnLine* columnLine;

  while (currentColumn < imageWidth)
  {
    for (columnIter=inColumnLines.begin(); columnIter!=inColumnLines.end(); columnIter++)
    {
      columnLine = (*columnIter);
      if (columnLine->pointIn(currentColumn, inRow))
      {
        newRight = currentColumn;
        break;
      }
    }

    if (newRight != imageWidth) break;

    currentColumn++;
  }

  return newRight;
}


/*** Find Regions based on the values of the image *********/
list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor)
{
  CvPoint point;
  int column, row;

  IplImage* tmpImage = cvCloneImage(inImage);
  imageWidth = tmpImage->width;
  imageHeight = tmpImage->height;

  list<BoundingRectangle*> boundingRectList; 
  BoundingRectangle* boundingRect;

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
          // boundingRect = angularSearch(point, inImage, inColor);
          // boundingRect = simpleSearch(column, row, inImage, inColor);
          boundingRect = nearestNeighbor(column, row, inImage, inColor);
          if (NULL != boundingRect)
            boundingRectList.push_back(boundingRect);
        }
      }
    }
  }

  return boundingRectList;
}

/*** Nearest Neighbor Search ***/
bool validPixel(int x, int y, uchar* inImage, int inColor)
{
  //printf("VALID: %d, %d\n", x, y);
  //getchar();

  if (x < 0) return false;
  if (y < 0) return false;
  if (x > imageWidth) return false;
  if (y > imageHeight) return false;

  if ((y*imageWidth+x) < 0) return false;
  if ((y*imageWidth+x) > (imageWidth*imageHeight)) return false;
  if (inImage[(y * imageWidth) + x] != inColor) return false;

  return true;
}

BoundingRectangle* nearestNeighbor(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  int top = nnFindTop(inColumn, inRow, inImage, inColor);
  int bottom = nnFindBottom(inColumn, inRow, inImage, inColor);

  int left = nnFindLeft(inColumn, inRow, inImage, inColor);
  int right = nnFindRight(inColumn, inRow, inImage, inColor);
 
  return new BoundingRectangle(top, bottom, left, right);
}

int nnFindTop(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  if (inRow <= 0) return 0;
  if (inColumn <= 0) return inRow;
  if (inRow >= imageHeight) return imageHeight;
  if (inColumn >= imageWidth) return inRow;

  int row = inRow;
  int topLeft = inRow;
  int topRight = inRow;
  uchar* tmpImage = (uchar *) inImage->imageData;

  while (validPixel(inColumn, row, tmpImage, inColor))
    row--;

  // if ((inColumn > 0) && (tmpImage[(row*imageWidth) + (inColumn-1)] == inColor))
  if (validPixel(inColumn-1, row, tmpImage, inColor))
    topLeft = nnFindTop(inColumn-1, row, inImage, inColor);
  else
    topLeft = row+1;

  // if ((inColumn < imageWidth) && (tmpImage[(row*imageWidth) + (inColumn+1)] == inColor))
  if (validPixel(inColumn+1, row, tmpImage, inColor))
    topRight = nnFindTop(inColumn+1, row, inImage, inColor);
  else
    topRight = row+1;

  return (topLeft < topRight) ? topLeft : topRight;
}

int nnFindBottom(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  if (inRow <= 0) return 0;
  if (inColumn <= 0) return inRow;
  if (inRow >= imageHeight) return imageHeight;
  if (inColumn >= imageWidth) return inRow;

  int row = inRow;
  int bottomLeft = inRow;
  int bottomRight = inRow;
  uchar* tmpImage = (uchar *) inImage->imageData;

  while (validPixel(inColumn, row, tmpImage, inColor))
    row++;

  // if ((inColumn > 0) && (tmpImage[(row*imageWidth) + (inColumn-1)] == inColor))
  if (validPixel(inColumn-1, row, tmpImage, inColor))
    bottomLeft = nnFindBottom(inColumn-1, row, inImage, inColor);
  else
    bottomLeft = row;

  // if ((inColumn < imageWidth) && (tmpImage[(row*imageWidth) + (inColumn+1)] == inColor))
  if (validPixel(inColumn+1, row, tmpImage, inColor))
    bottomRight = nnFindBottom(inColumn+1, row, inImage, inColor);
  else
    bottomRight = row;

  return (bottomLeft > bottomRight) ? bottomLeft : bottomRight;
}

int nnFindLeft(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  if (inRow <= 0) return 0;
  if (inColumn <= 0) return inRow;
  if (inRow >= imageHeight) return imageHeight;
  if (inColumn >= imageWidth) return inRow;

  int column = inColumn;
  int leftTop = inColumn;
  int leftBottom = inColumn;
  uchar* tmpImage = (uchar *) inImage->imageData;

  while(validPixel(column, inRow, tmpImage, inColor))
    column--;

  // if ((inRow > 0) && (tmpImage[((inRow-1)*imageWidth) + column] == inColor))
  if (validPixel(column, inRow-1, tmpImage, inColor))
    leftTop = nnFindLeft(column, inRow-1, inImage, inColor);
  else
    leftTop = column+1;

  // if ((inRow < imageHeight) && (tmpImage[((inRow+1)*imageWidth) + column] == inColor))
  if (validPixel(column, inRow+1, tmpImage, inColor))
    leftBottom = nnFindLeft(column, inRow+1, inImage, inColor);
  else
    leftBottom = column+1;

  return (leftTop < leftBottom) ? leftTop : leftBottom;
}


int nnFindRight(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  if (inRow <= 0) return 0;
  if (inColumn <= 0) return inRow;
  if (inRow >= imageHeight) return imageHeight;
  if (inColumn >= imageWidth) return inRow;

  int column = inColumn;
  int rightTop = inColumn;
  int rightBottom = inColumn;
  uchar* tmpImage = (uchar *) inImage->imageData;

  while(validPixel(column, inRow, tmpImage, inColor))
    column++;

  // if ((inRow > 0) && (tmpImage[((inRow-1)*imageWidth) + column] == inColor))
  if (validPixel(column, inRow-1, tmpImage, inColor))
    rightTop = nnFindRight(column, inRow-1, inImage, inColor);
  else
    rightTop = column;

  // if ((inRow < imageHeight) && (tmpImage[((inRow+1)*imageWidth) + column] == inColor))
  if (validPixel(column, inRow+1, tmpImage, inColor))
    rightBottom = nnFindRight(column, inRow+1, inImage, inColor);
  else
    rightBottom = column;

  return (rightTop > rightBottom) ? rightTop : rightBottom;
}


/*** Simple search ***/
BoundingRectangle* simpleSearch(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  int left = inColumn;
  int top = inRow;
  int right = inColumn;
  int bottom = inRow;
  int startColumn = inColumn;
  int startRow = inRow;
  int columnCounter = 0;
  int rowCounter = 0;

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
        right = (right > columnCounter) ? right : columnCounter;
        break;
      }
    }
  }

  bottom = (bottom > rowCounter) ? bottom : rowCounter;
  return new BoundingRectangle(top, bottom, left, right);
}

/*** Angular Search ***/
BoundingRectangle* angularSearch(CvPoint inPoint, IplImage* inImage, int inColor)
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

    newRight = (newRight < currentColumn) ? newRight : currentColumn;
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

    newBottom = (newBottom < currentRow) ? newBottom : currentRow;
  }

  BoundingRectangle* returnRect =  new BoundingRectangle();
  returnRect->top = inTop;
  returnRect->left = inLeft;
  returnRect->bottom = newBottom-1;
  returnRect->right = inRight;

  return returnRect;
}

