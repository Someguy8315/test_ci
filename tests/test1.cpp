#include <gtest/gtest.h>
#include "func.h"

TEST(basic_test_suite, sanity_checks1)
{
    int arr[3];
    arr[2] = 5;

    int value = getValue();
    EXPECT_EQ(value, 500);
}
