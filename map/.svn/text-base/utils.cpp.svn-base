#include "pyramid.h"
#include "utils.h"
#include "BoundingRectangle.h"


bool isBoundByRectangle(CvPoint inPoint, list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  BoundingRectangle* boundingRect;
  list<BoundingRectangle*>::iterator iter;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    boundingRect = (*iter);
    if (isBoundByRectangle(inPoint, boundingRect, inTolerance))
      return true;
  }

  return false;
}

bool isBoundByRectangle(CvPoint inPoint, BoundingRectangle* inRectangle, int inTolerance)
{
  if (inRectangle->pointIn(inPoint.x, inPoint.y, inTolerance))
    return true;

  return false;
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

bool isColoredColumn(int inColumn, int inStartRow, int inEndRow, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int inImageStep = inImage->widthStep;
  int coloredColumnCounter = 0;
  int rowCounter = 0;

  if (inStartRow == inEndRow)
  {
    if( inImageData[inImageStep*inStartRow+inColumn] == inColor )
      return true;

    return false;
  }

  for( rowCounter=inStartRow; rowCounter<inEndRow; rowCounter++ )
  {
    if( inImageData[inImageStep*rowCounter+inColumn] != inColor )
      coloredColumnCounter++;
  }

  if (coloredColumnCounter == (inEndRow - inStartRow))
    return false;

  return true;
}

bool isColoredRow(int inRow, int inStartColumn, int inEndColumn, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  int inImageStep = inImage->widthStep;
  int coloredRowCounter = 0;
  int columnCounter = 0;

  if (inStartColumn == inEndColumn)
  {
    if( inImageData[inImageStep*inEndColumn+inRow] == inColor )
      return true;

    return false;
  }

  for( columnCounter=inStartColumn; columnCounter<inEndColumn; columnCounter++ )
  {
    if( inImageData[inImageStep*inRow+columnCounter] == inColor )
      coloredRowCounter++;
  }

  if (coloredRowCounter == (inEndColumn - inStartColumn))
    return true;

  return false;
}

bool isIn(int inX, int inY, BoundingRectangle* inRectangle, int inTolerance)
{
  bool in = false;
  CvPoint point;
  point.x = inX;
  point.y = inY;

  if (isBoundByRectangle(point, inRectangle, inTolerance)) in = true;

  return in;
}

bool isNear(int point1, int point2, int tolerance)
{
  bool near = false;

  if (point1 == point2) near = true;
  if ( (point1+tolerance >= point2) && (point1-tolerance <= point2) ) near = true;

  return near;
}

bool sameRectangle(BoundingRectangle* first, BoundingRectangle* second)
{
  if (first->top != second->top) return false;
  if (first->bottom != second->bottom) return false;
  if (first->left != second->left) return false;
  if (first->right != second->right) return false;

  return true;
}

bool compareTopLeft(BoundingRectangle* first, BoundingRectangle* second)
{
  if ((first->top < second->top) && (first->left < second->left))
    return true;

  return false;
}

BoundingRectangle* combineRectangles(BoundingRectangle* rect1, BoundingRectangle* rect2)
{
  BoundingRectangle* returnRect = rect1;

  returnRect->top = (rect1->top < rect2->top) ? rect1->top : rect2->top;
  returnRect->left = (rect1->left < rect2->left) ? rect1->left : rect2->left;
  returnRect->right = (rect1->right > rect2->right) ? rect1->right : rect2->right;
  returnRect->bottom = (rect1->bottom > rect2->bottom) ? rect1->bottom : rect2->bottom;

  return returnRect;
}

void dumpRectList(list<BoundingRectangle*> rectList)
{
  int currentRect = 0;
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* rectangle;
  for (iter=rectList.begin(); iter!=rectList.end(); iter++)
  {
    currentRect++;
    rectangle = (*iter);
    printf("%d. ", currentRect); rectangle->toString();
  }
}


