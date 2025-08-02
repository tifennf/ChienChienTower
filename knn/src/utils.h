#ifndef __UTILS__
#define __UTILS__

void swap(float* a, float* b);

void selection_sort(float array[], int len);

float dot_product(float* X, float* Y, int n);
float norm2(float* X, int n);

float cos_dist(float* X, float* Y, int n);

#endif