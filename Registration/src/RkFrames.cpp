/*
 * RkFrames.cpp
 *
 */

#include "Registration.h"
#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkArticle.h"
#include "RkUtils.h"


list<RkSegment*> getSegments(list<RkSegment*> inSegmentList, int inType)
{
  list<RkSegment*> segmentList;
  list<RkSegment*>::iterator segmentIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	if ((*segmentIter)->segmentType == inType)
	  segmentList.push_back((*segmentIter));
  }

  return segmentList;
}

bool similarHeight(RkBoundingRectangle* inRect1, RkBoundingRectangle* inRect2, int inTolerance)
{
  if ((inRect1->height()+inTolerance >= inRect2->height()) &&
      (inRect2->height()+inTolerance >= inRect1->height()))
	  return true;

  return false;
}

RkBoundingRectangle* groupHorizontalSegments(RkSegment* inSegment, list<RkSegment*> inSegmentList, int inTolerance)
{
  bool testedAllSegments = false;
  RkBoundingRectangle* rectangle;

  RkBoundingRectangle* baseRectangle = inSegment->boundingRectangle;

  if (inSegmentList.size() > 0)
  {
	  int baseArea = baseRectangle->area() - 1;
	  list<RkSegment*>::iterator segmentIter=inSegmentList.begin();

	  while (! ((baseArea == baseRectangle->area()) && (testedAllSegments)))
	  {
		testedAllSegments = false;
		baseArea = baseRectangle->area();
		rectangle = (*segmentIter)->boundingRectangle;

		if (baseRectangle->isNear(rectangle))
		  baseRectangle->join(rectangle);

		if (baseRectangle->isRight(rectangle))
		{
		  if (baseRectangle->isNear(rectangle, inTolerance))
		  {
			if (similarHeight(baseRectangle, rectangle, inTolerance))
			  baseRectangle->join(rectangle);
		  }
		}

		if (baseRectangle->isLeft(rectangle))
		{
		  if (baseRectangle->isNear(rectangle, inTolerance))
		  {
			if (similarHeight(baseRectangle, rectangle, inTolerance))
			  baseRectangle->join(rectangle);
		  }
		}

	    segmentIter++;

		if (segmentIter == inSegmentList.end())
		{
		  segmentIter = inSegmentList.begin();
		  testedAllSegments = true;
		}
	  }
  }
  return baseRectangle;
}

RkSegment* getLargestSegment(list<RkSegment*> inSegmentList)
{
  RkSegment* segment;
  RkSegment* largestSegment = NULL;
  list<RkSegment*>::iterator segmentIter;
  int largestArea = 0;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	segment = (*segmentIter); if (NULL == largestSegment) largestSegment = segment;
	if (largestArea < segment->boundingRectangle->area())
	{
		largestSegment = segment;
		largestArea = largestSegment->boundingRectangle->area();
	}
  }

  return largestSegment;
}

RkBoundingRectangle* groupVerticleSegments(RkSegment* inSegment, list<RkSegment*> inSegmentList, int inTolerance)
{
  bool testedAllSegments = false;
  RkBoundingRectangle* rectangle;

  RkBoundingRectangle* baseRectangle = inSegment->boundingRectangle;

  if (inSegmentList.size() > 0)
  {
	  int baseArea = baseRectangle->area() - 1;
	  list<RkSegment*>::iterator segmentIter=inSegmentList.begin();

	  while (! ((baseArea == baseRectangle->area()) && (testedAllSegments)))
	  {
		testedAllSegments = false;
		baseArea = baseRectangle->area();
		rectangle = (*segmentIter)->boundingRectangle;

		if (baseRectangle->isVerticalOverlap(rectangle))
		  baseRectangle->join(rectangle);

		if (baseRectangle->isAbove(rectangle))
		{
		  if (baseRectangle->isNear(rectangle, inTolerance))
			baseRectangle->join(rectangle);
		}

		if (baseRectangle->isBelow(rectangle))
		{
		  if (baseRectangle->isNear(rectangle, inTolerance))
			baseRectangle->join(rectangle);
		}

		segmentIter++;

		if (segmentIter == inSegmentList.end())
		{
		  segmentIter = inSegmentList.begin();
		  testedAllSegments = true;
		}
	  }
  }
  return baseRectangle;
}

bool isSegmentInSegmentList(RkSegment* inSegment, list<RkSegment*> inSegmentList)
{
  RkSegment* segment;
  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
    segment = (*segmentIter);
    if (segment->boundingRectangle->isRectIn(inSegment->boundingRectangle)) return true;
  }

  return false;
}

