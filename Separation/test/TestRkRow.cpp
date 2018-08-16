/*
 * TestRkRow.cpp
 *
 */

#include "../src/Separate.h"
#include "../src/RkRow.h"

void testRkRow() {
	printf("\n** TEST ROW **\n");
	printf("--------------------\n");

	RkRow* row1 = new RkRow();
	row1->left = 10; row1->right = 25; row1->row = 5;

	RkRow* row2 = new RkRow(5, 10, 25);

	CvPoint pt1 = row1->leftPoint();
	if ((pt1.x != 10) && (pt1.y != 5)) printf("RkRow: leftPoint() FAILED\n");

	pt1 = row1->rightPoint();
	if ((pt1.x != 25) && (pt1.y != 5)) printf("RkRow: rightPoint() FAILED\n");

	if (row1->pointIn(9, 4, 0)) printf("RkRow: pointIn() FAILED\n");
	if (! row1->pointIn(10, 5, 0)) printf("RkRow: pointIn() FAILED\n");
	if (! row1->pointIn(25, 5, 0)) printf("RkRow: pointIn() FAILED\n");
	if (! row1->pointIn(9, 5, 1)) printf("RkRow: pointIn() FAILED\n");
	if (! row1->pointIn(26, 5, 1)) printf("RkRow: pointIn() FAILED\n");
	if (row1->pointIn(10, 4, 1)) printf("RkRow: pointIn() FAILED\n");
	if (row1->pointIn(25, 6, 1)) printf("RkRow: pointIn() FAILED\n");

	if (row1->width() != 15) printf("RkRow: width() FAILED\n");

	if (!row1->equals(row2)) printf("RkRow: equals() FAILED\n");
}
