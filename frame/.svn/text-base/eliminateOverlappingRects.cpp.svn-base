#include "pyramid.h"
#include "utils.h"
#include "BoundingRectangle.h"
#include "eliminateOverlappingRects.h"

list<BoundingRectangle*> eliminateOverlappingRectangles(list<BoundingRectangle*> inRectList, int inTolerance)
{
  int currentSize = inRectList.size() + 1;
  printf("Eliminate Overlapping Rectangles ...\n");
  while (inRectList.size() < currentSize) 
  {
    currentSize = inRectList.size();
    inRectList = eliminateOverlappingRects(inRectList, inTolerance);
  }
  printf("After Overlap Processing: %d\n\n", (int)inRectList.size());

  return inRectList;
}

list<BoundingRectangle*> eliminateOverlappingRects(list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*> overlappingList;
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* loopRectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    loopRectangle = (*iter);
    overlappingList = getOverlappingRects(loopRectangle, inRectangleList, inTolerance);
    if (overlappingList.size() > 0)
      break;
  }

  if (0 == overlappingList.size())
    return inRectangleList;

  overlappingList.push_back(loopRectangle);

  returnList = removeListFromList(inRectangleList, overlappingList);

  BoundingRectangle* newRect = combineRectList(loopRectangle, overlappingList);
  returnList.push_back(newRect);

  return returnList;
}

list<BoundingRectangle*> getOverlappingRects(BoundingRectangle* inRectangle,
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

    if (NULL != (rectangle = isOverlappingRectangle(loopRectangle, inRectangle, inTolerance)))
    {
      returnList.push_back(loopRectangle);
    }
  }

  return returnList;
}

BoundingRectangle* isOverlappingRectangle(BoundingRectangle* inRect1,
                                          BoundingRectangle* inRect2,
                                          int inTolerance)
{
    if (! inRect1->equals(inRect2))
    {
      if (inRect2->pointIn(inRect1->left, inRect1->top, inTolerance))
         return inRect1;

      if (inRect2->pointIn(inRect1->right, inRect1->top, inTolerance))
         return inRect1;

      if (inRect2->pointIn(inRect1->left, inRect1->bottom, inTolerance))
         return inRect1;

      if (inRect2->pointIn(inRect1->right, inRect1->bottom, inTolerance))
         return inRect1;
    }

  return NULL;
}


