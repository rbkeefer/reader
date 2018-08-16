/*
 * TestRkFrames.cpp
 *
 */

#include "../src/Frame.h"
#include "../src/RkBoundingRectangle.h"
#include "../src/RkCharacter.h"
#include "../src/RkTextFrame.h"
#include "../src/RkSegment.h"
#include "../src/RkArticle.h"
#include "../src/RkFrames.h"

void testRkFrames() {
	printf("\n** TEST FRAMES **\n");
	printf("------------------\n");

	// TEST SEGMENTS DIRECTLY FROM DATA
	list<RkSegment*> segmentList;

	segmentList.push_back(new RkSegment(new RkBoundingRectangle(0,0,116,456),4));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(0,464,152,512),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(132,392,140,452),4));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(140,0,180,456),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(156,464,180,512),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(184,464,328,512),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(188,0,196,456),4));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,0,220,40),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,56,224,120),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,120,224,180),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,184,224,372),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,376,228,456),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(228,0,244,36),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(232,88,236,156),4));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(232,192,260,320),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(232,328,240,348),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(232,328,260,452),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(236,452,240,456),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(248,0,272,48),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(248,56,452,184),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(264,192,448,320),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(264,328,336,452),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(280,0,284,16),4));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(292,0,300,20),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(304,0,360,48),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(332,460,452,512),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(340,328,372,452),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(372,0,512,48),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(376,328,428,452),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(432,328,448,452),2));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(456,56,464,512),4));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,56,492,156),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,160,492,192),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,196,492,244),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,264,488,304),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,328,512,512),4));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(476,248,488,260),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,72,512,108),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,112,512,156),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,156,512,260),1));
	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,264,512,320),1));

//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,0,220,40),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,56,224,120),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,120,224,180),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,184,224,372),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(204,376,228,456),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(228,0,244,36),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(248,0,272,48),1));
//
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,56,492,156),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,160,492,192),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,196,492,244),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(472,264,488,304),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(476,248,488,260),1));
//
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,72,512,108),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,112,512,156),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,156,512,260),1));
//	segmentList.push_back(new RkSegment(new RkBoundingRectangle(496,264,512,320),1));

	list<RkArticle*>::iterator articleIter;
	list<RkSegment*>::iterator columnIter;
	list<RkArticle*> articleList;
	RkArticle* article;

    articleList = groupArticles(segmentList);

	if (articleList.size() != 3)
	{
		printf("testRkFrames: groupArticles FAILED - expected 3 but got %d\n", (int) articleList.size());

		for (articleIter=articleList.begin(); articleIter!=articleList.end(); articleIter++)
		{
		  article = (*articleIter);
		  (article->boundingRectangle())->toString();
		}

		printf("\n------------\n\n");
	}

	list<RkSegment*> segmentList2;

    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(72,424,104,496),1));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(108,428,124,500),1));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(128,452,132,464),4));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(128,468,132,484),4));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(136,428,144,500),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(148,444,152,464),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(148,472,152,476),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(148,476,152,480),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(156,432,184,504),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(188,472,192,484),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(196,428,512,512),2));

	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(72,340,112,420),1));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(124,340,136,384),1));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(124,388,128,392),1));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(124,396,132,420),1));

	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(116,360,124,396),4));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(128,388,132,392),4));

	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(136,348,144,412),2));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(156,344,236,420),2));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(176,340,184,344),2));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(212,348,288,420),2));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(228,344,511,424),2));
	segmentList2.push_back(new RkSegment(new RkBoundingRectangle(136,348,144,412),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(148,364,152,392),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(156,352,168,408),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(172,344,212,420),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(176,340,180,344),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(180,340,184,344),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(212,352,224,412),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(224,348,236,356),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(224,348,236,360),2));
    segmentList2.push_back(new RkSegment(new RkBoundingRectangle(228,348,288,420),2));

	articleList = groupArticles(segmentList2);

	if (articleList.size() != 2) printf("testRkFrames: groupArticles FAILED - expected 2 but got %d\n", (int) articleList.size());
	for (articleIter=articleList.begin(); articleIter!=articleList.end(); articleIter++)
	{
	  article = (*articleIter);
	  if ((article->columns).size() > 2)
      {
	    printf("testRkFrames: groupArticles Column combination FAILED - expected 1 but got %d\n", (int) (article->columns).size());
	    for (columnIter=(article->columns).begin(); columnIter!=(article->columns).end(); columnIter++)
	    {
          (*columnIter)->boundingRectangle->toString();
	    }
	  }
	}



}
