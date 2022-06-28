#ifdef TEST

#define UNITY_INCLUDE_DOUBLE
#include "unity.h"

#include "exercise_4-2.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_exercise_4_2_NeedToImplement(void)
{
#define MAXLEN 1000

    char t1[MAXLEN] = {"0.0"};
    char t2[MAXLEN] = {"187.97754"};
    char t3[MAXLEN] = {"-187.97754"};
    char t4[MAXLEN] = {"18797754e-5"};
    char t5[MAXLEN] = {"18797754E-5"};
    char t6[MAXLEN] = {"-18797754e-5"};
    char t7[MAXLEN] = {"-18797754E-5"};

    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(0.0, atof(t1), "t1");
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(187.97754, atof(t2), "t2" );
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(-187.97754, atof(t3), "t3" );
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(187.97754, atof(t4), "t4" );
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(187.97754, atof(t5), "t5" );
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(-187.97754, atof(t6), "t6" );
    TEST_ASSERT_EQUAL_DOUBLE_MESSAGE(-187.97754, atof(t7), "t7" );
}

#endif // TEST
