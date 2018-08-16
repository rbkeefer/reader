/*
 * TestRkColumn.cpp
 *
 */

#include "../src/Classify.h"
#include "../src/RkColumn.h"

void testRkColumn() {
	printf("\n** TEST COLUMN **\n");
	printf("------------------\n");

	RkColumn* col1 = new RkColumn();
	col1->top = 10; col1->bottom = 25; col1->column = 5;

	RkColumn* col2 = new RkColumn(5, 10, 25);

	CvPoint pt1 = col1->topPoint();
	if ((pt1.x != 5) && (pt1.y != 10)) printf("RkColumn: topPoint() FAILED\n");

	pt1 = col1->bottomPoint();
	if ((pt1.x != 5) && (pt1.y != 25)) printf("RkColumn: bottomPoint() FAILED\n");

	if (col1->pointIn(4, 9, 0)) printf("RkColumn: pointIn() FAILED\n");
	if (! col1->pointIn(5, 10, 0)) printf("RkColumn: pointIn() FAILED\n");
	if (! col1->pointIn(5, 25, 0)) printf("RkColumn: pointIn() FAILED\n");
	if (! col1->pointIn(5, 9, 1)) printf("RkColumn: pointIn() FAILED\n");
	if (! col1->pointIn(5, 26, 1)) printf("RkColumn: pointIn() FAILED\n");
	if (col1->pointIn(4, 10, 1)) printf("RkColumn: pointIn() FAILED\n");
	if (col1->pointIn(6, 25, 1)) printf("RkColumn: pointIn() FAILED\n");

	if (col1->height() != 15) printf("RkColumn: height() FAILED\n");

	if (!col1->equals(col2)) printf("RkColumn: equals() FAILED\n");
}
