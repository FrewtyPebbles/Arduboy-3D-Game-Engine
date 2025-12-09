#include <unity.h>
#include "fraction_utilities.h"
#include <math.h>
#include <stdio.h>

// Helper function to compare fractions with a tolerance
template<typename Num, typename Den>
void assert_is_close(const fraction<Num, Den>& f, float expected, float tolerance = 0.01f) {
    float actual = static_cast<float>(f.numerator) / static_cast<float>(f.denominator);
    float diff = fabs(actual - expected);
    
    // Debug output
    char buffer[128];
    sprintf(buffer, "Expected: %.4f, Actual: %.4f (%ld/%ld), Diff: %.4f, Tolerance: %.4f", 
            expected, actual, (long)f.numerator, (long)f.denominator, diff, tolerance);
    
    TEST_ASSERT_TRUE_MESSAGE(diff < tolerance, buffer);
}

// ========== Factorial Tests ==========
void test_factorial_base_case(void) {
    TEST_ASSERT_EQUAL(1, Utility::factorial<int>(0));
    TEST_ASSERT_EQUAL(1, Utility::factorial<int>(1));
}

void test_factorial_small_values(void) {
    TEST_ASSERT_EQUAL(2, Utility::factorial<int>(2));
    TEST_ASSERT_EQUAL(6, Utility::factorial<int>(3));
    TEST_ASSERT_EQUAL(24, Utility::factorial<int>(4));
    TEST_ASSERT_EQUAL(120, Utility::factorial<int>(5));
    TEST_ASSERT_EQUAL(720, Utility::factorial<int>(6));
}

void test_factorial_large_values(void) {
    TEST_ASSERT_EQUAL(3628800, Utility::factorial<int32_t>(10));
}

// ========== Sin Tests ==========
void test_sin_zero(void) {
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::sin(x);
    assert_is_close(result, 0.0f, 0.001f);
}

void test_sin_pi_over_6(void) {
    // sin(π/6) ≈ 0.5
    fraction<int32_t, int32_t> x(355, 678); // π/6 ≈ 355/678
    auto result = Utility::sin(x);
    assert_is_close(result, 0.5f, 0.15f);
}

void test_sin_pi_over_4(void) {
    // sin(π/4) ≈ 0.707
    fraction<int32_t, int32_t> x(355, 452); // π/4 ≈ 355/452
    auto result = Utility::sin(x);
    assert_is_close(result, 0.707f, 0.15f);
}

void test_sin_pi_over_2(void) {
    // sin(π/2) ≈ 1.0
    fraction<int32_t, int32_t> x(157, 100); // Use 1.57 ≈ π/2
    auto result = Utility::sin(x);
    assert_is_close(result, 1.0f, 0.15f);
}

void test_sin_negative(void) {
    // sin(-π/6) ≈ -0.5
    fraction<int32_t, int32_t> x(-355, 678);
    auto result = Utility::sin(x);
    assert_is_close(result, -0.5f, 0.15f);
}

// ========== Cos Tests ==========
void test_cos_zero(void) {
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::cos(x);
    assert_is_close(result, 1.0f, 0.001f);
}

void test_cos_pi_over_6(void) {
    // cos(π/6) ≈ 0.866
    fraction<int32_t, int32_t> x(52, 100); // Use 0.52 ≈ π/6
    auto result = Utility::cos(x);
    assert_is_close(result, 0.866f, 0.15f);
}

void test_cos_pi_over_4(void) {
    // cos(π/4) ≈ 0.707
    fraction<int32_t, int32_t> x(79, 100); // Use 0.79 ≈ π/4
    auto result = Utility::cos(x);
    assert_is_close(result, 0.707f, 0.15f);
}

void test_cos_pi_over_2(void) {
    // cos(π/2) ≈ 0.0
    fraction<int32_t, int32_t> x(157, 100); // Use 1.57 ≈ π/2
    auto result = Utility::cos(x);
    assert_is_close(result, 0.0f, 0.15f);
}

void test_cos_pi(void) {
    // cos(π) ≈ -1.0
    fraction<int32_t, int32_t> x(314, 100); // Use 3.14 ≈ π
    auto result = Utility::cos(x);
    assert_is_close(result, -1.0f, 0.15f);
}

// ========== Tan Tests ==========
void test_tan_zero(void) {
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::tan(x, 10);
    assert_is_close(result, 0.0f, 0.001f);
}

void test_tan_pi_over_4(void) {
    // tan(π/4) ≈ 1.0
    fraction<int32_t, int32_t> x(79, 100); // Use 0.79 ≈ π/4
    auto result = Utility::tan(x, 15);
    assert_is_close(result, 1.0f, 0.2f);
}

void test_tan_pi_over_6(void) {
    // tan(π/6) ≈ 0.577
    fraction<int32_t, int32_t> x(52, 100); // Use 0.52 ≈ π/6
    auto result = Utility::tan(x, 15);
    assert_is_close(result, 0.577f, 0.15f);
}

