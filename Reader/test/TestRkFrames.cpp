/*
 * TestRkFrames.cpp
 *
 */

#include "../src/Reader.h"
#include "../src/RkBoundingRectangle.h"
#include "../src/RkCharacter.h"
#include "../src/RkTextFrame.h"
#include "../src/RkArticle.h"
#include "../src/RkFrames.h"

void testRkFrames() {
	printf("\n** TEST FRAMES **\n");
	printf("------------------\n");

	list<RkCharacter*> charList1;
	RkCharacter* ch1 = new RkCharacter(new RkBoundingRectangle(0,456, 10,466));
	charList1.push_back(ch1);
	RkCharacter* ch2 = new RkCharacter(new RkBoundingRectangle(0,468, 10,478));
	charList1.push_back(ch2);
	RkCharacter* ch3 = new RkCharacter(new RkBoundingRectangle(0,480, 10,490));
	charList1.push_back(ch3);
	RkCharacter* ch4 = new RkCharacter(new RkBoundingRectangle(0,492, 10,502));
	charList1.push_back(ch4);
	RkCharacter* ch5 = new RkCharacter(new RkBoundingRectangle(0,504, 10,512));
	charList1.push_back(ch5);

	RkBoundingRectangle* boundingFrame1 = new RkBoundingRectangle(0,456, 452,512);
	RkTextFrame* tf1 = new RkTextFrame(boundingFrame1, charList1);

	list<RkCharacter*> charList2;
	RkCharacter* ch6 = new RkCharacter(new RkBoundingRectangle(140,0, 12,150));
	charList2.push_back(ch6);
	RkCharacter* ch7 = new RkCharacter(new RkBoundingRectangle(152,0, 12,162));
	charList2.push_back(ch7);
	RkCharacter* ch8 = new RkCharacter(new RkBoundingRectangle(164,0, 12,174));
	charList2.push_back(ch8);
	RkCharacter* ch9 = new RkCharacter(new RkBoundingRectangle(176,0, 12,186));
	charList2.push_back(ch9);
	RkCharacter* ch10 = new RkCharacter(new RkBoundingRectangle(188,0, 12,198));
	charList2.push_back(ch10);

	RkBoundingRectangle* boundingFrame2 = new RkBoundingRectangle(140, 0, 180,456);
	RkTextFrame* tf2 = new RkTextFrame(boundingFrame2, charList2);


	RkTextFrame* tf3 = new RkTextFrame();
	(tf3->characterList).push_back(new RkCharacter(new RkBoundingRectangle(496,264, 512,274)));
	tf3->boundingRectangle = new RkBoundingRectangle(496,264, 512,320);
	RkTextFrame* tf4 = new RkTextFrame();
	(tf4->characterList).push_back(new RkCharacter(new RkBoundingRectangle(472,264, 488,274)));
	tf4->boundingRectangle = new RkBoundingRectangle(472,264, 488,304);
	RkTextFrame* tf5 = new RkTextFrame();
	(tf5->characterList).push_back(new RkCharacter(new RkBoundingRectangle(496,156, 512,270)));
	tf5->boundingRectangle = new RkBoundingRectangle(496,156, 512,260);
	RkTextFrame* tf6 = new RkTextFrame();
	(tf6->characterList).push_back(new RkCharacter(new RkBoundingRectangle(476,248, 492,270)));
	tf6->boundingRectangle = new RkBoundingRectangle(476,248, 492,260);
	RkTextFrame* tf7 = new RkTextFrame();
	(tf7->characterList).push_back(new RkCharacter(new RkBoundingRectangle(472,196, 492,206)));
	tf7->boundingRectangle = new RkBoundingRectangle(472,196, 492,244);
	RkTextFrame* tf8 = new RkTextFrame();
	(tf8->characterList).push_back(new RkCharacter(new RkBoundingRectangle(496,112, 512,122)));
	tf8->boundingRectangle = new RkBoundingRectangle(496,112, 512,156);
	RkTextFrame* tf9 = new RkTextFrame();
	(tf9->characterList).push_back(new RkCharacter(new RkBoundingRectangle(472,160, 492,170)));
	tf9->boundingRectangle = new RkBoundingRectangle(472,160, 492,192);
	RkTextFrame* tf10 = new RkTextFrame();
	(tf10->characterList).push_back(new RkCharacter(new RkBoundingRectangle(472,56, 492,66)));
	tf10->boundingRectangle = new RkBoundingRectangle(472,56, 492,156);


	list<RkTextFrame*> textFrameList;
	textFrameList.push_back(tf1);
	textFrameList.push_back(tf2);
	textFrameList.push_back(tf3);
	textFrameList.push_back(tf4);
	textFrameList.push_back(tf5);
	textFrameList.push_back(tf6);
	textFrameList.push_back(tf7);
	textFrameList.push_back(tf8);
	textFrameList.push_back(tf9);
	textFrameList.push_back(tf10);



	list<RkArticle*> articleList = groupArticles(textFrameList);

	if (articleList.size() != 3)
	{
		printf("testRkFrames: groupArticles FAILED - expected 3 but got %d\n", (int) articleList.size());

		list<RkArticle*>::iterator articleIter;
		RkArticle* article;
		for (articleIter=articleList.begin(); articleIter!=articleList.end(); articleIter++)
		{
		  article = (*articleIter);
		  (article->boundingRectangle())->toString();
		}
	}
}