list<RkSegment*> groupHeadlines(list<RkSegment*> inSegmentList)
{
  RkSegment* segment;
  RkSegment* headline;
  list<RkSegment*> headlines;
  list<RkSegment*> outHeadlines;
  list<RkSegment*>::iterator segmentIter;
  list<RkSegment*>::iterator headlineIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	segment = (*segmentIter);
	if (! isSegmentInSegmentList(segment, headlines))
	{
	  headline = new RkSegment(groupVerticleSegments(segment, inSegmentList, 20), 1);
	  headline->boundingRectangle = groupHorizontalSegments(headline, inSegmentList, 4);
	  headlines.push_back(headline);
	}
  }

  headlines.reverse();
  for (headlineIter=headlines.begin(); headlineIter!=headlines.end(); headlineIter++)
  {
	segment = (*headlineIter);
	segment->boundingRectangle->toString();
	if (! isSegmentInSegmentList(segment, outHeadlines))
	{
	  headline = new RkSegment(groupVerticleSegments(segment, headlines, 8), 1);
	  headline->boundingRectangle = groupHorizontalSegments(headline, headlines, 8);
	  outHeadlines.push_back(headline);
	}
  }

  return outHeadlines;
}

list<RkSegment*> groupTextColumns(list<RkSegment*> inSegmentList)
{
  RkSegment* segment;
  RkSegment* text;
  list<RkSegment*> textColumn;
  list<RkSegment*> columnList;
  list<RkSegment*>::iterator segmentIter;
  list<RkSegment*>::iterator textIter;

  for (segmentIter=inSegmentList.begin(); segmentIter!=inSegmentList.end(); segmentIter++)
  {
	segment = (*segmentIter);
	if (! isSegmentInSegmentList(segment, textColumn))
	{
	  text = new RkSegment(groupVerticleSegments(segment, inSegmentList, 4), 2);
	  textColumn.push_back(text);
	}
  }

  textColumn.reverse();
  for (segmentIter=textColumn.begin(); segmentIter!=textColumn.end(); segmentIter++)
  {
	segment = (*segmentIter);
	if (! isSegmentInSegmentList(segment, columnList))
	{
	  text = new RkSegment(groupVerticleSegments(segment, columnList, 6), 2);
	  columnList.push_back(text);
	}
  }

  return columnList;
}

bool isColumnWithHeadline(RkSegment* inColumn, RkSegment* inHeadline, list<RkSegment*> inHeadlineList)
{
  int difference = inColumn->boundingRectangle->top - inHeadline->boundingRectangle->bottom;
  int compare = difference;

  RkSegment* headline;
  list<RkSegment*>::iterator headlineIter;
  for (headlineIter=inHeadlineList.begin(); headlineIter!=inHeadlineList.end(); headlineIter++)
  {
	headline = (*headlineIter);
    if ((headline->boundingRectangle)->isBelow(inColumn->boundingRectangle))
    	compare = inColumn->boundingRectangle->top - headline->boundingRectangle->bottom;
    if (compare < difference) difference = compare;
  }

  if (difference == inColumn->boundingRectangle->top - inHeadline->boundingRectangle->bottom)
	  return true;

  return false;
}

list<RkArticle*> groupArticles(list<RkSegment*> inSegmentList)
{
  RkArticle* article;
  list<RkArticle*> articleList;

  list<RkSegment*> headlineSegments = getSegments(inSegmentList, 1);
  list<RkSegment*> headlineList = groupHeadlines(headlineSegments);

  list<RkSegment*> textSegments = getSegments(inSegmentList, 2);
  list<RkSegment*> columnList = groupTextColumns(textSegments);

  RkSegment* headline;
  RkSegment* columnSegment;
  list<RkSegment*>::iterator columnIter;
  list<RkSegment*>::iterator headlineIter;

  for (headlineIter=headlineList.begin(); headlineIter!=headlineList.end(); headlineIter++)
  {
	headline = (*headlineIter);
	article = new RkArticle();
	article->headline = headline;
	for (columnIter=columnList.begin(); columnIter!=columnList.end(); columnIter++)
	{
		columnSegment = (*columnIter);
		if ((headline->boundingRectangle)->isBelow(columnSegment->boundingRectangle))
		{
			if (isColumnWithHeadline(columnSegment, headline, headlineList))
				(article->columns).push_back(columnSegment);
		}
	}

	articleList.push_back(article);
  }

  return articleList;
}

