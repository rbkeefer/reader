#include "pyramid.h"
#include "utils.h"
#include "BoundingRectangle.h"
#include "combineRects.h"

BoundingRectangle* isInSameRectangle(BoundingRectangle* inRect1, BoundingRectangle* inRect2, int inTolerance);
BoundingRectangle* combineColumnarRects(BoundingRectangle* inRect1, BoundingRectangle* inRect2, int inTolerance);
BoundingRectangle* combineRowRects(BoundingRectangle* inRect1, BoundingRectangle* inRect2, int inTolerance);

list<BoundingRectangle*> combineRectangles(list<BoundingRectangle*> inRectList, int inTolerance)
{
  int currentSize = inRectList.size() + 1;
  printf("Combine Similar Rectangles ...\n");
  while (inRectList.size() < currentSize) 
  {
    currentSize = inRectList.size();
    inRectList = combineSimilarRects(inRectList, inTolerance);
  }
  printf("After Combine Processing: %d\n\n", (int)inRectList.size());

  return inRectList;
}

list<BoundingRectangle*> combineSimilarRects(list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*> similarList;
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* loopRectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    loopRectangle = (*iter);
    similarList = getRectsToCombine(loopRectangle, inRectangleList, inTolerance);
    if (similarList.size() > 0)
      break;
  }

  if (0 == similarList.size())
    return inRectangleList;

  similarList.push_back(loopRectangle);

  returnList = removeListFromList(inRectangleList, similarList);

  BoundingRectangle* newRect = combineRectList(loopRectangle, similarList);
  returnList.push_back(newRect);

  return returnList;
}

list<BoundingRectangle*> getRectsToCombine(BoundingRectangle* inRectangle,
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

    if (NULL != (rectangle = isSimilarRectangle(inRectangle, loopRectangle, inTolerance)))
    {
      returnList.push_back(loopRectangle);
    }
  }

  return returnList;
}

BoundingRectangle* isSimilarRectangle(BoundingRectangle* inRect1,
                       BoundingRectangle* inRect2,
                       int inTolerance)
{
  if (inRect1->equals(inRect2))
    return NULL;

  if ((inRect1->isColumnShape()) && (isInSameRectangle(inRect1, inRect2, inTolerance)))
    return combineColumnarRects(inRect1, inRect2, inTolerance);

  if ((inRect1->isRowShape()) && (isInSameRectangle(inRect1, inRect2, inTolerance)))
    return combineRowRects(inRect1, inRect2, inTolerance);

  return NULL;
}

BoundingRectangle* combineColumnarRects(BoundingRectangle* inRect1,
                       BoundingRectangle* inRect2,
                       int inTolerance)
{
  if (inRect1->top >= inRect2->top)
  {
    if ((inRect1->left >= inRect2->left) &&
        (inRect1->right <= inRect2->right))
    {
      return inRect2;
    }
  }

  return NULL;
}

BoundingRectangle* combineRowRects(BoundingRectangle* inRect1,
                       BoundingRectangle* inRect2,
                       int inTolerance)
{
  if (inRect1->left >= inRect2->left)
  {
    if ((inRect1->top >= inRect2->top) &&
        (inRect1->bottom <= inRect2->bottom))
    {
      return inRect2;
    }
  }

  return NULL;
}

BoundingRectangle* isCloseRectangle(BoundingRectangle* inRect1,
                       BoundingRectangle* inRect2,
                       int inTolerance)
{
  // Find Rectangles that Share Corners
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

  // Find Rectangles that Share Sides
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

  return isInSameRectangle(inRect1, inRect2, inTolerance);
}

BoundingRectangle* isInSameRectangle(BoundingRectangle* inRect1,
                       BoundingRectangle* inRect2,
                       int inTolerance)
{
  // Find Overlapping Rectangles
  if (inRect2->pointIn(inRect1->left, inRect1->top, inTolerance))
    return inRect1;

  if (inRect2->pointIn(inRect1->right, inRect1->top, inTolerance))
    return inRect1;

  if (inRect2->pointIn(inRect1->left, inRect1->bottom, inTolerance))
    return inRect1;

  if (inRect2->pointIn(inRect1->right, inRect1->bottom, inTolerance))
    return inRect1;

  return NULL;
}


