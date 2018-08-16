/*
 * TestRegions.cpp
 *
 */

#include "../src/Reader.h"
#include "../src/RkBoundingRectangle.h"
#include "../src/Regions.h"

void testGetPixel();

void testRegions() {

	testGetPixel();
}

void testGetPixel() {
	// Test generic point
	CvPoint pt1; pt1.x=10; pt1.y=10;
	CvPoint pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 9 && pt2.y==10)) printf("testRegions: getPixel() FAILED, expected 9,10 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 9 && pt2.y==9)) printf("testRegions: getPixel() FAILED, expected 9,9 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 10 && pt2.y==9)) printf("testRegions: getPixel() FAILED, expected 10,9 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 11 && pt2.y==9)) printf("testRegions: getPixel() FAILED, expected 11,9 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 11 && pt2.y==10)) printf("testRegions: getPixel() FAILED, expected 11,10 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 11 && pt2.y==11)) printf("testRegions: getPixel() FAILED, expected 11,11 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 10 && pt2.y==11)) printf("testRegions: getPixel() FAILED, expected 10,11 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 9 && pt2.y==11)) printf("testRegions: getPixel() FAILED, expected 9,11 but was %d,%d\n", pt2.x, pt2.y);


	// Test upper left
	pt1.x=0; pt1.y=0;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 1 && pt2.y==0)) printf("1. testRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 1 && pt2.y==0)) printf("2. testRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 1 && pt2.y==0)) printf("3. testRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 1 && pt2.y==0)) printf("4. testRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 1 && pt2.y==0)) printf("5. testRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 1 && pt2.y==1)) printf("6. testRegions: getPixel() FAILED, expected 1,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 0 && pt2.y==1)) printf("7. testRegions: getPixel() FAILED, expected 0,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 1 && pt2.y==0)) printf("8. testRegions: getPixel() FAILED, expected 1,0 but was %d,%d\n", pt2.x, pt2.y);

	// Test upper right
	pt1.x=127; pt1.y=0;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 126 && pt2.y==0)) printf("11. testRegions: getPixel() FAILED, expected 126,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 127 && pt2.y==1)) printf("12. testRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 127 && pt2.y==1)) printf("13. testRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 127 && pt2.y==1)) printf("14. testRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 127 && pt2.y==1)) printf("15. testRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 127 && pt2.y==1)) printf("16. testRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 127 && pt2.y==1)) printf("17. testRegions: getPixel() FAILED, expected 127,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 126 && pt2.y==1)) printf("18. testRegions: getPixel() FAILED, expected 126,1 but was %d,%d\n", pt2.x, pt2.y);

	// Test bottom left
	pt1.x=0; pt1.y=127;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 0 && pt2.y==126)) printf("21. testRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 0 && pt2.y==126)) printf("22. testRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 0 && pt2.y==126)) printf("23. testRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 1 && pt2.y==126)) printf("24. testRegions: getPixel() FAILED, expected 1,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 1 && pt2.y==127)) printf("25. testRegions: getPixel() FAILED, expected 1,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 0 && pt2.y==126)) printf("26. testRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 0 && pt2.y==126)) printf("27. testRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 0 && pt2.y==126)) printf("28. testRegions: getPixel() FAILED, expected 0,126 but was %d,%d\n", pt2.x, pt2.y);

	// Test bottom right
	pt1.x=127; pt1.y=127;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 126 && pt2.y==127)) printf("31. testRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 126 && pt2.y==126)) printf("32. testRegions: getPixel() FAILED, expected 126,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 127 && pt2.y==126)) printf("33. testRegions: getPixel() FAILED, expected 127,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 126 && pt2.y==127)) printf("34. testRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 126 && pt2.y==127)) printf("35. testRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 126 && pt2.y==127)) printf("36. testRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 126 && pt2.y==127)) printf("37. testRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 126 && pt2.y==127)) printf("38. testRegions: getPixel() FAILED, expected 126,127 but was %d,%d\n", pt2.x, pt2.y);

	// Test center top
	pt1.x=65; pt1.y=0;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 64 && pt2.y==0)) printf("1. testRegions: getPixel() FAILED, expected 64,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 66 && pt2.y==0)) printf("2. testRegions: getPixel() FAILED, expected 66,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 65 && pt2.y==1)) printf("3. testRegions: getPixel() FAILED, expected 66,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 66 && pt2.y==0)) printf("4. testRegions: getPixel() FAILED, expected 66,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 66 && pt2.y==0)) printf("5. testRegions: getPixel() FAILED, expected 66,0 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 66 && pt2.y==1)) printf("6. testRegions: getPixel() FAILED, expected 66,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 65 && pt2.y==1)) printf("7. testRegions: getPixel() FAILED, expected 0,1 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 64 && pt2.y==1)) printf("8. testRegions: getPixel() FAILED, expected 64,1 but was %d,%d\n", pt2.x, pt2.y);

	// Test center right
	pt1.x=127; pt1.y=65;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 126 && pt2.y==65)) printf("11. testRegions: getPixel() FAILED, expected 126,65 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 126 && pt2.y==64)) printf("12. testRegions: getPixel() FAILED, expected 126,64 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 127 && pt2.y==64)) printf("13. testRegions: getPixel() FAILED, expected 127,64 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 127 && pt2.y==66)) printf("14. testRegions: getPixel() FAILED, expected 127,66 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 126 && pt2.y==65)) printf("15. testRegions: getPixel() FAILED, expected 126,65 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 127 && pt2.y==66)) printf("16. testRegions: getPixel() FAILED, expected 127,66 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 127 && pt2.y==66)) printf("17. testRegions: getPixel() FAILED, expected 127,66 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 126 && pt2.y==66)) printf("18. testRegions: getPixel() FAILED, expected 126,66 but was %d,%d\n", pt2.x, pt2.y);

	// Test center bottom
	pt1.x=65; pt1.y=127;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 64 && pt2.y==127)) printf("21. testRegions: getPixel() FAILED, expected 64,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 64 && pt2.y==126)) printf("22. testRegions: getPixel() FAILED, expected 64,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 65 && pt2.y==126)) printf("23. testRegions: getPixel() FAILED, expected 65,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 66 && pt2.y==126)) printf("24. testRegions: getPixel() FAILED, expected 66,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 66 && pt2.y==127)) printf("25. testRegions: getPixel() FAILED, expected 66,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 64 && pt2.y==127)) printf("26. testRegions: getPixel() FAILED, expected 64,127 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 65 && pt2.y==126)) printf("27. testRegions: getPixel() FAILED, expected 65,126 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 64 && pt2.y==127)) printf("28. testRegions: getPixel() FAILED, expected 64,127 but was %d,%d\n", pt2.x, pt2.y);

	// Test center left
	pt1.x=0; pt1.y=65;
	pt2 = getPixel(pt1, 0, 128, 128);
	if (! (pt2.x == 1 && pt2.y==65)) printf("31. testRegions: getPixel() FAILED, expected 1,65 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 1, 128, 128);
	if (! (pt2.x == 0 && pt2.y==64)) printf("32. testRegions: getPixel() FAILED, expected 0,64 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 2, 128, 128);
	if (! (pt2.x == 0 && pt2.y==64)) printf("33. testRegions: getPixel() FAILED, expected 0,64 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 3, 128, 128);
	if (! (pt2.x == 1 && pt2.y==64)) printf("34. testRegions: getPixel() FAILED, expected 1,64 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 4, 128, 128);
	if (! (pt2.x == 1 && pt2.y==65)) printf("35. testRegions: getPixel() FAILED, expected 1,65 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 5, 128, 128);
	if (! (pt2.x == 1 && pt2.y==66)) printf("36. testRegions: getPixel() FAILED, expected 1,66 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 6, 128, 128);
	if (! (pt2.x == 0 && pt2.y==66)) printf("37. testRegions: getPixel() FAILED, expected 0,66 but was %d,%d\n", pt2.x, pt2.y);
	pt2 = getPixel(pt1, 7, 128, 128);
	if (! (pt2.x == 0 && pt2.y==64)) printf("38. testRegions: getPixel() FAILED, expected 0,64 but was %d,%d\n", pt2.x, pt2.y);
}
