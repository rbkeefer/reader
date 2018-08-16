#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "RowLine.h"
#include "ColumnLine.h"
#include "findParts.h"
#include "regionImage.h"

int imageWidth;
int imageHeight;


/*** Find Regions based on the values of the image *********/
bool samePoint(CvPoint point1, CvPoint point2)
{
  if (point1.x != point2.x) return false;
  if (point1.y != point2.y) return false;
  return true;
}

CvPoint getPixel(CvPoint inCurrent, int inPosition)
{
  CvPoint point;
  switch (inPosition)
  {
    case 0:
      point.x = (inCurrent.x > 0) ? inCurrent.x - 1 : 0;
      point.y = inCurrent.y;
      break;
    case 1:
      point.x = (inCurrent.x > 0) ? inCurrent.x - 1 : 0;
      point.y = (inCurrent.y > 0) ? inCurrent.y - 1 : 0;
      break;
    case 2:
      point.x = inCurrent.x;
      point.y = (inCurrent.y > 0) ? inCurrent.y - 1 : 0;
      break;
    case 3:
      point.x = (inCurrent.x < imageWidth - 1) ? inCurrent.x + 1 : imageWidth - 1;
      point.y = (inCurrent.y > 0) ? inCurrent.y - 1 : 0;
      break;
    case 4:
      point.x = (inCurrent.x < imageWidth - 1) ? inCurrent.x + 1 : imageWidth - 1;
      point.y = inCurrent.y;
      break;
    case 5:
      point.x = (inCurrent.x < imageWidth - 1) ? inCurrent.x + 1 : imageWidth - 1;
      point.y = (inCurrent.y < imageHeight - 1) ? inCurrent.y + 1 : imageHeight - 1;
      break;
    case 6:
      point.x = inCurrent.x;
      point.y = (inCurrent.y < imageHeight - 1) ? inCurrent.y + 1 : imageHeight - 1;
      break;
    case 7:
      point.x = (inCurrent.x > 0) ? inCurrent.x - 1 : 0;
      point.y = (inCurrent.y < imageHeight - 1) ? inCurrent.y + 1 : imageHeight - 1;
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

int findNextPosition(CvPoint inCurrent, int inPosition, IplImage* inImage, int inColor)
{
  uchar* inImageData = (uchar *) inImage->imageData;
  CvPoint neighbor = getPixel(inCurrent, inPosition);
  int pixel = (neighbor.y * imageWidth) + neighbor.x;

  printf("\n  FIND inPixel:[%d, %d]    Neighbor:[%d, %d]\n",
            inCurrent.x, inCurrent.y, neighbor.x, neighbor.y);

  if ( inImageData[pixel] == inColor )
    return inPosition;

  int currentPosition = inPosition + 1;
  int endN = inPosition;
  while (endN != (currentPosition%8))
  {
    neighbor = getPixel(inCurrent, currentPosition%8);
    pixel = (neighbor.y * imageWidth) + neighbor.x;

    printf("              curN:[%d]   Neighbor:[%d, %d]\n", currentPosition%8, neighbor.x, neighbor.y);

    if ( inImageData[pixel] == inColor )
      return currentPosition%8;

    currentPosition++; 
  }  

  return -1;
}

BoundingRectangle* regionBoundary(int inColumn, int inRow, IplImage* inImage, int inColor)
{
  printf("\n******* New Rectangle *******\n");
  int top = inRow;
  int bottom = inRow;
  int left = inColumn;
  int right = inColumn;

  CvPoint start;
  start.x = inColumn;
  start.y = inRow;

  int b = 0;
  CvPoint prev = start;
  CvPoint current = start;
  int n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;
  printf("START: [%d, %d]  b:[%d]  n:[%d]\n", start.x, start.y, b, n);

  current = getPixel(current, n);
  b = getBValue(n);
  n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;
  printf("    Current: [%d, %d]  b:[%d]  n:[%d]\n", current.x, current.y, b, n);

  while (! samePoint(current, start))
  {
    prev = current;
    current = getPixel(current, n);
    b = getBValue(n);
    n = findNextPosition(current, b, inImage, inColor); if (-1 == n) return NULL;
    printf("    Current: [%d, %d]  b:[%d]  n:[%d]\n", current.x, current.y, b, n);

    if (samePoint(current, prev)) break;

    left = (left < current.x) ? left : current.x;
    right = (right > current.x) ? right : current.x;
    top = (top < current.y) ? top : current.y;
    bottom = (bottom > current.y) ? bottom : current.y;
  }

  BoundingRectangle* br = new BoundingRectangle(top, bottom, left, right);
  br->toString();
  printf("*** END Rectangle ***\n\n");
  return br;
}

list<BoundingRectangle*> regionizeImage(IplImage* inImage, int inColor)
{
  CvPoint point;
  int column, row;
  int pixel;

  uchar* inImageData = (uchar *) inImage->imageData;
  IplImage* tmpImage = cvCloneImage(inImage);
  imageWidth = tmpImage->width;
  imageHeight = tmpImage->height;

  list<BoundingRectangle*> boundingRectList; 
  BoundingRectangle* boundingRect;

  printf("Finding Regions ...\n");
  for( row=0; row<imageHeight; row++ )
  {
    for(column=0; column<imageWidth; column++)
    {
      point.x = column;
      point.y = row;
      pixel = (row * imageWidth) + column;
      if ( inImageData[pixel] == inColor )
      {
        printf("1");
        if (! isBoundByRectangle(point, boundingRectList, 0))
        {
          boundingRect = regionBoundary(column, row, inImage, inColor);
          if (NULL != boundingRect)
            boundingRectList.push_back(boundingRect);
        }
      }
      else
      {
        printf("0");
      }
    }
    printf("\n");
  }

  return boundingRectList;
}

