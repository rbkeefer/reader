/*
 * TestRkArticle.cpp
 *
 */

#include "../src/RkBoundingRectangle.h"
#include "../src/RkSegment.h"
#include "../src/RkArticle.h"


void testRkArticle() {
	printf("\n** TEST ARTICLE **\n");
	printf("--------------------\n");


	RkBoundingRectangle* boundingHeadline = new RkBoundingRectangle(2,2, 10,60);


	RkBoundingRectangle* boundingContent = new RkBoundingRectangle(15,1, 22,60);


	RkArticle* article = new RkArticle();
	RkSegment* headline = new RkSegment(boundingHeadline, 1);
	RkSegment* content = new RkSegment(boundingContent, 2);

	article->headline = headline;
	(article->columns).push_back(content);
}
