#include "pyramid.h"
#include "mergeRectList.h"
#include "BoundingRectangle.h"

BoundingRectangle::BoundingRectangle()
{
  top = 0;
  bottom = 0;
  left = 0;
  right = 0;
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

void BoundingRectangle::toString()
{
  printf("BoundingRectangle: top[%d] left[%d] bottom[%d] right[%d]\n",
         top, left, bottom, right);
}

void BoundingRectangle::toCode(int inN)
{
  printf("  BoundingRectangle* r%d = new BoundingRectangle(%d, %d, %d,%d);\n",
         inN, top, bottom, left, right);
  printf("  returnList.push_back(%d);\n\n", inN);
}

