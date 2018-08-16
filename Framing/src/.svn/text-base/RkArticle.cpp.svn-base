/*
 * RkArticle.cpp
 *
 */

#include "RkArticle.h"

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

void RkArticle::toString() {
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
