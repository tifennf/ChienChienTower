#include "../src/fixedpoint.h"
#include "../unity/unity.h"

void setUp(void) {}

void tearDown(void) {}

void test_convert(void) {
	float eps = 0.001;

	float a = 0.2;
	Q15 q = float_to_Q15(a);
	float p = Q15_to_float(q);

	TEST_ASSERT_EQUAL_INT32(6553, q);
	TEST_ASSERT_FLOAT_WITHIN(eps, a, p);

	float theta = 3.14 / 4;
	float x = Q15_to_float(float_to_Q15(theta));
	TEST_ASSERT_FLOAT_WITHIN(eps, theta, x);
}
