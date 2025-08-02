#include "knn.h"
#include <stdlib.h>

// There will be only one example by dog, None is a blank class without any example
struct _KNN_Classifier {
	int k;
	float* desc_set[MAX_EXAMPLE];
	int label_set[MAX_EXAMPLE];
	int nb_ex;
};

KNN_Classifier* init_knn(int k) {
	KNN_Classifier* res = malloc(sizeof(KNN_Classifier));
	res->k = k;
	res->nb_ex = 0;
	for (int i = 0; i < MAX_EXAMPLE; i++) {
		res->desc_set[i] = NULL;
		res->label_set[i] = -1;
	}

	return res;
}

void train_knn(KNN_Classifier* knn, float** desc_set, int* label_set, int len) {
	for (int i = 0; i < len; i++) {
		knn->desc_set[i] = desc_set[i];
		knn->label_set[i] = label_set[i];
		knn->nb_ex += 1;
	}
}

// bubble sort implementation in-place
void sort_dist(float* d, int len) {

	for (int k = 0; k < len; k++) {
		int i = 0;
		int j = 1;
		float tmp;
		while (i < len && j < len) {
			if (d[i] > d[j]) {
				tmp = d[j];
				d[j] = d[i];
				d[i] = tmp;
			}

			i++;
			j++;
		}
	}
}

int* score(KNN_Classifier* knn, float* X) {

	// float dists[MAX_EXAMPLE] = {0};

	// // Cos distance between X and all examples
	// for (int i = 0; i < knn->nb_ex; i++) {
	// 	dists[i] = cos_dist(knn->desc_set[i], X);
	// }

	// tak
}

// Distance entre
int predict(KNN_Classifier* knn, float* X) {
	// float dists[MAX_EXAMPLE] = {0};

	// // Cos distance between X and all examples
	// for (int i = 0; i < knn->nb_ex; i++) {
	// 	dists[i] = cos_dist(knn->desc_set[i], X);
	// }
}