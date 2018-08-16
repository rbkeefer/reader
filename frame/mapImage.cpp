#include <list>
#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "mapImage.h"
using namespace std;

BoundingRectangle* findMappedRegion(BoundingRectangle* inBoundingRect, int inRegionSize);

list<BoundingRectangle*> mapImage(list<BoundingRectangle*> inBoundingRectList)
{
  list<BoundingRectangle*> boundingRectList; 
  BoundingRectangle* boundingRect;

  printf("Map Image ...\n");

  list<BoundingRectangle*>::iterator iter;
  for (iter=inBoundingRectList.begin(); iter!=inBoundingRectList.end(); iter++)
  {
     boundingRect = findMappedRegion(*iter, BOX_SIZE);
     boundingRectList.push_back(boundingRect);
  }

  return boundingRectList;
}

BoundingRectangle* findMappedRegion(BoundingRectangle* inBoundingRect, int inRegionSize)
{
  BoundingRectangle* boundingRect = new BoundingRectangle();
  int columnCounter, rowCounter;
  int rectRow, rectColumn;

  int thisRow, thisColumn;

  thisRow = inRegionSize*inBoundingRect->top;
  thisColumn = inRegionSize*inBoundingRect->left;
  boundingRect->top = thisRow;
  boundingRect->left = thisColumn;

  thisRow = inRegionSize*inBoundingRect->bottom+1;
  thisColumn = inRegionSize*inBoundingRect->right+1;
  boundingRect->bottom = thisRow;
  boundingRect->right = thisColumn;

  return boundingRect;
}

