/*
 * RkColumn.cpp
 *
 */

#include "Frame.h"
#include "RkColumn.h"

RkColumn::RkColumn() {
	top = 0;
	bottom = 0;
	column = 0;
}

RkColumn::RkColumn(int inColumn, int inTop, int inBottom)
{
  top = inTop;
  bottom = inBottom;
  column = inColumn;
}

RkColumn::~RkColumn() {
	// Do Nothing for now
}

CvPoint RkColumn::topPoint()
{
  CvPoint point;
  point.x = column;
  point.y = top;

  return point;
}

CvPoint RkColumn::bottomPoint()
{
  CvPoint point;
  point.x = column;
  point.y = bottom;

  return point;
}

int RkColumn::height()
{
  return bottom-top;
}

bool RkColumn::pointIn(int inColumn, int inRow, int inTolerance)
{
  if (inColumn == column)
  {
    if ((inRow >= top-inTolerance) && (inRow <= bottom+inTolerance))
      return true;
  }

  return false;
}

bool RkColumn::equals(RkColumn* inLine)
{
  if (top != inLine->top) return false;
  if (bottom != inLine->bottom) return false;
  if (column != inLine->column) return false;

  return true;
}

void RkColumn::toString()
{
  printf("RkColumn: top[%d] bottom[%d] column[%d]\n",
         top, bottom, column);
}
