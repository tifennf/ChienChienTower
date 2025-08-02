#ifndef __FIXED_POINT__
#define __FIXED_POINT__

#include <stdint.h>

typedef int16_t Q15;
// SCALE is 2^15
#define SCALE 32768

// Convert from float to fixed point format Q31
// Assume f is between 0 and 1
Q15 float_to_Q15(float f);

// Convert from Q31 to float (approximation)
float Q15_to_float(Q15 q);

Q15 add_Q15(Q15 a, Q15 b);

#endif
