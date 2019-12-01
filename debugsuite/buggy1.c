#include <stdint.h>
#include <assert.h>

/**
 * Increment integer.
 *
 * @param j The integer to increment.
 *
 * @return The result of j incremented.
 */
int16_t increment(int16_t j) {
	return j++;
}

int main(int argc, char *argv[]) {

	const int n_increments = 100000; // Increment 100000 times.

	int16_t old_value = 0;
	int16_t new_value = 0;

	for (int i = 0; i < n_increments; ++i) {
		new_value = increment(old_value);
		assert(new_value == old_value + 1);
		old_value = new_value;
	}

	return 0;
}
