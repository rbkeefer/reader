/*
 * TestUtils.cpp
 *
 */

#include "../src/Reader.h"

#include "../src/RkBoundingRectangle.h"
#include "../src/RkSegment.h"
#include "../src/RkArticle.h"
#include "../src/Utils.h"

void testUtils(IplImage* origImg) {

	// Test isColoredRegion
	isColoredRegion(0,0, 2, origImg, BLACK);
	isColoredRegion(639,0, 2, origImg, BLACK);
	isColoredRegion(639,479, 2, origImg, BLACK);

	// Test isSamePoint
	CvPoint pt1; pt1.x = 10; pt1.y = 10;
	CvPoint pt2; pt2.x = 10; pt2.y = 10;
	if (! isSamePoint(pt1, pt2)) printf("Utils: isSamePoint() FAILED\n");

	pt2.x = 11;
	if (isSamePoint(pt1, pt2)) printf("Utils: isSamePoint() FAILED\n");
	pt2.x = 10; pt2.y = 8;
	if (isSamePoint(pt1, pt2)) printf("Utils: isSamePoint() FAILED\n");


	// Test isBoundByRectangle
	RkBoundingRectangle* rect1 = new RkBoundingRectangle(9,9, 20,20);
	if (! isPointBoundByRectangle(pt1, rect1, 0)) printf("Utils: isBoundByRectangle() FAILED\n");
	if (isPointBoundByRectangle(pt2, rect1, 0)) printf("Utils: isBoundByRectangle() FAILED\n");
	if (! isPointBoundByRectangle(pt2, rect1, 1)) printf("Utils: isBoundByRectangle() FAILED\n");

	RkBoundingRectangle* rect2 = new RkBoundingRectangle(29, 29, 40,40);
	list<RkBoundingRectangle*> rectList;
	rectList.push_back(rect1);
	rectList.push_back(rect2);

	if (! isPointBoundByRectangle(pt1, rectList, 0)) printf("Utils: isBoundByRectangle() FAILED");
	if (isPointBoundByRectangle(pt2, rectList, 0)) printf("Utils: isBoundByRectangle() FAILED");
	if (! isPointBoundByRectangle(pt2, rectList, 1)) printf("Utils: isBoundByRectangle() FAILED");


	// Test expandBoundingRectList
	expandBoundingRectList(rectList, 2);
	list<RkBoundingRectangle*>::iterator iter;
	for (iter = rectList.begin(); iter != rectList.end(); iter++)
	{
		if ((*iter)->width() != 48) printf("Utils: expand FAILED: expected 48 but got %d\n", (*iter)->width());
		if ((*iter)->height() != 48) printf("Utils: expand FAILED: expected 48 but got %d\n", (*iter)->height());
	}

	free(rect1);
	free(rect2);
}
