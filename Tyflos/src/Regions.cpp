/*
 * Regions.cpp
 *
 */
#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkArticle.h"

#include "Utils.h"
#include "Regions.h"

/*** Find Regions based on the values of the image *********/
list<RkBoundingRectangle*> getRegionBoundaries(IplImage* inImage, int inColor)
{
  CvPoint point;
  int column, row;
  int pixel;

  uchar* inImageData = (uchar *) inImage->imageData;
  IplImage* tmpImage = cvCloneImage(inImage);
  int imgStep = tmpImage->widthStep;
  int imgWidth = tmpImage->width;
  int imgHeight = tmpImage->height;

  list<RkBoundingRectangle*> boundingRectList;
  RkBoundingRectangle* boundingRect;

  printf("Finding Regions ...\n");
  for( row=0; row<imgHeight; row++ )
  {
    for(column=0; column<imgWidth; column++)
    {
      point.x = column;
      point.y = row;
      pixel = (row * imgStep) + column;
      if ( inImageData[pixel] == inColor )
      {
        if (! isPointBoundByRectangle(point, boundingRectList, 0))
        {
          if (isColoredRegion(column, row, BOX_SIZE, inImage, inColor))
          {
            boundingRect = regionBoundary(column, row, inImage, inColor);
            if (NULL != boundingRect)
              boundingRectList.push_back(boundingRect);
          }
        }
      }
    }
  }

  return boundingRectList;
}

RkBoundingRectangle* regionBoundary(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  int imgWidth = inImage->width;
  int imgHeight = inImage->height;
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

  current = getPixel(current, n, imgHeight, imgWidth);
  b = getBValue(n);
  n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;

  while (! isSamePoint(current, start))
  {
    prev = current;
    current = getPixel(current, n, imgHeight, imgWidth);
    b = getBValue(n);
    n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;

    if (isSamePoint(current, prev)) break;
    if (counter++ > imgWidth*imgHeight) break;

    left = (left < current.x) ? left : current.x;
    right = (right > current.x) ? right : current.x;
    top = (top < current.y) ? top : current.y;
    bottom = (bottom > current.y) ? bottom : current.y;
  }

  return new RkBoundingRectangle(top, left, bottom, right);

}


CvPoint getPixel(CvPoint inCurrent, int inPosition, int inImgHeight, int inImgWidth)
{

  CvPoint point;
  switch (inPosition)
  {
    case 0: // Due West
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == 0) && (inCurrent.y == inImgHeight - 1)) {point.x = 0; point.y = inImgHeight - 2;}
      else if (inCurrent.x == 0) {point.x = 1; point.y = inCurrent.y;}
      else { point.x = inCurrent.x - 1; point.y = inCurrent.y; }
      break;
    case 1: // North West
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == 0)) {point.x = inImgWidth - 1; point.y = 1; }
      else if ((inCurrent.x == 0) && (inCurrent.y == inImgHeight - 1)) {point.x = 0; point.y = inImgHeight - 2; }
      else if (inCurrent.x == 0) {point.x = 0; point.y = inCurrent.y-1;}
      else if (inCurrent.y == 0) {point.x = inCurrent.x + 1; point.y = 0;}
      else { point.x = inCurrent.x - 1; point.y = inCurrent.y - 1; }
      break;
    case 2: // Due North
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == 0)) {point.x = inImgWidth - 1; point.y = 1; }
      else if (inCurrent.y == 0) {point.x = inCurrent.x; point.y = 1;}
      else { point.x = inCurrent.x; point.y = inCurrent.y - 1; }
      break;
    case 3: // North East
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; } // top left
      else if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == 0)) {point.x = inImgWidth - 1; point.y = 1; } // top right
      else if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == inImgHeight - 1)) {point.x = inImgWidth - 2; point.y = inImgHeight - 1; } // bottom right
      else if (inCurrent.x == inImgWidth - 1) {point.x = inImgWidth - 1; point.y = inCurrent.y + 1; }
      else if (inCurrent.y == 0) {point.x = inCurrent.x + 1; point.y = 0;}
      else { point.x = inCurrent.x + 1; point.y = inCurrent.y - 1; }
      break;
    case 4:  // Due East
      if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == 0)) {point.x = inImgWidth - 1; point.y = 1; } // top right
      else if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == inImgHeight - 1)) {point.x = inImgWidth - 2; point.y = inImgHeight - 1; } // bottom right
      else if (inCurrent.x == inImgWidth - 1) {point.x = inImgWidth - 2; point.y = inCurrent.y; }
      else { point.x = inCurrent.x + 1; point.y = inCurrent.y; }
      break;
    case 5: // South East
      if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == 0)) {point.x = inImgWidth - 1; point.y = 1; } // top right
      else if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == inImgHeight - 1)) {point.x = inImgWidth - 2; point.y = inImgHeight - 1; } // bottom right
      else if ((inCurrent.x == 0) && (inCurrent.y == inImgHeight - 1)) {point.x = 0; point.y = inImgHeight - 2; } // bottom left
      else if (inCurrent.x == inImgWidth - 1) {point.x = inImgWidth - 1; point.y = inCurrent.y + 1; }
      else if (inCurrent.y == inImgWidth - 1) {point.x = inCurrent.x -1; point.y = inCurrent.y; }
      else { point.x = inCurrent.x + 1; point.y = inCurrent.y + 1; }
      break;
    case 6: // Due South
      if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == inImgHeight - 1)) {point.x = inImgWidth - 2; point.y = inImgHeight - 1; }
      else if ((inCurrent.x == 0) && (inCurrent.y == inImgHeight - 1)) {point.x = 0; point.y = inImgHeight - 2; }
      else if (inCurrent.y == inImgWidth - 1) {point.x = inCurrent.x; point.y = inCurrent.y - 1; }
      else { point.x = inCurrent.x; point.y = inCurrent.y + 1; }
      break;
    case 7: // South West
      if ((inCurrent.x == 0) && (inCurrent.y == 0)) {point.x = 1; point.y = 0; }
      else if ((inCurrent.x == 0) && (inCurrent.y == inImgHeight - 1)) {point.x = 0; point.y = inImgHeight - 2; }
      else if ((inCurrent.x == inImgWidth - 1) && (inCurrent.y == inImgHeight - 1)) {point.x = inImgWidth - 2; point.y = inImgHeight - 1; }
      else if (inCurrent.x == 0) {point.x = 0; point.y = inCurrent.y-1;}
      else if (inCurrent.y == inImgWidth - 1) {point.x = inCurrent.x -1; point.y = inCurrent.y; }
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

