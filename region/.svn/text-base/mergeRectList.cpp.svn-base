#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "mergeRectList.h"


list<BoundingRectangle*> combineCloseRects(list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  list<BoundingRectangle*> returnList;

  returnList = getSeparatedRectList(inRectangleList, inTolerance);
  returnList.sort(compareTopLeft);
  returnList.unique(sameRectangle);

  return returnList;
}

list<BoundingRectangle*> getSeparatedRectList(list<BoundingRectangle*> inRectangleList, int inTolerance)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*>::iterator iter;

  BoundingRectangle* thisRectangle;
  BoundingRectangle* rectangle;
  BoundingRectangle* newRectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    thisRectangle = (*iter);

    if (NULL != (rectangle = findCloseRectangle(thisRectangle, inRectangleList, inTolerance)))
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

BoundingRectangle*  findCloseRectangle(BoundingRectangle* inRectangle,
                       list<BoundingRectangle*> inRectangleList,
                       int inTolerance)
{
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* compareRect;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    compareRect = (*iter);

    if (! inRectangle->equals(compareRect))
    {
      if ((inRectangle->top < compareRect->top) && 
          (inRectangle->bottom > compareRect->bottom) &&
          ((inRectangle->left-inTolerance <= compareRect->right) &&
           (inRectangle->left-inTolerance >= compareRect->left)))
        return compareRect;

      if ((inRectangle->top < compareRect->top) && 
          (inRectangle->bottom > compareRect->bottom) &&
          ((inRectangle->right+inTolerance >= compareRect->left) &&
           (inRectangle->right+inTolerance <= compareRect->right)))
        return compareRect;

      if ((inRectangle->left < compareRect->left) && 
          (inRectangle->right > compareRect->right) &&
          ((inRectangle->top-inTolerance <= compareRect->bottom) &&
           (inRectangle->top-inTolerance >= compareRect->top)))
        return compareRect;

      if ((inRectangle->left < compareRect->left) && 
          (inRectangle->right > compareRect->right) &&
          ((inRectangle->bottom+inTolerance >= compareRect->top) &&
           (inRectangle->bottom+inTolerance <= compareRect->bottom)))
        return compareRect;
    }
  }

  return NULL;
}
list<BoundingRectangle*> eliminateOverlaps(list<BoundingRectangle*> inRectangleList)
{
  list<BoundingRectangle*> returnList;

  returnList = getNonOverlappedRectList(inRectangleList);
  returnList.sort(compareTopLeft);
  returnList.unique(sameRectangle);

  return returnList;
}

list<BoundingRectangle*> getNonOverlappedRectList(list<BoundingRectangle*> inRectangleList)
{
  list<BoundingRectangle*> returnList;
  list<BoundingRectangle*>::iterator iter;

  BoundingRectangle* thisRectangle;
  BoundingRectangle* rectangle;
  BoundingRectangle* newRectangle;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    thisRectangle = (*iter);

    if (NULL != (rectangle = findOverlappedByRectangle(thisRectangle, inRectangleList)))
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
                       list<BoundingRectangle*> inRectangleList)
{
  list<BoundingRectangle*>::iterator iter;
  BoundingRectangle* boundingRect;

  for (iter=inRectangleList.begin(); iter!=inRectangleList.end(); iter++)
  {
    boundingRect = (*iter);

    if (! inRectangle->equals(boundingRect))
    {
      if (isBoundByRectangle(inRectangle->topLeft(), boundingRect, 0))
        return boundingRect;

      if (isBoundByRectangle(inRectangle->topRight(), boundingRect, 0))
        return boundingRect;

      if (isBoundByRectangle(inRectangle->bottomLeft(), boundingRect, 0))
        return boundingRect;

      if (isBoundByRectangle(inRectangle->bottomRight(), boundingRect, 0))
        return boundingRect;
    }
  }

  return NULL;
}

