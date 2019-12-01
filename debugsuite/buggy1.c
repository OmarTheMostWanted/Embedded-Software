#include <stdint.h>
#include <assert.h>
#include <stdio.h>

/**
 * Increment integer.
 *
 * @param j The integer to increment.
 *
 * @return The result of j incremented.
 */
int16_t increment(int16_t j) {

    //this does not work
    //return j++;

    return j+1; //FIX
}

int main(int argc, char *argv[]) {

    //this is breaking the code.
    //const int n_increments = 100000; // Increment 100000 times.

    const int n_increments = 32767; // FIX: an overflow occures after 32767 causing the number to become -32768

    int16_t old_value = 0;
    int16_t new_value = 0;

    for (int i = 0; i < n_increments; ++i) {
        new_value = increment(old_value);
        assert(new_value == old_value + 1);
        old_value = new_value;
    }

    return 0;
}
