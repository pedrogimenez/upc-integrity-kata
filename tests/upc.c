#include "framework/clar.h"
#include "../lib/upc.h"

void test_upc__it_returns_true_when_the_upc_is_valid(void)
{
    cl_assert_(check_upc_integrity("013800151735"), "The upc is not valid.");
}

void test_upc__it_returns_false_when_the_upc_has_less_than_twelve_digits(void)
{
    cl_assert_(check_upc_integrity("01380") == false, "The upc has less than 12 digits.");
}

void test_upc__it_returns_false_when_the_upc_has_more_than_twelve_digits(void)
{
    cl_assert_(check_upc_integrity("0138001517359") == false, "The upc has more than 12 digits.");
}
