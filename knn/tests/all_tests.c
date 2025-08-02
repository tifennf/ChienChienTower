#include "../unity/unity.h"

void test_convert(void);

void test_swap(void);
void test_selection_sort(void);

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_convert);
	RUN_TEST(test_swap);
	RUN_TEST(test_selection_sort);

	return UNITY_END();
}
