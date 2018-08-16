#include "../src/RkBoundingRectangle.h"

void testRkBoundingRect() {

	printf("\n** TEST BOUNDING RECTANGLE **\n");
	printf("-----------------------------\n");

	RkBoundingRectangle* br1 = new RkBoundingRectangle();
	br1->top = 1;
	br1->bottom = 10;
	br1->left = 1;
	br1->right = 10;

	RkBoundingRectangle* br2 = new RkBoundingRectangle(1, 1, 10, 10);
	RkBoundingRectangle* br3 = new RkBoundingRectangle(br2);


	// Test Constructors and Equals
	if (1 != br1->equals(br2)) printf("RkBoundingRect: equals() FAILED\n");
	if (1 != br1->equals(br3)) printf("RkBoundingRect: equals() FAILED\n");


	// Test Functions
	if (9 != br1->width()) printf("RkBoundingRect: width() FAILED\n");
	if (9 != br1->height()) printf("RkBoundingRect: height() FAILED\n");
	if (81 != br1->area()) printf("RkBoundingRect: area() FAILED\n");

	CvPoint pt; pt.x = 11; pt.y = 11;     br1->move(pt);
	if (0 != br3->equals(br1)) printf("RkBoundingRect: move() FAILED\n");


	// Test Points
	if ((12 != (br1->topLeft()).x) || (12 != (br1->topLeft()).y))
		printf("RkBoundingRect: topLeft() FAILED\n");
	if ((21 != (br1->topRight()).x) || (12 != (br1->topRight()).y))
		printf("RkBoundingRect: topRight() FAILED\n");
	if ((12 != (br1->bottomLeft()).x) || (21 != (br1->bottomLeft()).y))
		printf("RkBoundingRect: bottomLeft() FAILED\n");
	if ((21 != (br1->bottomRight()).x) || (21 != (br1->bottomRight()).y))
		printf("RkBoundingRect: bottomRight() FAILED\n");


    // Test Booleans
	if (0 == br1->pointIn(13, 13, 0)) printf("RkBoundingRect: pointIn() first test FAILED\n");
	if (1 == br1->pointIn(22, 22, 0)) printf("RkBoundingRect: pointIn() second test FAILED\n");
	if (1 == br1->isColumnShape()) printf("RkBoundingRect: isColumnShape() first test FAILED\n");
	if (1 == br1->isRowShape()) printf("RkBoundingRect: isRowShape() first test FAILED\n");

	br3->bottom = 50;
	if (0 == br3->isColumnShape()) printf("RkBoundingRect: isColumnShape() second test FAILED\n");

	br3->right = 500;
	if (0 == br3->isRowShape()) printf("RkBoundingRect: isRowShape() second test FAILED\n");

	// Test Transformations
	CvRect rect;
	rect.x=12; rect.y=12;
	rect.height=9; rect.width=9;

	CvRect br1Rect = br1->toRect();
	if ((rect.x != br1Rect.x) || (rect.y != br1Rect.y) ||
		(rect.width != br1Rect.width) || (rect.height != br1Rect.height))
		printf("RkBoundingRect: cvRect() FAILED\n");

	br1->top = 10; br1->left = 10; br1->bottom = 25; br1->right = 25;
	br2->top = 5; br2->left = 5; br2->bottom = 30; br2->right = 15;
	br3->top = 15; br3->left = 20; br3->bottom = 20; br3->right = 30;

	if (! br1->isNear(br2)) printf("RkBoundingRect: isNear() first test FAILED\n");
	if (! br1->isNear(br3)) printf("RkBoundingRect: isNear() second test FAILED\n");
	if (br2->isNear(br3)) printf("RkBoundingRect: isNear() third test FAILED\n");

}
