/*
 * RkRegions.cpp
 *
 */
#include "Segment.h"
#include "RkBoundingRectangle.h"
#include "RkUtils.h"
#include "RkRegions.h"

int regImgWidth = 128;
int regImgHeight = 128;

/*** Find Regions based on the values of the image *********/
list<RkBoundingRectangle*> regionizeImage(IplImage* inImage, int inColor)
{
  CvPoint point;
  int column, row;
  int pixel;

  uchar* inImageData = (uchar *) inImage->imageData;
  IplImage* tmpImage = cvCloneImage(inImage);
  regImgWidth = tmpImage->width;
  regImgHeight = tmpImage->height;

  list<RkBoundingRectangle*> boundingRectList;
  RkBoundingRectangle* boundingRect;

  printf("Finding Regions ...\n");
  for( row=0; row<regImgHeight; row++ )
  {
    for(column=0; column<regImgWidth; column++)
    {
      point.x = column;
      point.y = row;
      pixel = (row * regImgWidth) + column;
      if ( inImageData[pixel] == inColor )
      {
        if (! isBoundByRectangle(point, boundingRectList, 0))
        {
          boundingRect = regionBoundary(column, row, inImage, inColor);
          if (NULL != boundingRect)
            boundingRectList.push_back(boundingRect);
        }
      }
    }
  }

  return boundingRectList;
}

RkBoundingRectangle* regionBoundary(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  int top = inRow;
  int bottom = inRow;
  int left = inColumn;
  int right = inColumn;
  int counter = 0;

  CvPoint start;
  start.x = inColumn;
  start.y = inRow;

  int b = 0;
  CvPoint prev = start;
  CvPoint current = start;
  int n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;

  current = getPixel(current, n);
  b = getBValue(n);
  n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;

  while (! isSamePoint(current, start))
  {
    prev = current;
    current = getPixel(current, n);
    b = getBValue(n);
    n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;

    if (isSamePoint(current, prev)) break;
    if (counter++ > regImgWidth*regImgHeight) break;

    left = (left < current.x) ? left : current.x;
    right = (right > current.x) ? right : current.x;
    top = (top < current.y) ? top : current.y;
    bottom = (bottom > current.y) ? bottom : current.y;
  }

  RkBoundingRectangle* br = new RkBoundingRectangle(top, left, bottom, right);
  return br;
}


CvPoint getPixel(CvPoint inCurrent, int inPosition)
{

  CvPoint point;
  switch (inPosition)
  {
    case 0: // Due West
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == 0) && (inCurrent.y == regImgHeight - 1)) {point.x = 0; point.y = regImgHeight - 2;}
      else { point.x = inCurrent.x - 1; point.y = inCurrent.y; }
      break;
    case 1: // North West
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == 0)) {point.x = regImgWidth - 1; point.y = 1; }
      else if ((inCurrent.x == 0) && (inCurrent.y == regImgHeight - 1)) {point.x = 0; point.y = regImgHeight - 2; }
      else { point.x = inCurrent.x - 1; point.y = inCurrent.y - 1; }
      break;
    case 2: // Due North
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == 0)) {point.x = regImgWidth - 1; point.y = 1; }
      else { point.x = inCurrent.x; point.y = inCurrent.y - 1; }
      break;
    case 3: // North East
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == 0)) {point.x = regImgWidth - 1; point.y = 1; }
      else if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == regImgHeight - 1)) {point.x = regImgWidth - 2; point.y = regImgHeight - 1; }
      else { point.x = inCurrent.x + 1; point.y = inCurrent.y - 1; }
      break;
    case 4:  // Due East
      if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == 0)) {point.x = regImgWidth - 1; point.y = 1; }
      else if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == regImgHeight - 1)) {point.x = regImgWidth - 2; point.y = regImgHeight - 1; }
      else { point.x = inCurrent.x + 1; point.y = inCurrent.y; }
      break;
    case 5: // South East
      if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == 0)) {point.x = regImgWidth - 1; point.y = 1; }
      else if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == regImgHeight - 1)) {point.x = regImgWidth - 2; point.y = regImgHeight - 1; }
      else if ((inCurrent.x == 0) && (inCurrent.y == regImgHeight - 1)) {point.x = 0; point.y = regImgHeight - 2; }
      else { point.x = inCurrent.x + 1; point.y = inCurrent.y + 1; }
      break;
    case 6: // Due South
      if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == regImgHeight - 1)) {point.x = regImgWidth - 2; point.y = regImgHeight - 1; }
      else if ((inCurrent.x == 0) && (inCurrent.y == regImgHeight - 1)) {point.x = 0; point.y = regImgHeight - 2; }
      else { point.x = inCurrent.x; point.y = inCurrent.y + 1; }
      break;
    case 7: // South West
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == 0) && (inCurrent.y == regImgHeight - 1)) {point.x = 0; point.y = regImgHeight - 2; }
      else if ((inCurrent.x == regImgWidth - 1) && (inCurrent.y == regImgHeight - 1)) {point.x = regImgWidth - 2; point.y = regImgHeight - 1; }
      else { point.x = inCurrent.x - 1 ; point.y = inCurrent.y + 1; }
      break;
  }

  return point;
}

