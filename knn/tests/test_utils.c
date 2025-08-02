#include "../src/utils.h"
#include "../unity/unity.h"

// void setUp(void) {}

// void tearDown(void) {}

// void test_convert(void) {

// 	float a = 0.2;
// 	Q15 q = float_to_Q15(a);

// 	TEST_ASSERT_EQUAL_INT32(6553, q);
// 	TEST_ASSERT_EQUAL_FLOAT(a, Q15_to_float(q));

// 	float theta = 3.14 / 4;
// 	float x = Q15_to_float(float_to_Q15(theta));
// 	TEST_ASSERT_FLOAT_WITHIN(1e-11f, theta, x);
// }

void test_swap(void) {
	float a, b;
	a = 1.0;
	b = 2.0;

	swap(&a, &b);

	TEST_ASSERT_EQUAL_FLOAT(2.0, a);
	TEST_ASSERT_EQUAL_FLOAT(1.0, b);
}

static void check_order(float s[], int len) {
	// test tri ordre croissant
	float last = -1.0;
	for (int i = 0; i < len; i++) {
		TEST_ASSERT_GREATER_OR_EQUAL_FLOAT(last, s[i]);
		last = s[i];
	}
}

void test_selection_sort(void) {
	int len = 5;
	float s[] = {3, 1, 2, 5, 4};

	selection_sort(s, len);
	check_order(s, len);
}