// ========== Atan Tests ==========
void test_atan_zero(void) {
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::atan(x);
    assert_is_close(result, 0.0f, 0.01f);
}

void test_atan_one(void) {
    // atan(1) ≈ π/4 ≈ 0.785
    fraction<int32_t, int32_t> x(1);
    auto result = Utility::atan(x);
    assert_is_close(result, 0.785f, 0.1f);
}

void test_atan_small_positive(void) {
    // atan(0.5) ≈ 0.464
    fraction<int32_t, int32_t> x(1, 2);
    auto result = Utility::atan(x);
    assert_is_close(result, 0.464f, 0.15f);
}

void test_atan_negative(void) {
    // atan(-1) ≈ -π/4 ≈ -0.785
    fraction<int32_t, int32_t> x(-1);
    auto result = Utility::atan(x);
    assert_is_close(result, -0.785f, 0.1f);
}

// ========== Atan2 Tests ==========
void test_atan2_first_quadrant(void) {
    fraction<int32_t, int32_t> y(1);
    fraction<int32_t, int32_t> x(1);
    auto result = Utility::atan2(y, x);
    assert_is_close(result, 0.785f, 0.1f); // π/4
}

void test_atan2_second_quadrant(void) {
    fraction<int32_t, int32_t> y(1);
    fraction<int32_t, int32_t> x(-1);
    auto result = Utility::atan2(y, x);
    assert_is_close(result, 2.356f, 0.2f); // 3π/4
}

void test_atan2_third_quadrant(void) {
    fraction<int32_t, int32_t> y(-1);
    fraction<int32_t, int32_t> x(-1);
    auto result = Utility::atan2(y, x);
    assert_is_close(result, -2.356f, 0.2f); // -3π/4
}

void test_atan2_fourth_quadrant(void) {
    fraction<int32_t, int32_t> y(-1);
    fraction<int32_t, int32_t> x(1);
    auto result = Utility::atan2(y, x);
    assert_is_close(result, -0.785f, 0.1f); // -π/4
}

void test_atan2_positive_y_axis(void) {
    fraction<int32_t, int32_t> y(1);
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::atan2(y, x);
    assert_is_close(result, 1.571f, 0.1f); // π/2
}

void test_atan2_negative_y_axis(void) {
    fraction<int32_t, int32_t> y(-1);
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::atan2(y, x);
    assert_is_close(result, -1.571f, 0.1f); // -π/2
}

void test_atan2_origin(void) {
    fraction<int32_t, int32_t> y(0);
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::atan2(y, x);
    assert_is_close(result, 0.0f, 0.001f);
}

// ========== Asin Tests ==========
void test_asin_zero(void) {
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::asin(x);
    assert_is_close(result, 0.0f, 0.001f);
}

void test_asin_half(void) {
    // asin(0.5) ≈ π/6 ≈ 0.524
    fraction<int32_t, int32_t> x(1, 2);
    auto result = Utility::asin(x);
    assert_is_close(result, 0.524f, 0.1f);
}

void test_asin_small_value(void) {
    // asin(0.25) ≈ 0.253
    fraction<int32_t, int32_t> x(1, 4);
    auto result = Utility::asin(x);
    assert_is_close(result, 0.253f, 0.05f);
}

void test_asin_negative(void) {
    // asin(-0.5) ≈ -π/6 ≈ -0.524
    fraction<int32_t, int32_t> x(-1, 2);
    auto result = Utility::asin(x);
    assert_is_close(result, -0.524f, 0.1f);
}

// ========== Acos Tests ==========
void test_acos_zero(void) {
    // acos(0) ≈ π/2 ≈ 1.571
    fraction<int32_t, int32_t> x(0);
    auto result = Utility::acos(x);
    assert_is_close(result, 1.571f, 0.1f);
}

void test_acos_half(void) {
    // acos(0.5) ≈ π/3 ≈ 1.047
    fraction<int32_t, int32_t> x(1, 2);
    auto result = Utility::acos(x);
    assert_is_close(result, 1.047f, 0.1f);
}

void test_acos_one(void) {
    // acos(1) ≈ 0
    fraction<int32_t, int32_t> x(1);
    auto result = Utility::acos(x);
    assert_is_close(result, 0.0f, 0.2f);
}

// ========== Wrap Euler Angle Degrees Tests ==========
void test_wrap_degrees_zero(void) {
    TEST_ASSERT_EQUAL(0, Utility::wrap_euler_angle_degrees(0));
}

void test_wrap_degrees_positive_in_range(void) {
    TEST_ASSERT_EQUAL(45, Utility::wrap_euler_angle_degrees(45));
    TEST_ASSERT_EQUAL(180, Utility::wrap_euler_angle_degrees(180));
    TEST_ASSERT_EQUAL(270, Utility::wrap_euler_angle_degrees(270));
}

void test_wrap_degrees_exact_rotation(void) {
    TEST_ASSERT_EQUAL(0, Utility::wrap_euler_angle_degrees(360));
    TEST_ASSERT_EQUAL(0, Utility::wrap_euler_angle_degrees(720));
}

