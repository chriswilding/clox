#include "vendor/unity.h"
#include "../src/example.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_example(void)
{
    int input = 123;
    TEST_ASSERT_EQUAL_INT(example(input), input);
}

int main(void)
{
    UnityBegin("test/test_example.c");

    RUN_TEST(test_example);

    return UnityEnd();
}
