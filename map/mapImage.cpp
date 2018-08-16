#include <list>
#include "pyramid.h"
#include "BoundingRectangle.h"
#include "utils.h"
#include "mapImage.h"
using namespace std;

BoundingRectangle* finMappedRectangle(BoundingRectangle* inBoundingRect);

list<BoundingRectangle*> mapImage(list<BoundingRectangle*> inBoundingRectList)
{
  list<BoundingRectangle*> boundingRectList; 
  BoundingRectangle* boundingRect;

  printf("Map Image ...\n");

  list<BoundingRectangle*>::iterator iter;
  for (iter=inBoundingRectList.begin(); iter!=inBoundingRectList.end(); iter++)
  {
     boundingRect = finMappedRectangle(*iter);
     boundingRectList.push_back(boundingRect);
  }

  return boundingRectList;
}

BoundingRectangle* finMappedRectangle(BoundingRectangle* inBoundingRect)
{
  BoundingRectangle* boundingRect = new BoundingRectangle();

  boundingRect->top = BOX_SIZE*inBoundingRect->top;
  boundingRect->left = BOX_SIZE*inBoundingRect->left;

  boundingRect->bottom = BOX_SIZE*inBoundingRect->bottom+1;
  boundingRect->right = BOX_SIZE*inBoundingRect->right+1;

  return boundingRect;
}

