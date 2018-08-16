#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "mergeRectList.h"

list<BoundingRectangle*> combineTouchingRectangles(list<BoundingRectangle*> inRectList, int inTolerance)
{
  int currentSize = inRectList.size() + 1;
  printf("Combine Touching Rectangles ...\n");
  while (inRectList.size() < currentSize) 
  {
    currentSize = inRectList.size();
    inRectList = combineCloseRects(inRectList, inTolerance);
  }
  printf("After Combine Processing: %d\n\n", (int)inRectList.size());

  return inRectList;
}

list<BoundingRectangle*> combineCloseRects(list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*> touchingList;
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* loopRectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    loopRectangle = (*iter);
    touchingList = getTouchingRects(loopRectangle, inRectangleList, inTolerance);
    if (touchingList.size() > 0)
      break;
  }

  if (0 == touchingList.size())
    return inRectangleList;

  touchingList.push_back(loopRectangle);

  returnList = removeListFromList(inRectangleList, touchingList);

  BoundingRectangle* newRect = combineRectList(loopRectangle, touchingList);

  returnList.push_back(newRect);

  return returnList;
}

list<BoundingRectangle*> removeListFromList(list<BoundingRectangle*> inRectangleList,
                                        list<BoundingRectangle*> inRemoveRectList)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* rectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    rectangle = (*iter);
    if (! isRectangleInList(rectangle, inRemoveRectList))
    {
      returnList.push_back(rectangle);
    }
  }

  return returnList;
}

list<BoundingRectangle*> getTouchingRects(BoundingRectangle* inRectangle,
                                          list<BoundingRectangle*> inRectangleList,
                                          int inTolerance)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*>::iterator iter;

  BoundingRectangle* loopRectangle;
  BoundingRectangle* rectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    loopRectangle = (*iter);

    if (NULL != (rectangle = isTouchingRectangle(inRectangle, loopRectangle, inTolerance)))
    {
      returnList.push_back(loopRectangle);
    }
  }

  return returnList;
}

BoundingRectangle* isTouchingRectangle(BoundingRectangle* inRect1,
                       BoundingRectangle* inRect2,
                       int inTolerance)
{
    if (! inRect1->equals(inRect2))
    {
      if ((isNear(inRect1->top, inRect2->top, inTolerance)) &&
          (isNear(inRect1->left, inRect2->right, inTolerance))) 
         return inRect2;

      if ((isNear(inRect1->bottom, inRect2->bottom, inTolerance)) &&
          (isNear(inRect1->left, inRect2->right, inTolerance)))
         return inRect2;

      if ((isNear(inRect1->left, inRect2->left, inTolerance)) &&
          (isNear(inRect1->top, inRect2->bottom, inTolerance)))
         return inRect2;

      if ((isNear(inRect1->right, inRect2->right, inTolerance)) &&
          (isNear(inRect1->top, inRect2->bottom, inTolerance)))
         return inRect2;

      if ((isNear(inRect1->bottom, inRect2->bottom, inTolerance)) &&
          (inRect1->left < inRect2->left) && (inRect1->right > inRect2->right))
         return inRect2;

      if ((isNear(inRect1->top, inRect2->top, inTolerance)) &&
          (inRect1->left < inRect2->left) && (inRect1->right > inRect2->right))
         return inRect2;

      if ((isNear(inRect1->left, inRect2->left, inTolerance)) &&
          (inRect1->top < inRect2->top) && (inRect1->bottom > inRect2->bottom))
         return inRect2;

      if ((isNear(inRect1->right, inRect2->right, inTolerance)) &&
          (inRect1->top < inRect2->top) && (inRect1->bottom > inRect2->bottom))
         return inRect2;
    }

  return NULL;
}

list<BoundingRectangle*> eliminateOverlaps(list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  list<BoundingRectangle*> returnList;

  returnList = getNonOverlappedRectList(inRectangleList, inTolerance);
  returnList.sort(compareTopLeft);
  returnList.unique(sameRectangle);

  return returnList;
}

list<BoundingRectangle*> getNonOverlappedRectList(list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*>::iterator iter;

  BoundingRectangle* thisRectangle;
  BoundingRectangle* rectangle;
  BoundingRectangle* newRectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    thisRectangle = (*iter);

    if (NULL != (rectangle = findOverlappedByRectangle(thisRectangle, inRectangleList, inTolerance)))
    {
      newRectangle = combineRectangles(thisRectangle, rectangle);
      returnList.push_back(newRectangle);
    }
    else
    {
      returnList.push_back(thisRectangle);
    }
  }

  return returnList;
}

BoundingRectangle*  findOverlappedByRectangle(BoundingRectangle* inRectangle,
                       list<BoundingRectangle*> inRectangleList,
                       int inTolerance)
{
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* boundingRect;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    boundingRect = (*iter);

    if (! inRectangle->equals(boundingRect))
    {
      if (isBoundByRectangle(inRectangle->topLeft(), boundingRect, inTolerance))
        return boundingRect;

      if (isBoundByRectangle(inRectangle->topRight(), boundingRect, inTolerance))
        return boundingRect;

      if (isBoundByRectangle(inRectangle->bottomLeft(), boundingRect, inTolerance))
        return boundingRect;

      if (isBoundByRectangle(inRectangle->bottomRight(), boundingRect, inTolerance))
        return boundingRect;
    }
  }

  return NULL;
}

