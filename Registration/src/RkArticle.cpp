/*
 * RkArticle.cpp
 *
 */

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkUtils.h"
#include "RkArticle.h"

bool compareTextLeftRight(RkSegment* first, RkSegment* second)
{
  if (first->boundingRectangle->left < second->boundingRectangle->left)
	  return true;

  return false;
}


RkArticle::RkArticle() {

}

RkArticle::~RkArticle() {
	// Do Nothing for now
}

RkBoundingRectangle* RkArticle::boundingRectangle() {
  list<RkSegment*>::iterator columnIter;
  RkBoundingRectangle* rectangle = new RkBoundingRectangle(headline->boundingRectangle);

  for (columnIter=columns.begin(); columnIter!=columns.end(); columnIter++)
  {
    rectangle->join((*columnIter)->boundingRectangle);
  }

  return rectangle;
}

int RkArticle::height() {
	return boundingRectangle()->height();
}

int RkArticle::width() {
	return boundingRectangle()->width();
}

int RkArticle::numberOfColumns() {
	return columns.size();
}

int RkArticle::distBetweenColumns() {
  if (columns.size() < 2)
	  return 0;

  columns.sort(compareTextLeftRight);

  RkBoundingRectangle* leftRectangle;
  RkBoundingRectangle* rightRectangle;
  int distanceBetweenColumns = 0;
  list<RkSegment*>::iterator columnIter = columns.begin();
  leftRectangle = (*columnIter)->boundingRectangle;columnIter++;

  while (columnIter!=columns.end())
  {
    rightRectangle = (*columnIter)->boundingRectangle;
    distanceBetweenColumns =  distanceBetweenColumns + (rightRectangle->left - leftRectangle->right);
    leftRectangle = (*columnIter)->boundingRectangle; columnIter++;
  }

  return distanceBetweenColumns/(columns.size()-1);
}

void RkArticle::info() {
  RkBoundingRectangle* rect = boundingRectangle();
  printf("[%d,%d,%d,%d] [%d, %d]  %d  %d",
		  rect->top, rect->left, rect->bottom, rect->right,
		  height(), width(), numberOfColumns(), distBetweenColumns());

}

void RkArticle::toString() {
  printf("\nArticle: [%d, %d]  %d  %d\n", height(), width(), numberOfColumns(), distBetweenColumns());
  printf("(%d, %d, %d, %d)\n",
		headline->boundingRectangle->top,
		headline->boundingRectangle->left,
		headline->boundingRectangle->bottom,
		headline->boundingRectangle->right);

  list<RkSegment*>::iterator columnIter;
  for (columnIter=columns.begin(); columnIter!=columns.end(); columnIter++)
  {
	  printf("     (%d, %d, %d, %d)\n",
			(*columnIter)->boundingRectangle->top,
			(*columnIter)->boundingRectangle->left,
			(*columnIter)->boundingRectangle->bottom,
			(*columnIter)->boundingRectangle->right);
  }
}

void RkArticle::printString(FILE* inFile) {
  fprintf(inFile, "%d,%d,%d,%d,%d\n",
		  headline->boundingRectangle->top,
		  headline->boundingRectangle->left,
		  headline->boundingRectangle->bottom,
		  headline->boundingRectangle->right,
		  (int) columns.size());

  list<RkSegment*>::iterator columnIter;
  for (columnIter=columns.begin(); columnIter!=columns.end(); columnIter++)
  {
	fprintf(inFile, "%d,%d,%d,%d\n",
			(*columnIter)->boundingRectangle->top,
			(*columnIter)->boundingRectangle->left,
			(*columnIter)->boundingRectangle->bottom,
			(*columnIter)->boundingRectangle->right);
  }
}
