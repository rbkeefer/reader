#include "pyramid.h"
#include "utils.h"
#include "BoundingRectangle.h"
#include "combineTouchingRects.h"

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


