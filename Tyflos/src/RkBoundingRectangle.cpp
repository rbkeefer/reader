/*
 * RkBoundingRectangle.cpp
 *
 */

#include "RkBoundingRectangle.h"

RkBoundingRectangle::RkBoundingRectangle() {
	  top = 0;
	  bottom = 0;
	  left = 0;
	  right = 0;
}

RkBoundingRectangle::RkBoundingRectangle(RkBoundingRectangle* inRectangle)
{
  top = inRectangle->top;
  bottom = inRectangle->bottom;
  left = inRectangle->left;
  right = inRectangle->right;
}

RkBoundingRectangle::RkBoundingRectangle(int inTop, int inLeft, int inBottom, int inRight)
{
  top = inTop;
  left = inLeft;
  bottom = inBottom;
  right = inRight;
}

RkBoundingRectangle::~RkBoundingRectangle() {
	// Do Nothing for now
}


CvPoint RkBoundingRectangle::topLeft()
{
  CvPoint point;
  point.x = left;
  point.y = top;

  return point;
}

CvPoint RkBoundingRectangle::bottomLeft()
{
  CvPoint point;
  point.x = left;
  point.y = bottom;

  return point;
}

CvPoint RkBoundingRectangle::bottomRight()
{
  CvPoint point;
  point.x = right;
  point.y = bottom;

  return point;
}

CvPoint RkBoundingRectangle::topRight()
{
  CvPoint point;
  point.x = right;
  point.y = top;

  return point;
}


int RkBoundingRectangle::width()
{
  return right-left;
}

int RkBoundingRectangle::height()
{
  return bottom-top;
}

int RkBoundingRectangle::area()
{
  int width = right-left;
  int height = bottom-top;

  return height*width;
}

bool RkBoundingRectangle::isPointIn(int inColumn, int inRow, int inTolerance)
{
  if ((inColumn >= left-inTolerance) && (inColumn <= right+inTolerance))
  {
    if ((inRow >= top-inTolerance) && (inRow <= bottom+inTolerance))
      return true;
  }

  return false;
}

bool RkBoundingRectangle::isRectIn(RkBoundingRectangle* inRect)
{
  if (! isPointIn(inRect->left, inRect->top, 0)) return false;
  if (! isPointIn(inRect->left, inRect->bottom, 0)) return false;
  if (! isPointIn(inRect->right, inRect->top, 0)) return false;
  if (! isPointIn(inRect->right, inRect->bottom, 0)) return false;

  return true;
}

bool RkBoundingRectangle::equals(RkBoundingRectangle* inRect)
{
  if (top != inRect->top) return false;
  if (bottom != inRect->bottom) return false;
  if (left != inRect->left) return false;
  if (right != inRect->right) return false;

  return true;
}

bool RkBoundingRectangle::isNear(RkBoundingRectangle* inRect, int inTolerance)
{
  if (isPointIn(inRect->left, inRect->top, inTolerance)) return true;
  if (isPointIn(inRect->left, inRect->bottom, inTolerance)) return true;
  if (isPointIn(inRect->right, inRect->top, inTolerance)) return true;
  if (isPointIn(inRect->right, inRect->bottom, inTolerance)) return true;

  if (inRect->isPointIn(left, top, inTolerance)) return true;
  if (inRect->isPointIn(left, bottom, inTolerance)) return true;
  if (inRect->isPointIn(right, top, inTolerance)) return true;
  if (inRect->isPointIn(right, bottom, inTolerance)) return true;

  return false;
}

bool RkBoundingRectangle::isVerticalOverlap(RkBoundingRectangle* inRect)
{
  if ((inRect->left >= left) && (inRect->right <= right))
  {
	  if (isPointIn(inRect->left, inRect->top, 0)) return true;
	  if (isPointIn(inRect->left, inRect->bottom, 0)) return true;
	  if (isPointIn(inRect->right, inRect->top, 0)) return true;
	  if (isPointIn(inRect->right, inRect->bottom, 0)) return true;
  }

  if ((left >= inRect->left) && (right <= inRect->right))
  {
	  if (inRect->isPointIn(left, top, 0)) return true;
	  if (inRect->isPointIn(left, bottom, 0)) return true;
	  if (inRect->isPointIn(right, top, 0)) return true;
	  if (inRect->isPointIn(right, bottom, 0)) return true;
  }

  return false;
}

bool RkBoundingRectangle::isAbove(RkBoundingRectangle* inRect, int inTolerance)
{
  if ((inRect->left >= left) && (inRect->left <= right))
  {
	if (inRect->bottom <= top+inTolerance) return true;
  }

  if ((inRect->right >= left) && (inRect->right <= right))
  {
	if (inRect->bottom <= top+inTolerance) return true;
  }

  return false;
}

bool RkBoundingRectangle::isBelow(RkBoundingRectangle* inRect, int inTolerance)
{
  if ((inRect->left >= left) && (inRect->left <= right))
  {
	if (inRect->top >= bottom-inTolerance) return true;
  }

  if ((inRect->right >= left) && (inRect->right <= right))
  {
	if (inRect->top >= bottom-inTolerance) return true;
  }

  return false;
}

bool RkBoundingRectangle::isLeft(RkBoundingRectangle* inRect, int inTolerance)
{
  if ((inRect->top >= top) && (inRect->top <= bottom))
  {
	if (inRect->right <= left+inTolerance) return true;
  }

  if ((inRect->bottom >= top) && (inRect->bottom <= bottom))
  {
	if (inRect->right <= left+inTolerance) return true;
  }

  return false;
}

bool RkBoundingRectangle::isRight(RkBoundingRectangle* inRect, int inTolerance)
{
  if ((inRect->top >= top) && (inRect->top <= bottom))
  {
	if (inRect->left >= right-inTolerance) return true;
  }

  if ((inRect->bottom >= top-inTolerance) && (inRect->bottom <= bottom+inTolerance))
  {
	if (inRect->left >= right-inTolerance) return true;
  }

  return false;
}

bool RkBoundingRectangle::isColumnShape()
{
  int height = bottom - top;
  int width = right - left;

  return (height > width) ? true : false;
}

bool RkBoundingRectangle::isRowShape()
{
  int height = bottom - top;
  int width = right - left;

  return (width > height) ? true : false;
}


void RkBoundingRectangle::move(CvPoint topLeft)
{
  top = top + topLeft.y;
  bottom = bottom + topLeft.y;

  left = left + topLeft.x;
  right = right + topLeft.x;
}

void RkBoundingRectangle::join(RkBoundingRectangle* inRectangle)
{
  top = (top < inRectangle->top) ? top : inRectangle->top;
  bottom = (bottom > inRectangle->bottom) ? bottom : inRectangle->bottom;
  left = (left < inRectangle->left) ? left : inRectangle->left;
  right = (right > inRectangle->right) ? right : inRectangle->right;
}

CvRect RkBoundingRectangle::toRect()
{
  CvRect rect;
  rect.x = left;
  rect.y = top;
  rect.width = width();
  rect.height = height();
  return rect;
}

void RkBoundingRectangle::printString(FILE* inFile)
{
	fprintf(inFile, "%d,%d,%d,%d\n", top, left, bottom, right);
}

void RkBoundingRectangle::toString()
{
	printf("BoundingRectangle: top[%d] left[%d] bottom[%d] right[%d]   Width:[%d] Height:[%d]\n",
	         top, left, bottom, right, width(), height());
}

