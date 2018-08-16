/*
 * TestRkArticle.cpp
 *
 */

#include "../src/RkArticle.h"
#include "../src/RkCharacter.h"
#include "../src/RkBoundingRectangle.h"


void testRkArticle() {
	printf("\n** TEST ARTICLE **\n");
	printf("--------------------\n");

	list<RkCharacter*> headCharList;
	RkCharacter* h1 = new RkCharacter(new RkBoundingRectangle(2,2, 10,10));
	RkCharacter* h2 = new RkCharacter(new RkBoundingRectangle(2,12, 10,20));
	RkCharacter* h3 = new RkCharacter(new RkBoundingRectangle(2,22, 10,30));
	RkCharacter* h4 = new RkCharacter(new RkBoundingRectangle(2,32, 10,40));
	RkCharacter* h5 = new RkCharacter(new RkBoundingRectangle(2,42, 10,50));
	RkCharacter* h6 = new RkCharacter(new RkBoundingRectangle(2,52, 10,60));
	headCharList.push_back(h1); headCharList.push_back(h2); headCharList.push_back(h3);
	headCharList.push_back(h4); headCharList.push_back(h5); headCharList.push_back(h6);

	RkBoundingRectangle* boundingHeadline = new RkBoundingRectangle(2,2, 10,60);

	RkTextFrame* headlineFrame = new RkTextFrame(boundingHeadline, headCharList);


	list<RkCharacter*> charList;
	RkCharacter* ch1 = new RkCharacter(new RkBoundingRectangle(15,2, 22,10));
	RkCharacter* ch2 = new RkCharacter(new RkBoundingRectangle(15,12, 22,20));
	RkCharacter* ch3 = new RkCharacter(new RkBoundingRectangle(15,22, 22,30));
	RkCharacter* ch4 = new RkCharacter(new RkBoundingRectangle(15,32, 22,40));
	RkCharacter* ch5 = new RkCharacter(new RkBoundingRectangle(15,42, 22,50));
	RkCharacter* ch6 = new RkCharacter(new RkBoundingRectangle(15,52, 22,60));
	charList.push_back(ch1); charList.push_back(ch2); charList.push_back(ch3);
	charList.push_back(ch4); charList.push_back(ch5); charList.push_back(ch6);

	RkBoundingRectangle* boundingContent = new RkBoundingRectangle(15,1, 22,60);

	RkTextFrame* contentFrame = new RkTextFrame(boundingContent, charList);

	RkArticle* article = new RkArticle();
	(article->headlineList).push_back(headlineFrame);
	(article->contentList).push_back(contentFrame);
}
