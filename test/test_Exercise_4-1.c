#ifdef TEST

#include "unity.h"

#include "Exercise_4-1.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Exercise_4_1_NeedToImplement(void)
{
#define MAXLEN 1000

    char s[MAXLEN] = {"uno dos tres uno dos tres uno dos tres uno dos tres"};
    char t1[MAXLEN] = {"uno"};
    char t2[MAXLEN] = {"dos"};
    char t3[MAXLEN] = {"tres"};

    TEST_ASSERT_EQUAL_INT16_MESSAGE (39, strindex(s, t1), "test 1 exercise 4.1");
    TEST_ASSERT_EQUAL_INT16_MESSAGE (43, strindex(s, t2), "test 2 exercise 4.1");
    TEST_ASSERT_EQUAL_INT16_MESSAGE (47, strindex(s, t3), "test 3 exercise 4.1");

}

#endif // TEST
