#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "regionImage.h"

BoundingRectangle* findRegion(int inColumn, int inRow, IplImage* inImage, int inColor);
BoundingRectangle* findRight(int inTop, int inLeft, int inBottom, int inRight, IplImage* inImage, int inColor);
BoundingRectangle* findBottom(int inTop, int inLeft, int inBottom, int inRight, IplImage* inImage, int inColor);

int imageWidth;
int imageHeight;

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
          // boundingRect = findRegion(point, inImage, inColor);
          boundingRect = findRegion(column, row, inImage, inColor);
          if (NULL != boundingRect)
            boundingRectList.push_back(boundingRect);
        }
      }
    }
  }

  return boundingRectList;
}

BoundingRectangle* findRegion(int inColumn, int inRow, IplImage* inImage, int inColor)
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

    newBottom = (newBottom < currentRow) ? newBottom : currentRow;
  }

  BoundingRectangle* returnRect =  new BoundingRectangle();
  returnRect->top = inTop;
  returnRect->left = inLeft;
  returnRect->bottom = newBottom-1;
  returnRect->right = inRight;

  return returnRect;
}

