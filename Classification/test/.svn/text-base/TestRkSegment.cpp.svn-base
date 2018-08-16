/*
 * TestRkSegment.cpp
 */

#include "../src/RkBoundingRectangle.h"
#include "../src/RkSegment.h"

void testRkSegment() {
	printf("\n** TEST SEGMENT**\n");
	printf("---------------------\n");

	RkBoundingRectangle* br1 = new RkBoundingRectangle(1, 1, 10, 10);
	RkSegment* seg1 = new RkSegment(br1, 1);


	RkBoundingRectangle* br2 = new RkBoundingRectangle(1, 1, 10, 10);
	RkSegment* seg2 = new RkSegment();
	seg2->boundingRectangle = br2;
	seg2->segmentType = 1;

	if (! seg1->boundingRectangle->equals(seg2->boundingRectangle)) printf("RkSegment: Constructors failed\n");

}