void test_wrap_degrees_more_than_rotation(void) {
    TEST_ASSERT_EQUAL(90, Utility::wrap_euler_angle_degrees(450));
    TEST_ASSERT_EQUAL(90, Utility::wrap_euler_angle_degrees(810));
}

void test_wrap_degrees_negative(void) {
    TEST_ASSERT_EQUAL(315, Utility::wrap_euler_angle_degrees(-45));
    TEST_ASSERT_EQUAL(270, Utility::wrap_euler_angle_degrees(-90));
    TEST_ASSERT_EQUAL(0, Utility::wrap_euler_angle_degrees(-360));
    TEST_ASSERT_EQUAL(270, Utility::wrap_euler_angle_degrees(-450));
}

// ========== Wrap Euler Angle Radians Tests ==========
void test_wrap_radians_zero(void) {
    fraction<int32_t, int32_t> angle(0);
    auto result = Utility::wrap_euler_angle_radians(angle);
    assert_is_close(result, 0.0f, 0.001f);
}

void test_wrap_radians_small_positive(void) {
    fraction<int32_t, int32_t> angle(1, 2); // 0.5 radians
    auto result = Utility::wrap_euler_angle_radians(angle);
    assert_is_close(result, 0.5f, 0.01f);
}

void test_wrap_radians_pi(void) {
    fraction<int32_t, int32_t> angle(355, 113); // π
    auto result = Utility::wrap_euler_angle_radians(angle);
    assert_is_close(result, 3.14159f, 0.1f);
}

void test_wrap_radians_two_pi(void) {
    fraction<int32_t, int32_t> angle(710, 113); // 2π
    auto result = Utility::wrap_euler_angle_radians(angle);
    assert_is_close(result, 0.0f, 0.1f);
}

void test_wrap_radians_more_than_two_pi(void) {
    // 3π should wrap to π
    fraction<int32_t, int32_t> angle(1065, 113);
    auto result = Utility::wrap_euler_angle_radians(angle);
    assert_is_close(result, 3.14159f, 0.2f);
}

void test_wrap_radians_negative(void) {
    // -π/4 should stay as -π/4
    fraction<int32_t, int32_t> angle(-355, 452);
    auto result = Utility::wrap_euler_angle_radians(angle);
    assert_is_close(result, -0.785f, 0.1f);
}

// ========== Main Test Runner ==========
void run_fraction_utility_tests() {
    
    // Factorial tests
    RUN_TEST(test_factorial_base_case);
    RUN_TEST(test_factorial_small_values);
    RUN_TEST(test_factorial_large_values);
    
    // Sin tests
    RUN_TEST(test_sin_zero);
    RUN_TEST(test_sin_pi_over_6);
    RUN_TEST(test_sin_pi_over_4);
    RUN_TEST(test_sin_pi_over_2);
    RUN_TEST(test_sin_negative);
    
    // Cos tests
    RUN_TEST(test_cos_zero);
    RUN_TEST(test_cos_pi_over_6);
    RUN_TEST(test_cos_pi_over_4);
    RUN_TEST(test_cos_pi_over_2);
    RUN_TEST(test_cos_pi);
    
    // Tan tests
    RUN_TEST(test_tan_zero);
    RUN_TEST(test_tan_pi_over_4);
    RUN_TEST(test_tan_pi_over_6);
    
    // Atan tests
    RUN_TEST(test_atan_zero);
    RUN_TEST(test_atan_one);
    RUN_TEST(test_atan_small_positive);
    RUN_TEST(test_atan_negative);
    
    // Atan2 tests
    RUN_TEST(test_atan2_first_quadrant);
    RUN_TEST(test_atan2_second_quadrant);
    RUN_TEST(test_atan2_third_quadrant);
    RUN_TEST(test_atan2_fourth_quadrant);
    RUN_TEST(test_atan2_positive_y_axis);
    RUN_TEST(test_atan2_negative_y_axis);
    RUN_TEST(test_atan2_origin);
    
    // Asin tests
    RUN_TEST(test_asin_zero);
    RUN_TEST(test_asin_half);
    RUN_TEST(test_asin_small_value);
    RUN_TEST(test_asin_negative);
    
    // Acos tests
    RUN_TEST(test_acos_zero);
    RUN_TEST(test_acos_half);
    RUN_TEST(test_acos_one);
    
    // Wrap degrees tests
    RUN_TEST(test_wrap_degrees_zero);
    RUN_TEST(test_wrap_degrees_positive_in_range);
    RUN_TEST(test_wrap_degrees_exact_rotation);
    RUN_TEST(test_wrap_degrees_more_than_rotation);
    RUN_TEST(test_wrap_degrees_negative);
    
    // Wrap radians tests
    RUN_TEST(test_wrap_radians_zero);
    RUN_TEST(test_wrap_radians_small_positive);
    RUN_TEST(test_wrap_radians_pi);
    RUN_TEST(test_wrap_radians_two_pi);
    RUN_TEST(test_wrap_radians_more_than_two_pi);
    RUN_TEST(test_wrap_radians_negative);
}
