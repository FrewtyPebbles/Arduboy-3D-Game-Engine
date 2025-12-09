#define UNITY_VERBOSE
#include <unity.h>
#include "test_fraction.h"
#include "test_fraction_utilities.h"

void setUp(void) {

}

void tearDown(void) {
    // clean stuff up here
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    run_fraction_tests();
    run_fraction_utility_tests();

    UNITY_END();
}