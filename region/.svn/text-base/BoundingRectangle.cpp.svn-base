#include "pyramid.h"
#include "BoundingRectangle.h"

BoundingRectangle::BoundingRectangle()
{
  top = 0;
  bottom = 0;
  left = 0;
  right = 0;
}

BoundingRectangle::BoundingRectangle(BoundingRectangle* inRectangle)
{
  top = inRectangle->top;
  bottom = inRectangle->bottom;
  left = inRectangle->left;
  right = inRectangle->right;
}

BoundingRectangle::BoundingRectangle(int inTop, int inBottom, int inLeft, int inRight)
{
  top = inTop;
  bottom = inBottom;
  left = inLeft;
  right = inRight;
}

CvPoint BoundingRectangle::topLeft()
{
  CvPoint point;
  point.x = left;
  point.y = top;

  return point;
}

CvPoint BoundingRectangle::bottomLeft()
{
  CvPoint point;
  point.x = left;
  point.y = bottom;

  return point;
}

CvPoint BoundingRectangle::bottomRight()
{
  CvPoint point;
  point.x = right;
  point.y = bottom;

  return point;
}

CvPoint BoundingRectangle::topRight()
{
  CvPoint point;
  point.x = right;
  point.y = top;

  return point;
}

int BoundingRectangle::width()
{
  return right-left;
}

int BoundingRectangle::height()
{
  return bottom-top;
}

int BoundingRectangle::area()
{
  int width = right-left;
  int height = bottom-top;

  return sqrt((width*width) + (height*height));
}

bool BoundingRectangle::pointIn(int inColumn, int inRow, int inTolerance)
{
  // printf("  BR [c,r] [%d, %d]  BR:[%d, %d, %d, %d]\n", inColumn, inRow, top, left, bottom, right);

  if ((inColumn >= left-inTolerance) && (inColumn <= right+inTolerance))
  {
    if ((inRow >= top-inTolerance) && (inRow <= bottom+inTolerance))
      return true;
  }

  return false;
}

bool BoundingRectangle::equals(BoundingRectangle* inRect)
{
  if (top != inRect->top) return false;
  if (bottom != inRect->bottom) return false;
  if (left != inRect->left) return false;
  if (right != inRect->right) return false;

  return true;
}

bool BoundingRectangle::isColumnShape()
{
  int height = bottom - top;
  int width = right - left;

  return (height >= width) ? true : false;
}

bool BoundingRectangle::isRowShape()
{
  int height = bottom - top;
  int width = right - left;

  return (width > height) ? true : false;
}

void BoundingRectangle::toString()
{
  printf("BoundingRectangle: top[%d] left[%d] bottom[%d] right[%d]\n",
         top, left, bottom, right);
}

void BoundingRectangle::toCode(int inN)
{
  printf("  BoundingRectangle* r%d = new BoundingRectangle(%d, %d, %d,%d);\n",
         inN, top, bottom, left, right);
  printf("  returnList.push_back(r%d);\n\n", inN);
}