int getValidPosition(CvPoint inCurrent, int inPosition, int inImgHeight, int inImgWidth)
{
  if ((inPosition == 0) && (inCurrent.x == 0)) return getValidPosition(inCurrent, 2, inImgHeight, inImgWidth);

  if ((inPosition == 1) && (inCurrent.x == 0)) return getValidPosition(inCurrent, 2, inImgHeight, inImgWidth);
  if ((inPosition == 1) && (inCurrent.y == 0)) return getValidPosition(inCurrent, 4, inImgHeight, inImgWidth);

  if ((inPosition == 2) && (inCurrent.y == 0)) return getValidPosition(inCurrent, 4, inImgHeight, inImgWidth);

  if ((inPosition == 3) && (inCurrent.x == inImgWidth-1)) return getValidPosition(inCurrent, 6, inImgHeight, inImgWidth);
  if ((inPosition == 3) && (inCurrent.y == 0)) return getValidPosition(inCurrent, 4, inImgHeight, inImgWidth);

  if ((inPosition == 4) && (inCurrent.x == inImgWidth-1)) return getValidPosition(inCurrent, 6, inImgHeight, inImgWidth);

  if ((inPosition == 5) && (inCurrent.x == inImgWidth-1)) return getValidPosition(inCurrent, 6, inImgHeight, inImgWidth);
  if ((inPosition == 5) && (inCurrent.y == inImgHeight-1)) return getValidPosition(inCurrent, 0, inImgHeight, inImgWidth);

  if ((inPosition == 6) && (inCurrent.y == inImgHeight-1)) return getValidPosition(inCurrent, 0, inImgHeight, inImgWidth);

  if ((inPosition == 7) && (inCurrent.x == 0)) return getValidPosition(inCurrent, 2, inImgHeight, inImgWidth);
  if ((inPosition == 7) && (inCurrent.y == inImgHeight-1)) return getValidPosition(inCurrent, 0, inImgHeight, inImgWidth);

  return inPosition%8;
}

int findNextPosition(CvPoint inCurrent, int inPosition, IplImage* inImage, int inColor)
{
  int imgStep = inImage->widthStep;
  int imgWidth = inImage->width;
  int imgHeight = inImage->height;

  int nPosition = getValidPosition(inCurrent, inPosition, imgHeight, imgWidth);

  uchar* inImageData = (uchar *) inImage->imageData;
  CvPoint neighbor = getPixel(inCurrent, nPosition, imgHeight, imgWidth);
  int pixel = (neighbor.y * imgStep) + neighbor.x;

  if ( inImageData[pixel] == inColor )
    return nPosition;

  int endN = nPosition;
  nPosition = getValidPosition(inCurrent, nPosition + 1, imgHeight, imgWidth);
  while (endN != (nPosition%8))
  {
    neighbor = getPixel(inCurrent, nPosition%8, imgHeight, imgWidth);

    if (! isSamePoint(inCurrent, neighbor))
    {
      pixel = (neighbor.y * imgStep) + neighbor.x;

      if ( inImageData[pixel] == inColor )
        return nPosition%8;
    }

    nPosition = getValidPosition(inCurrent, nPosition + 1, imgHeight, imgWidth);
  }

  return -1;
}

