#include "fixedpoint.h"

Q15 float_to_Q15(float f) { return (Q15)(f * SCALE); }

float Q15_to_float(Q15 q) { return ((float)q) / SCALE; }

// Perform addition of Q15 numbers a and b
Q15 add_Q15(Q15 a, Q15 b) {
	float x, y;

	x = Q15_to_float(a);
	y = Q15_to_float(b);

	return float_to_Q15(x + y);
}

// Perform multiplication of Q31 numbers a and b
Q15 mult_Q15(Q15 a, Q15 b) {
	float x, y;

	x = Q15_to_float(a);
	y = Q15_to_float(b);

	return float_to_Q15(x * y);
}