int getBValue(int n)
{
  switch(n)
  {
    case 0: return 6;
    case 1: return 6;
    case 2: return 0;
    case 3: return 0;
    case 4: return 2;
    case 5: return 2;
    case 6: return 4;
    case 7: return 4;
  }

  return -1;
}

int getValidPosition(CvPoint inCurrent, int inPosition)
{
  if ((inPosition == 0) && (inCurrent.x == 0)) return getValidPosition(inCurrent, 2);

  if ((inPosition == 1) && (inCurrent.x == 0)) return getValidPosition(inCurrent, 2);
  if ((inPosition == 1) && (inCurrent.y == 0)) return getValidPosition(inCurrent, 4);

  if ((inPosition == 2) && (inCurrent.y == 0)) return getValidPosition(inCurrent, 4);

  if ((inPosition == 3) && (inCurrent.x == regImgWidth-1)) return getValidPosition(inCurrent, 6);
  if ((inPosition == 3) && (inCurrent.y == 0)) return getValidPosition(inCurrent, 4);

  if ((inPosition == 4) && (inCurrent.x == regImgWidth-1)) return getValidPosition(inCurrent, 6);

  if ((inPosition == 5) && (inCurrent.x == regImgWidth-1)) return getValidPosition(inCurrent, 6);
  if ((inPosition == 5) && (inCurrent.y == regImgHeight-1)) return getValidPosition(inCurrent, 0);

  if ((inPosition == 6) && (inCurrent.y == regImgHeight-1)) return getValidPosition(inCurrent, 0);

  if ((inPosition == 7) && (inCurrent.x == 0)) return getValidPosition(inCurrent, 2);
  if ((inPosition == 7) && (inCurrent.y == regImgHeight-1)) return getValidPosition(inCurrent, 0);

  return inPosition%8;
}

int findNextPosition(CvPoint inCurrent, int inPosition, IplImage* inImage, int inColor)
{
  int nPosition = getValidPosition(inCurrent, inPosition);

  uchar* inImageData = (uchar *) inImage->imageData;
  CvPoint neighbor = getPixel(inCurrent, nPosition);
  int pixel = (neighbor.y * regImgWidth) + neighbor.x;

  if ( inImageData[pixel] == inColor )
    return nPosition;

  int endN = nPosition;
  nPosition = getValidPosition(inCurrent, nPosition + 1);
  while (endN != (nPosition%8))
  {
    neighbor = getPixel(inCurrent, nPosition%8);

    if (! isSamePoint(inCurrent, neighbor))
    {
      pixel = (neighbor.y * regImgWidth) + neighbor.x;

      if ( inImageData[pixel] == inColor )
        return nPosition%8;
    }

    nPosition = getValidPosition(inCurrent, nPosition + 1);
  }

  return -1;
}

