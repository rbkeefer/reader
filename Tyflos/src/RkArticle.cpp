/*
 * RkArticle.cpp
 *
 */
#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkArticle.h"

RkArticle::RkArticle() {
	headline = NULL;
}

RkArticle::~RkArticle() {
  if (NULL != headline)
    free(headline);

  if (columns.size() > 0)
  {
    list<RkSegment*>::iterator columnIter;
    for (columnIter=columns.begin();
         columnIter!=columns.end();
         columnIter++)
      free(*columnIter);
  }
}

RkBoundingRectangle* RkArticle::boundingRectangle() {

  if ((NULL == headline) && (columns.size() == 0)) return NULL;

  RkBoundingRectangle* rectangle;
  list<RkSegment*>::iterator columnIter;

  if ((NULL != headline) && (NULL != headline->boundingRectangle))
    rectangle = new RkBoundingRectangle(headline->boundingRectangle);
  else
	rectangle = new RkBoundingRectangle((columns.front())->boundingRectangle);

  for (columnIter=columns.begin(); columnIter!=columns.end(); columnIter++)
  {
    rectangle->join((*columnIter)->boundingRectangle);
  }

  return rectangle;
}

void RkArticle::join(RkArticle* inArticle)
{
  list<RkSegment*>::iterator columnIter;
  for (columnIter=(inArticle->columns).begin(); columnIter!=(inArticle->columns).end(); columnIter++)
	columns.push_back((*columnIter));
}

bool RkArticle::equals(RkArticle* inArticle)
{
  if (columns.size() != (inArticle->columns).size()) return false;
  if ((boundingRectangle()->area()) != (inArticle->boundingRectangle())->area()) return false;

  return true;
}

void RkArticle::toString()
{
  if ((NULL != headline) && (NULL!= headline->boundingRectangle))
    printf("(%d, %d, %d, %d)\n",
		headline->boundingRectangle->top,
		headline->boundingRectangle->left,
		headline->boundingRectangle->bottom,
		headline->boundingRectangle->right);
  else
   printf("(0, 0, 0, 0)\n");

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
  if ((NULL != headline) && (NULL!= headline->boundingRectangle))
    fprintf(inFile, "%d,%d,%d,%d,%d\n",
		  headline->boundingRectangle->top,
		  headline->boundingRectangle->left,
		  headline->boundingRectangle->bottom,
		  headline->boundingRectangle->right,
		  (int) columns.size());
  else
   fprintf(inFile, "0,0,0,0,%d\n", (int) columns.size());

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
