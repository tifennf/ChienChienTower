#ifndef __PRECISION__
#define __PRECISION__

#define NB_CLASS 6 // 0: Roseline 1: Milo 2: Rebecca: 3: Ratatin 4: Nina 5: None
#define MAX_EXAMPLE NB_CLASS - 1

typedef struct _KNN_Classifier KNN_Classifier;

// Initialize a KNN classifier with k as the number of neiborgs to looks for.
KNN_Classifier* init_knn(int k);

// Train a KNN with a description set and a label set
void train_knn(KNN_Classifier* knn, float** desc_set, int* label_set, int len);

// Return occurence of each class for k nearest neighors of X
int* score(KNN_Classifier* knn, float* X);

// Predict a class for X
int predict(KNN_Classifier* knn, float* X);

#endif
