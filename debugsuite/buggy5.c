#include <stdio.h>
#include <assert.h>

#define      ADD(a,b) a + b
#define SUBTRACT(a,b) a - b
#define MULTIPLY(a,b) a * b
#define   DIVIDE(a,b) a / b
#define      MOD(a,b) a % b
#define   SQUARE(a  ) MULTIPLY(a,a)

#define ZERO  0
#define ONE   1
#define TWO   ADD(ONE,   1)
#define THREE ADD(TWO,   1)
#define FOUR  ADD(THREE, 1)
#define FIVE  ADD(FOUR,  1)
#define SIX   ADD(FIVE,  1)
#define SEVEN ADD(SIX,   1)
#define EIGHT ADD(SEVEN, 1)
#define NINE  ADD(EIGHT, 1)
#define TEN   ADD(NINE,  1)


int main(int argc, char *argv[]) {

	/**
	 * Some tests.
	 */

	int actual, expected;

	// 2 + 3
	actual   = ADD(TWO, THREE);
	expected = FIVE;
	assert(actual == expected);

	// (8 + 3) - 2
	actual   = SUBTRACT(ADD(EIGHT, THREE), TWO);
	expected = NINE;
	assert(actual == expected);

	// 2 * (2 + 3)
	actual   = MULTIPLY(TWO, ADD(TWO, THREE));
	expected = TEN;
	assert(actual == expected);

	// (5 + 8) % 2
	actual   = MOD(ADD(FIVE, EIGHT), TWO);
	expected = ONE;
	assert(actual == expected);

	// (2 + 1)^2 squared
	actual   = SQUARE(ADD(TWO, ONE));
	expected = NINE;
	assert(actual == expected);

	printf("No assertions fired!\n");

	return 0;
}
