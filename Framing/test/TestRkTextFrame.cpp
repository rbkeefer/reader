/*
 * TestRkTextFrame.cpp
 *
 */

#include "../src/RkTextFrame.h"

void testRkTextFrame() {
	printf("\n** TEST TEXT FRAME **\n");
	printf("--------------------\n");

	RkTextFrame* tf1 = new RkTextFrame();
	RkBoundingRectangle* boundingFrame = new RkBoundingRectangle(1,1, 100,50);

	RkCharacter* ch1 = new RkCharacter(new RkBoundingRectangle(2,2, 10,10));
	RkCharacter* ch2 = new RkCharacter(new RkBoundingRectangle(2,12, 10,20));
	RkCharacter* ch3 = new RkCharacter(new RkBoundingRectangle(2,22, 10,30));

	list<RkCharacter*> charList;
	charList.push_back(ch1);
	charList.push_back(ch2);
	charList.push_back(ch3);

	tf1->boundingRectangle = boundingFrame;
	tf1->characterList = charList;


	RkTextFrame* tf2 = new RkTextFrame(boundingFrame, charList);

	if (! (tf1->boundingRectangle)->equals(tf2->boundingRectangle))
		printf("RkTextFrame: frame construction FAILED\n");

	RkCharacter* tmpChar;
	list<RkCharacter*>::iterator iter;
	for (iter=(tf2->characterList).begin(); iter!=(tf2->characterList).end(); iter++) {
		tmpChar = (*iter);
		if ( !(tmpChar->boundingRectangle->equals(ch1->boundingRectangle)) &&
			 !(tmpChar->boundingRectangle->equals(ch2->boundingRectangle)) &&
			 !(tmpChar->boundingRectangle->equals(ch3->boundingRectangle)))
			printf("RkTextFrame: character construction FAILED\n");
	}

	int fontSize = tf1->getFontSize();
	if (8 != fontSize) printf("RKTextFrame: getFontSize FAILED - expected 8 but got %d\n", fontSize);

}
