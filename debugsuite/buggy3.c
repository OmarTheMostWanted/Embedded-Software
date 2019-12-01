#include <stdio.h>
#include <stdlib.h>

/**
 * Calculate mean of percentages (the sum of all percentages divided by the
 * number of percentages).
 *
 * @param n_percentages The number of percentages given in array 'percentages'.
 * @param percentages   Array of percentages.
 */
int mean_percentage(int n_percentages, int percentages[]) {
	int sum = 0;
	for (int i = 0; i < n_percentages; ++i) {
		sum += percentages[i];
	}
	return sum / n_percentages;
}

int main(int argc, char *argv[]) {

	const int n_percentages = 3;
	int * percentages = (int *) malloc(sizeof(int) * n_percentages);

	// Hardcode some percentages.
	percentages[0] = 023; //  23 percent.
	percentages[1] = 100; // 100 percent.
	percentages[2] = 065; //  65 percent.

	int mean = mean_percentage(n_percentages, percentages);
	printf("Mean: %d\n", mean);

	free(percentages);

	return 0;
}
