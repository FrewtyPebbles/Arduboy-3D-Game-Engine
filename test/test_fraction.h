#include <unity.h>
#include "fraction.h"
#include "vec2.h"

template<typename N,typename D>
void print_fraction(fraction<N,D> frac) {
    char buf[10];
    sprintf(buf, " %d/%d ", frac.numerator, frac.denominator);
    UnityPrint(buf);
}

// OPERATIONS

void test_add_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    fraction<int8_t, int8_t> frac3 = frac + frac2;
    TEST_ASSERT_TRUE(frac3.numerator == 13 && frac3.denominator == 14);
}

void test_subtract_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    fraction<int8_t, int8_t> frac3 = frac - frac2;
    TEST_ASSERT_TRUE(frac3.numerator == 1 && frac3.denominator == 14);
}

void test_multiply_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    fraction<int8_t, int8_t> frac3 = frac * frac2;
    TEST_ASSERT_TRUE(frac3.numerator == 3 && frac3.denominator == 14);
}

void test_divide_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    fraction<int8_t, int8_t> frac3 = frac / frac2;
    TEST_ASSERT_TRUE(frac3.numerator == 7 && frac3.denominator == 6);
}

void test_eq_add_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    frac += frac2;
    TEST_ASSERT_TRUE(frac.numerator == 13 && frac.denominator == 14);
}

void test_eq_subtract_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    frac -= frac2;
    TEST_ASSERT_TRUE(frac.numerator == 1 && frac.denominator == 14);
}

void test_eq_multiply_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    frac *= frac2;
    TEST_ASSERT_TRUE(frac.numerator == 3 && frac.denominator == 14);
}

void test_eq_divide_2_fractions() {
    fraction<int8_t, int8_t> frac(1, 2);
    fraction<int8_t, int8_t> frac2(3, 7);
    frac /= frac2;
    TEST_ASSERT_TRUE(frac.numerator == 7 && frac.denominator == 6);
}

void test_multiply_fraction_scalar() {
    fraction<int8_t, int8_t> frac(1, 2);
    auto frac2 = frac * 2;
    TEST_ASSERT_TRUE(frac2 == 1);
}

void test_multiply_fraction_scalar2() {
    fraction<int8_t, int8_t> frac(1, 2);
    auto frac2 = frac * 7;
    TEST_ASSERT_TRUE((frac2 == fraction<int8_t, int8_t>(7,2)));
}

void test_add_fraction_scalar() {
    fraction<int8_t, int8_t> frac(1, 2);
    auto frac2 = frac + 2;
    TEST_ASSERT_TRUE((frac2 == fraction<int8_t, int8_t>(5, 2)));
}

void test_add_fraction_scalar2() {
    fraction<int8_t, int8_t> frac(1, 2);
    auto frac2 = frac + 7;
    TEST_ASSERT_TRUE((frac2 == fraction<int8_t, int8_t>(15, 2)));
}

// COMPARISON

void test_fraction_eq_fraction() {
    fraction<int8_t, int8_t> frac1(20, 40);
    fraction<int8_t, int8_t> frac2(1, 2);
    TEST_ASSERT_TRUE(frac1 == frac2);
}

void test_vec2_float_to_fraction() {
    Vec2F16B vec(1.0f, 2.5f);
    TEST_ASSERT_TRUE((vec.x == 1 && vec.y == fraction<int8_t, int8_t>(5,2)));
}

void test_vec2_add_fractions() {
    Vec2F16B vec1(1.0f, 2.5f);
    Vec2F16B vec2(0.33333333f, 2.5f);
    Vec2F16B vec3 = vec1 + vec2;
    TEST_ASSERT_TRUE((vec3.x == fraction<int8_t, int8_t>(4, 3) && vec3.y == fraction<int8_t, int8_t>(10,2)));
}

void test_vec2_multiply_fractions() {
    Vec2F16B vec1(1.0f, 2.5f);
    Vec2F16B vec2(0.33333333f, 2.5f);
    Vec2F16B vec3 = vec1 * vec2;
    TEST_ASSERT_TRUE((vec3.x == fraction<int8_t, int8_t>(1, 3) && vec3.y == fraction<int8_t, int8_t>(25,4)));
}


void run_fraction_tests() {

    RUN_TEST(test_add_2_fractions);
    RUN_TEST(test_subtract_2_fractions);
    RUN_TEST(test_multiply_2_fractions);
    RUN_TEST(test_divide_2_fractions);

    RUN_TEST(test_eq_add_2_fractions);
    RUN_TEST(test_eq_subtract_2_fractions);
    RUN_TEST(test_eq_multiply_2_fractions);
    RUN_TEST(test_eq_divide_2_fractions);

    RUN_TEST(test_fraction_eq_fraction);

    RUN_TEST(test_vec2_float_to_fraction);
    RUN_TEST(test_vec2_add_fractions);
    RUN_TEST(test_vec2_multiply_fractions);

    RUN_TEST(test_multiply_fraction_scalar);
    RUN_TEST(test_multiply_fraction_scalar2);

    RUN_TEST(test_add_fraction_scalar);
    RUN_TEST(test_add_fraction_scalar2);

}
