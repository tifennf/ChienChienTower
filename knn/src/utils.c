

#include "utils.h"

void swap(float* a, float* b) {
	float tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

void selection_sort(float* array, int len) {
	int i, j;
	int min; // min idx

	for (i = 0; i < len; i++) {

		// we look for minimum's idx
		min = i;
		for (j = i + 1; j < len; j++) {
			if (array[j] < array[min]) {
				min = j;
			}
		}

		// we place min at pos i
		swap(&array[i], &array[min]);
	}
}

float dot_product(float* X, float* Y, int n) {
	float res = 0.0;
	for (int i = 0; i < n; i++) {
		res += X[i] * Y[i];
	}

	return res;
}

float norm2(float* X, int n){
    
}
float cos_dist(float* X, float* Y, int n) {

}