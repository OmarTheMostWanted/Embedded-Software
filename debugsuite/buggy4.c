#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Fill array with random numbers.
 *
 * @param size The size of the array 'array'.
 * @param array Pointer to the array.
 */
void fill_array_random(int size, int *array) {
	for (int i = 0; i < size; ++i) {
		array[i] = rand();
	}
}

int main(int argc, char *argv[]) {

	// Initialize random generator.
	srand(time(NULL));

	const int size = 10;
	int * my_array = (int *) malloc(size);

	// Fill the array with random numbers.
	fill_array_random(size, my_array);

	// Print array.
	printf("Array:\n");
	for (int i = 0; i < size; ++i) {
		printf("[%d]: %d\n", i, my_array[i]);
	}

	// Free array.
	for (int i = 0; i < size; ++i) {
		free(my_array[i]);
	}

}
