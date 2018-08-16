/*
 * TestRkRegions.cpp
 *
 */

#include "../src/Reader.h"
#include "../src/RkBoundingRectangle.h"
#include "../src/RkRegions.h"

void testGetPixel();

void testRkRegions() {
	printf("\n** TEST REGIONS **\n");
	printf("------------------\n");

	testGetPixel();
}

void testGetPixel() {
	// Test generic point
	CvPoint pt1; pt1.x=10; pt1.y=10;
	CvPoint pt2 = getPixel(pt1, 0);
	if (! (pt2.x == 9 && pt2.y==10)) printf("testRkRegions: getPixel() FAILED, expected 9,10 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1);
	if (! (pt2.x == 9 && pt2.y==9)) printf("testRkRegions: getPixel() FAILED, expected 9,9 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2);
	if (! (pt2.x == 10 && pt2.y==9)) printf("testRkRegions: getPixel() FAILED, expected 10,9 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3);
	if (! (pt2.x == 11 && pt2.y==9)) printf("testRkRegions: getPixel() FAILED, expected 11,9 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4);
	if (! (pt2.x == 11 && pt2.y==10)) printf("testRkRegions: getPixel() FAILED, expected 11,10 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5);
	if (! (pt2.x == 11 && pt2.y==11)) printf("testRkRegions: getPixel() FAILED, expected 11,11 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6);
	if (! (pt2.x == 10 && pt2.y==11)) printf("testRkRegions: getPixel() FAILED, expected 10,11 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7);
	if (! (pt2.x == 9 && pt2.y==11)) printf("testRkRegions: getPixel() FAILED, expected 9,11 but was %d,%d\n", pt2.x, pt2.y);


	// Test upper left
	pt1.x=0; pt1.y=0;
	pt2 = getPixel(pt1, 0);
	if (! (pt2.x == 1 && pt2.y==0)) printf("1. testRkRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1);
	if (! (pt2.x == 1 && pt2.y==0)) printf("2. testRkRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2);
	if (! (pt2.x == 1 && pt2.y==0)) printf("3. testRkRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3);
	if (! (pt2.x == 1 && pt2.y==0)) printf("4. testRkRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4);
	if (! (pt2.x == 1 && pt2.y==0)) printf("5. testRkRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5);
	if (! (pt2.x == 1 && pt2.y==1)) printf("6. testRkRegions: getPixel() FAILED, expected 1,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6);
	if (! (pt2.x == 0 && pt2.y==1)) printf("7. testRkRegions: getPixel() FAILED, expected 0,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7);
	if (! (pt2.x == 1 && pt2.y==0)) printf("8. testRkRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);

	// Test upper right
	pt1.x=127; pt1.y=0;
	pt2 = getPixel(pt1, 0);
	if (! (pt2.x == 126 && pt2.y==0)) printf("11. testRkRegions: getPixel() FAILED, expected 126,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1);
	if (! (pt2.x == 127 && pt2.y==1)) printf("12. testRkRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2);
	if (! (pt2.x == 127 && pt2.y==1)) printf("13. testRkRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3);
	if (! (pt2.x == 127 && pt2.y==1)) printf("14. testRkRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4);
	if (! (pt2.x == 127 && pt2.y==1)) printf("15. testRkRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5);
	if (! (pt2.x == 127 && pt2.y==1)) printf("16. testRkRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6);
	if (! (pt2.x == 127 && pt2.y==1)) printf("17. testRkRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7);
	if (! (pt2.x == 126 && pt2.y==1)) printf("18. testRkRegions: getPixel() FAILED, expected 126,1 but was %d,%d\n", pt2.x, pt2.y);

	// Test bottom left
	pt1.x=0; pt1.y=127;
	pt2 = getPixel(pt1, 0);
	if (! (pt2.x == 0 && pt2.y==126)) printf("21. testRkRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1);
	if (! (pt2.x == 0 && pt2.y==126)) printf("22. testRkRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2);
	if (! (pt2.x == 0 && pt2.y==126)) printf("23. testRkRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3);
	if (! (pt2.x == 1 && pt2.y==126)) printf("24. testRkRegions: getPixel() FAILED, expected 1,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4);
	if (! (pt2.x == 1 && pt2.y==127)) printf("25. testRkRegions: getPixel() FAILED, expected 1,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5);
	if (! (pt2.x == 0 && pt2.y==126)) printf("26. testRkRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6);
	if (! (pt2.x == 0 && pt2.y==126)) printf("27. testRkRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7);
	if (! (pt2.x == 0 && pt2.y==126)) printf("28. testRkRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);

	// Test bottom right
	pt1.x=127; pt1.y=127;
	pt2 = getPixel(pt1, 0);
	if (! (pt2.x == 126 && pt2.y==127)) printf("31. testRkRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1);
	if (! (pt2.x == 126 && pt2.y==126)) printf("32. testRkRegions: getPixel() FAILED, expected 126,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2);
	if (! (pt2.x == 127 && pt2.y==126)) printf("33. testRkRegions: getPixel() FAILED, expected 127,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3);
	if (! (pt2.x == 126 && pt2.y==127)) printf("34. testRkRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4);
	if (! (pt2.x == 126 && pt2.y==127)) printf("35. testRkRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5);
	if (! (pt2.x == 126 && pt2.y==127)) printf("36. testRkRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6);
	if (! (pt2.x == 126 && pt2.y==127)) printf("37. testRkRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7);
	if (! (pt2.x == 126 && pt2.y==127)) printf("38. testRkRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
}
