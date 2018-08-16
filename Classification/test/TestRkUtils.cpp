/*
 * TestRkUtils.cpp
 *
 */

#include "../src/Classify.h"
#include "../src/RkBoundingRectangle.h"
#include "../src/RkSegment.h"
#include "../src/RkTextFrame.h"
#include "../src/RkUtils.h"

void testRkUtils() {
	printf("\n** TEST UTILS **\n");
	printf("------------------\n");

	// Test isSamePoint
	CvPoint pt1; pt1.x = 10; pt1.y = 10;
	CvPoint pt2; pt2.x = 10; pt2.y = 10;
	if (! isSamePoint(pt1, pt2)) printf("RkUtils: isSamePoint() FAILED\n");

	pt2.x = 11;
	if (isSamePoint(pt1, pt2)) printf("RkUtils: isSamePoint() FAILED\n");
	pt2.x = 10; pt2.y = 8;
	if (isSamePoint(pt1, pt2)) printf("RkUtils: isSamePoint() FAILED\n");


	// Test isBoundByRectangle
	RkBoundingRectangle* rect1 = new RkBoundingRectangle(9,9, 20,20);
	if (! isBoundByRectangle(pt1, rect1, 0)) printf("RkUtils: isBoundByRectangle() FAILED\n");
	if (isBoundByRectangle(pt2, rect1, 0)) printf("RkUtils: isBoundByRectangle() FAILED\n");
	if (! isBoundByRectangle(pt2, rect1, 1)) printf("RkUtils: isBoundByRectangle() FAILED\n");

	RkBoundingRectangle* rect2 = new RkBoundingRectangle(29, 29, 40,40);
	list<RkBoundingRectangle*> rectList;
	rectList.push_back(rect1);
	rectList.push_back(rect2);

	if (! isBoundByRectangle(pt1, rectList, 0)) printf("RkUtils: isBoundByRectangle() FAILED");
	if (isBoundByRectangle(pt2, rectList, 0)) printf("RkUtils: isBoundByRectangle() FAILED");
	if (! isBoundByRectangle(pt2, rectList, 1)) printf("RkUtils: isBoundByRectangle() FAILED");


	// Test expandBoundingRectList
	expandBoundingRectList(rectList, 2);
	list<RkBoundingRectangle*>::iterator iter;
	for (iter = rectList.begin(); iter != rectList.end(); iter++)
	{
		if ((*iter)->width() != 48) printf("RkUtils: expand FAILED: expected 48 but got %d\n", (*iter)->width());
		if ((*iter)->height() != 48) printf("RkUtils: expand FAILED: expected 48 but got %d\n", (*iter)->height());
	}
}
