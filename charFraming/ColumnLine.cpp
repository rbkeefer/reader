#include "pyramid.h"
#include "ColumnLine.h"

ColumnLine::ColumnLine()
{
  top = 0;
  bottom = 0;
  column = 0;
}

ColumnLine::ColumnLine(int inColumn, int inTop, int inBottom)
{
  top = inTop;
  bottom = inBottom;
  column = inColumn;
}

CvPoint ColumnLine::topPoint()
{
  CvPoint point;
  point.x = column;
  point.y = top;

  return point;
}

CvPoint ColumnLine::bottomPoint()
{
  CvPoint point;
  point.x = column;
  point.y = bottom;

  return point;
}

int ColumnLine::height()
{
  return bottom-top;
}

bool ColumnLine::pointIn(int inColumn, int inRow, int inTolerance)
{
  if (inColumn == column)
  {
    if ((inRow >= top-inTolerance) && (inRow <= bottom+inTolerance))
      return true;
  }

  return false;
}

bool ColumnLine::equals(ColumnLine* inLine)
{
  if (top != inLine->top) return false;
  if (bottom != inLine->bottom) return false;
  if (column != inLine->column) return false;

  return true;
}

void ColumnLine::toString()
{
  printf("ColumnLine: top[%d] bottom[%d] column[%d]\n",
         top, bottom, column);
}


