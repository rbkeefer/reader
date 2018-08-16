#include "Reader.h"

#include "RkBoundingRectangle.h"
#include "RkSegment.h"
#include "RkArticle.h"

#include "Utils.h"
#include "Frame.h"

int HEADLINE_VERTICAL_DISTANCE = 40;
int HEADLINE_HORIZONTAL_DISTANCE = 6;

void doFraming(int inDemoMode, int inRunMode, int inIllumination, int inReduction,
		string* inImageFileName, IplImage* inOrigImage, IplImage* inCleanedImage)
{
  printf("\nBegin Framing\n");

  IplImage* segmentImg;
  IplImage* articleImg;

  string* inFileName = new string(*inImageFileName);
  inFileName->append(".Classified.txt");
  string* outFileName = new string(*inImageFileName);
  outFileName->append(".Framed.txt");

  list<RkSegment*> segmentList = getClassifiedSegmentList(inFileName);

  segmentImg = cvCreateImage(cvSize(inOrigImage->width, inOrigImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inOrigImage, inOrigImage, inOrigImage, NULL, segmentImg);
  segmentImg = displayBoundaries(segmentImg, segmentList, THIN_LINE);
  cvNamedWindow("Segments", CV_WINDOW_AUTOSIZE);
  cvShowImage("Segments", segmentImg);

  list<RkArticle*> articleList = groupArticles(segmentList);

  articleImg = cvCreateImage(cvSize(inOrigImage->width, inOrigImage->height), IPL_DEPTH_8U, 3);
  cvMerge(inOrigImage, inOrigImage, inOrigImage, NULL, articleImg);
  articleImg = displayBoundaries(articleImg, articleList, THICK_LINE);
  cvNamedWindow("Articles", CV_WINDOW_AUTOSIZE);
  cvShowImage("Articles", articleImg);

  string* saveImgFileName = new string(*inImageFileName);
  saveImgFileName->append(".framed.jpg");
  cvSaveImage(saveImgFileName->c_str(), articleImg);

  cvWaitKey(0);

  cvReleaseImage(&segmentImg);
  cvDestroyWindow("Segments");

  cvReleaseImage(&articleImg);
  cvDestroyWindow("Articles");

  list<RkSegment*>::iterator segmentIter;
  for (segmentIter=segmentList.begin(); segmentIter!=segmentList.end(); segmentIter++)
	free(*segmentIter);

  list<RkArticle*>::iterator articleIter;
  for (articleIter=articleList.begin(); articleIter!=articleList.end(); articleIter++)
	free(*articleIter);

  free(inFileName);
  free(outFileName);
}

list<RkArticle*> groupArticles(list<RkSegment*> inSegmentList)
{
  RkArticle* article;
  list<RkArticle*> articleList;
  list<RkArticle*> finalArticleList;

  list<RkSegment*> headlineSegments = getTypedSegments(inSegmentList, HEADLINE_TYPE);
  list<RkSegment*> headlineList = groupHeadlines(headlineSegments);

  list<RkSegment*> textSegments = getTypedSegments(inSegmentList, CONTENT_TYPE);
  list<RkSegment*> textColumnList = groupTextColumns(textSegments);

  RkSegment* headline;
  RkSegment* columnSegment;
  list<RkSegment*>::iterator columnIter;
  list<RkSegment*>::iterator headlineIter;

  for (headlineIter=headlineList.begin(); headlineIter!=headlineList.end(); headlineIter++)
  {
	headline = (*headlineIter);
	article = new RkArticle();
	article->headline = headline;
	for (columnIter=textColumnList.begin(); columnIter!=textColumnList.end(); columnIter++)
	{
		columnSegment = (*columnIter);
		if ((headline->boundingRectangle)->isBelow(columnSegment->boundingRectangle))
		{
			if (isColumnWithHeadline(columnSegment, headline, headlineList))
				(article->columns).push_back(columnSegment);
		}
		else if ((columnSegment->boundingRectangle)->isAbove(headline->boundingRectangle))
		{
			if (isColumnWithHeadline(columnSegment, headline, headlineList))
				(article->columns).push_back(columnSegment);
		}
	}

	articleList.push_back(article);
  }

  bool found = false;
  list<RkArticle*>::iterator articleIter;
  for (columnIter=textColumnList.begin(); columnIter!=textColumnList.end(); columnIter++)
  {
	  columnSegment = (*columnIter);
	  found = false;
	  for (articleIter=articleList.begin(); articleIter!=articleList.end(); articleIter++)
	  {
		  if (isSegmentInSegmentList(columnSegment, (*articleIter)->columns))
		  {
			  found = true;
			  break;
		  }
	  }

	  if (! found)
	  {
		article = new RkArticle();
		(article->columns).push_back(columnSegment);
		articleList.push_back(article);
	  }
  }

  RkArticle* finalArticle;
  for (articleIter=articleList.begin(); articleIter!=articleList.end(); articleIter++)
  {
	article = (*articleIter);
	if (! isArticleInArticleList(article, finalArticleList))
	{
	  finalArticle = groupArticles(article, articleList);
	  finalArticleList.push_back(finalArticle);
	}
  }

  return finalArticleList;
}

RkArticle* groupArticles(RkArticle* inArticle, list<RkArticle*> inArticleList)
{
  bool testedAllArticles = false;
  RkBoundingRectangle* rectangle;

  if (inArticleList.size() > 0)
  {
	  int baseArea = (inArticle->boundingRectangle())->area() - 1;
	  list<RkArticle*>::iterator articleIter = inArticleList.begin();

	  while (! ((baseArea == (inArticle->boundingRectangle())->area()) && (testedAllArticles)))
	  {
		testedAllArticles = false;
		rectangle = (*articleIter)->boundingRectangle();
		baseArea = (inArticle->boundingRectangle())->area();

		if (! inArticle->equals(*articleIter))
		{
			if ((inArticle->boundingRectangle())->isNear(rectangle))
			{
			  inArticle->join(*articleIter);
			}
		}
		articleIter++;

		if (articleIter == inArticleList.end())
		{
		  articleIter = inArticleList.begin();
		  testedAllArticles = true;
		}
	  }
  }
  return inArticle;
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
	  headline = new RkSegment(groupVerticleSegments(segment, inSegmentList, HEADLINE_VERTICAL_DISTANCE), HEADLINE_TYPE);
	  headline->boundingRectangle = groupHorizontalSegments(headline, inSegmentList, HEADLINE_HORIZONTAL_DISTANCE);
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
	  headline = new RkSegment(groupVerticleSegments(segment, headlines, HEADLINE_HORIZONTAL_DISTANCE*2), HEADLINE_TYPE);
	  headline->boundingRectangle = groupHorizontalSegments(headline, headlines, HEADLINE_HORIZONTAL_DISTANCE*2);
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
	  text = new RkSegment(groupVerticleSegments(segment, inSegmentList, 4), CONTENT_TYPE);
	  textColumn.push_back(text);
	}
  }

  textColumn.reverse();
  for (segmentIter=textColumn.begin(); segmentIter!=textColumn.end(); segmentIter++)
  {
	segment = (*segmentIter);
	if (! isSegmentInSegmentList(segment, columnList))
	{
	  text = new RkSegment(groupVerticleSegments(segment, columnList, 6), CONTENT_TYPE);
	  columnList.push_back(text);
	}
  }

  return columnList;
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
			if (isSimilarHeight(baseRectangle, rectangle, inTolerance))
			  baseRectangle->join(rectangle);
		  }
		}

		if (baseRectangle->isLeft(rectangle))
		{
		  if (baseRectangle->isNear(rectangle, inTolerance))
		  {
			if (isSimilarHeight(baseRectangle, rectangle, inTolerance))
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

  if ((difference == inColumn->boundingRectangle->top - inHeadline->boundingRectangle->bottom) &&
	  (difference < HEADLINE_VERTICAL_DISTANCE*2))
	  return true;

  return false;
}

list<RkSegment*> getClassifiedSegmentList(string* inFileName)
{
  int* top = new int; int* left = new int;
  int* bottom = new int; int* right = new int;
  int* type = new int;

  list<RkSegment*> segmentList;
  RkBoundingRectangle* tmpRect;

  FILE* segmentFile;
  segmentFile = fopen(inFileName->c_str(), "r");

  while ( ! feof (segmentFile) )
  {
	fscanf(segmentFile, "%d,%d,%d,%d, %d\n", top, left, bottom, right, type);
	tmpRect = new RkBoundingRectangle(*top, *left, *bottom, *right);
	segmentList.push_back(new RkSegment(tmpRect, *type));
  }

  fclose(segmentFile);
  return segmentList;
}

void dumpFramedSegmentList(list<RkArticle*> inArticleList, string* inFileName)
{
  RkArticle* article;
  list<RkArticle*>::iterator articleIter;

  FILE* articleFile;
  articleFile = fopen(inFileName->c_str(), "w");

  for (articleIter=inArticleList.begin(); articleIter!=inArticleList.end(); articleIter++)
  {
	  article = (*articleIter);
	  article->printString(articleFile);
  }

  fclose(articleFile);
}
