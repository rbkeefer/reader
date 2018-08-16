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


bool RkBoundingRectangle::pointIn(int inColumn, int inRow, int inTolerance)
{
  if ((inColumn >= left-inTolerance) && (inColumn <= right+inTolerance))
  {
    if ((inRow >= top-inTolerance) && (inRow <= bottom+inTolerance))
      return true;
  }

  return false;
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
  if (pointIn(inRect->left, inRect->top, inTolerance)) return true;
  if (pointIn(inRect->left, inRect->bottom, inTolerance)) return true;
  if (pointIn(inRect->right, inRect->top, inTolerance)) return true;
  if (pointIn(inRect->right, inRect->bottom, inTolerance)) return true;

  if (inRect->pointIn(left, top, inTolerance)) return true;
  if (inRect->pointIn(left, bottom, inTolerance)) return true;
  if (inRect->pointIn(right, top, inTolerance)) return true;
  if (inRect->pointIn(right, bottom, inTolerance)) return true;

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


CvRect RkBoundingRectangle::toRect()
{
  CvRect rect;
  rect.x = left;
  rect.y = top;
  rect.width = width();
  rect.height = height();
  return rect;
}

void RkBoundingRectangle::toString()
{
	printf("BoundingRectangle: top[%d] left[%d] bottom[%d] right[%d]   Width:[%d] Height:[%d]\n",
	         top, left, bottom, right, width(), height());
}

