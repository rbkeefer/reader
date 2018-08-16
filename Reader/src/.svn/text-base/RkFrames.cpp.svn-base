/*
 * RkFrames.cpp
 *
 */

#include "Reader.h"
#include "RkBoundingRectangle.h"
#include "RkRegions.h"
#include "RkCharacter.h"
#include "RkTextFrame.h"
#include "RkArticle.h"
#include "RkUtils.h"

list<RkCharacter*> getCharacterList(RkBoundingRectangle* inRegion, IplImage* inFramedImg)
{
  int ht, wd;
  RkBoundingRectangle* charRectangle;
  list<RkCharacter*> characterList;

  list<RkBoundingRectangle*> potentialCharacterList = regionizeImage(inFramedImg, BLACK);

  list<RkBoundingRectangle*>::iterator charFrameIter;
  for (charFrameIter=potentialCharacterList.begin(); charFrameIter!=potentialCharacterList.end(); charFrameIter++)
  {
    charRectangle = (*charFrameIter);
    ht = charRectangle->height();
    wd = charRectangle->width();
    if ((ht > 8) && (wd > 6) && (ht < 25) && (wd < 25))
    {
	  RkCharacter* character = new RkCharacter(charRectangle);
	  characterList.push_back(character);
    }
  }

  return characterList;
}

list<RkTextFrame*> getTextFrameList(list<RkBoundingRectangle*> regionList, IplImage* cleanedImg)
{
  IplImage* frameImg;
  RkBoundingRectangle* region;
  RkTextFrame* textFrame;
  list<RkTextFrame*> textFrameList;
  list<RkCharacter*> characterList;
  list<RkBoundingRectangle*>::iterator regionIter;

  for (regionIter=regionList.begin(); regionIter!=regionList.end(); regionIter++)
  {
    region = (*regionIter);
    cvSetImageROI(cleanedImg, region->toRect());

    frameImg = cvCreateImage(cvGetSize(cleanedImg), cleanedImg->depth, cleanedImg->nChannels);
    cvCopy(cleanedImg, frameImg, NULL);

    characterList = getCharacterList(region, frameImg);
    if (characterList.size() > 0)
    {
    	textFrame = new RkTextFrame(region, characterList);
    	textFrame->frameType = (((float)textFrame->getFontSize())/((float)region->height()) > 0.24) ? HEADLINE_TYPE : CONTENT_TYPE;
    	textFrameList.push_back(textFrame);
    }

    cvResetImageROI(cleanedImg);
  }

  return textFrameList;
}

bool isInArticle(RkTextFrame* inFrame, list<RkArticle*> inArticleList)
{
  RkArticle* article;
  RkTextFrame* textFrame;
  list<RkTextFrame*> textFrameList;
  list<RkArticle*>::iterator articleIter;
  list<RkTextFrame*>::iterator textFrameIter;

  for (articleIter=inArticleList.begin(); articleIter!=inArticleList.end(); articleIter++)
  {
	article = (*articleIter);

	// Check headline
	textFrameList = article->headlineList;
    for (textFrameIter=textFrameList.begin(); textFrameIter!=textFrameList.end(); textFrameIter++)
    {
    	textFrame = (*textFrameIter);
    	if ((NULL != textFrame) && (textFrame->equals(inFrame))) return true;
    }

    // Check content
	textFrameList = article->contentList;
    for (textFrameIter=textFrameList.begin(); textFrameIter!=textFrameList.end(); textFrameIter++)
    {
    	textFrame = (*textFrameIter);
    	if ((NULL != textFrame) && (textFrame->equals(inFrame))) return true;
    }
  }

  return false;
}

list<RkTextFrame*> findHeadlineFrames(RkTextFrame* inFrame, list<RkTextFrame*> inFrameList)
{
  list<RkTextFrame*> foundList;
  list<RkTextFrame*> headlineList;
  RkTextFrame* textFrame;
  list<RkTextFrame*>::iterator textFrameIter;

  for (textFrameIter=inFrameList.begin(); textFrameIter!=inFrameList.end(); textFrameIter++)
  {
	textFrame = (*textFrameIter);
	if (textFrame->equals(inFrame)) break;
  }
  inFrameList.erase(textFrameIter);

  for (textFrameIter=inFrameList.begin(); textFrameIter!=inFrameList.end(); textFrameIter++)
  {
	textFrame = (*textFrameIter);

	if ((textFrame->frameType == HEADLINE_TYPE) && ((textFrame->isNear(inFrame, 4)))) // ||
			                                      //  (textFrame->isBelow(inFrame, textFrame->getFontSize())))
	{
	  foundList = findHeadlineFrames(textFrame, inFrameList);
	  foundList.sort(compareTextFrameBottomRight);
	  headlineList.sort(compareTextFrameBottomRight);

      headlineList.merge(foundList);
	}
  }

  headlineList.unique(sameTextFrame);
  headlineList.push_back(inFrame);

  return headlineList;
}

list<RkTextFrame*> findContentFrames(RkTextFrame* inFrame, list<RkTextFrame*> inFrameList)
{
  list<RkTextFrame*> foundList;
  list<RkTextFrame*> contentList;
  RkTextFrame* textFrame;
  list<RkTextFrame*>::iterator textFrameIter;

  for (textFrameIter=inFrameList.begin(); textFrameIter!=inFrameList.end(); textFrameIter++)
  {
	textFrame = (*textFrameIter);
	if (textFrame->equals(inFrame)) break;
  }
  inFrameList.erase(textFrameIter);

  for (textFrameIter=inFrameList.begin(); textFrameIter!=inFrameList.end(); textFrameIter++)
  {
	textFrame = (*textFrameIter);

	if ((textFrame->frameType == CONTENT_TYPE) && (textFrame->isNear(inFrame, 4))) {
	  foundList = findContentFrames(textFrame, inFrameList);
	  foundList.sort(compareTextFrameBottomRight);
	  contentList.sort(compareTextFrameBottomRight);

      contentList.merge(foundList);
	}
  }

  contentList.unique(sameTextFrame);
  contentList.push_back(inFrame);

  return contentList;
}

RkArticle* createArticle(RkTextFrame* inFrame, list<RkTextFrame*> inFrameList)
{
  RkArticle* article;
  article = new RkArticle();

  if (inFrame->frameType == HEADLINE_TYPE)
	  article->headlineList = findHeadlineFrames(inFrame, inFrameList);
  else
	  article->contentList = findContentFrames(inFrame, inFrameList);

  return article;
}

list<RkArticle*> groupArticles(list<RkTextFrame*> inFrameList)
{
  RkArticle* article;
  RkTextFrame* textFrame;
  list<RkArticle*> articleList;
  list<RkTextFrame*>::iterator textFrameIter;

  inFrameList.sort(compareTextFrameBottomRight);

  for (textFrameIter=inFrameList.begin(); textFrameIter!=inFrameList.end(); textFrameIter++)
  {
	textFrame = (*textFrameIter);

	if (! isInArticle(textFrame, articleList))
	{
	  article = createArticle(textFrame, inFrameList);
	  articleList.push_back(article);
	}
  }

  return articleList;
}

list<RkArticle*> getArticleList(list<RkBoundingRectangle*> inRegionList, IplImage* inCleanedImg)
{

  list<RkTextFrame*> textFrameList = getTextFrameList(inRegionList, inCleanedImg);

  list<RkArticle*> articleList = groupArticles(textFrameList);

  return articleList;
}

