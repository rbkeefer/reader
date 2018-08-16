#include <list>
#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "frameImage.h"
using namespace std;

int findLeftSide(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList);
int findRightSide(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList);
int findTop(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList);
int findBottom(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList);
BoundingRectangle* findBoundaries(BoundingRectangle* inRect,
                                  list<BoundingRectangle*> inRectList);

int requiredArea = 0;

list<BoundingRectangle*> frameImage(list<BoundingRectangle*> inBlackRectList,
                                    list<BoundingRectangle*> inWhiteRectList)
{
  BoundingRectangle* rectangle;
  BoundingRectangle* newRectangle;
  list<BoundingRectangle*> frameList;
  list<BoundingRectangle*>::iterator iter;

  printf("Frame Image ...\n");

  for (iter=inBlackRectList.begin(); iter!=inBlackRectList.end(); iter++)
  {
    rectangle = (*iter);

    newRectangle = findBoundaries(rectangle, inWhiteRectList);
    frameList.push_back(newRectangle);
  }

  return frameList;
}

BoundingRectangle* findBoundaries(BoundingRectangle* inRect,
                                  list<BoundingRectangle*> inRectList)
{
  BoundingRectangle* newRectangle = new BoundingRectangle(inRect);

  newRectangle->left = findLeftSide(inRect, inRectList);
  newRectangle->top = findTop(inRect, inRectList);
  newRectangle->right = findRightSide(inRect, inRectList);
  newRectangle->bottom = findBottom(inRect, inRectList);

  return newRectangle;
}

int findLeftSide(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList)
{
  int leftValue = inRect->left;
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  int closest = 1024;
  int spread = 0;
  CvPoint point;
  point.x = inRect->left;
  point.y = inRect->top;

  for (iter=inRectList.begin(); iter!=inRectList.end(); iter++)
  {
    rectangle = (*iter);

    if (rectangle->area() > requiredArea)
    {
      if (isBoundByRectangle(point, rectangle, 1))
      {
        spread = inRect->left - rectangle->right;

        if ((spread >= 0) && (spread < closest))
        {
          closest = spread;
          leftValue = rectangle->right;
        }
      }
    }
  }

  return leftValue;
}

int findRightSide(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList)
{
  int rightValue = inRect->right;
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  int closest = 1024;
  int spread = 0;
  CvPoint point;
  point.x = inRect->right;
  point.y = inRect->bottom;

  for (iter=inRectList.begin(); iter!=inRectList.end(); iter++)
  {
    rectangle = (*iter);

    if (rectangle->area() > requiredArea)
    {
      if (isBoundByRectangle(point, rectangle, 1))
      {
        spread = rectangle->left - inRect->right;

        if ((spread >= 0) && (spread < closest))
        {
          closest = spread;
          rightValue = rectangle->left;
        }
      }
    }
  }

  return rightValue;
}

int findTop(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList)
{
  int topValue = inRect->top;
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  int closest = 1024;
  int spread = 0;
  CvPoint point;
  point.x = inRect->left;
  point.y = inRect->top;

  for (iter=inRectList.begin(); iter!=inRectList.end(); iter++)
  {
    rectangle = (*iter);

    if (rectangle->area() > requiredArea)
    {
      if (isBoundByRectangle(point, rectangle, 1))
      {
        spread = inRect->top - rectangle->bottom;

        if ((spread >= 0) && (spread < closest))
        {
          closest = spread;
          topValue = rectangle->bottom;
        }
      }
    }
  }

  return topValue;
}

int findBottom(BoundingRectangle* inRect, list<BoundingRectangle*> inRectList)
{
  int bottomValue = inRect->bottom;
  BoundingRectangle* rectangle;
  list<BoundingRectangle*>::iterator iter;
  int closest = 1024;
  int spread = 0;
  CvPoint point;
  point.x = inRect->left;
  point.y = inRect->top;

  for (iter=inRectList.begin(); iter!=inRectList.end(); iter++)
  {
    rectangle = (*iter);

    if (rectangle->area() > requiredArea)
    {
      if (isBoundByRectangle(point, rectangle, 1))
      {
        spread = rectangle->top - inRect->bottom;

        if ((spread >= 0) && (spread < closest))
        {
          closest = spread;
          bottomValue = rectangle->top;
        }
      }
    }
  }

  return bottomValue;
}

