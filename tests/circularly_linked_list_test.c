/**
 * Circularly linked list test suite
 */

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>

#include "circle.h"

// static helper functions here

void test_holder()
{
    // test code here
}

// more test functions here

int main(void)
{
    CU_TestInfo suite1_tests[] = { { "Test Placeholder:", test_holder },
                                   CU_TEST_INFO_NULL };

    CU_SuiteInfo suites[] = {
        { "Suite-1:", NULL, NULL, .pTests = suite1_tests }, CU_SUITE_INFO_NULL
    };

    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    if (0 != CU_register_suites(suites))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_basic_show_failures(CU_get_failure_list());
    int num_failed = CU_get_number_of_failures();
    CU_cleanup_registry();
    printf("\n");
    return num_failed;
}

// end of circularly_linked_list_tests.c
