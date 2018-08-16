/*
 * TestRkCharacter.cpp
 *
 */

#include "../src/RkCharacter.h"

void testRkCharacter() {
	printf("\n** TEST CHARACTER **\n");
	printf("--------------------\n");

	RkCharacter* ch1 = new RkCharacter();
	ch1->boundingRectangle = new RkBoundingRectangle(1,1, 10,10);

	RkCharacter* ch2 = new RkCharacter(ch1->boundingRectangle);

	if (1 != ch1->equals(ch2)) printf("RkCharacter: equals() FAILED\n");
	if (9 != ch1->fontSize()) printf("RkCharacter: fontSize() FAILED\n");

}
