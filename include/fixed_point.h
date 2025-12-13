#pragma once

#include <cstdint>
#include "types.h"
#include "math.h"

// HELPER FOR COMPILE TIME SHIFT direction changing
template<bool Negative>
struct shift_switch;

template<>
struct shift_switch<true> {
    template<typename T, typename U>
    static T apply(T value, U d) { return value >> abs(d); }
};

template<>
struct shift_switch<false> {
    template<typename T, typename U>
    static T apply(T value, U d) { return value << d; }
};

template<typename T, uint8_t PRECISION>
class fixed {
public:
    fixed() = default;
    fixed(const T& value) : value(value) {}
    fixed(const fixed& other) : value(other.value) {}

    static constexpr fixed float_to_fixed(float f) {
        return fixed(round(f * (1 << PRECISION) + (f >= 0 ? 0.5 : -0.5)));
    }
    static constexpr fixed int_to_fixed(T i) {
        return fixed(i << PRECISION);
    }
    static constexpr float fixed_to_float(fixed fx) {
        return float(fx) / float(1 << PRECISION);
    }

    static constexpr fixed PI = float_to_fixed(3.14159265359f);
    static constexpr fixed HALF_PI = float_to_fixed(1.57079632679f);

    T floor() {
        return value >> PRECISION;
    }

    T ceil() {
        // get only fraction part and check if greater than 0
        constexpr T int_size = sizeof(T) * 8 - PRECISION;
        return (value << int_size) == 0 ?  floor() : floor() + 1;
    }

    fixed abs() {
        return (*this < 0) ? -*this : *this
    }



    // OPERATORS
    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    fixed operator/(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        auto a = Utility::Types::upcast<T>(this->value);
        auto b = Utility::Types::upcast<T_OTHER>(
            shift_switch<(PRECISION - PRECISION_OTHER < 0)>::apply(
                other.value, PRECISION - PRECISION_OTHER
            )
        );
        return Utility::Types::choose_larger_type<fixed, fixed<T_OTHER, PRECISION_OTHER>>(
            (a / b) << PRECISION
        );
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    fixed operator%(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        auto a = Utility::Types::upcast<T>(this->value);
        auto b = Utility::Types::upcast<T_OTHER>(
            shift_switch<(PRECISION - PRECISION_OTHER < 0)>::apply(
                other.value, PRECISION - PRECISION_OTHER
            )
        );
        return Utility::Types::choose_larger_type<fixed, fixed<T_OTHER, PRECISION_OTHER>>(
            a - (a / b) * b
        );
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    fixed operator*(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        auto a = Utility::Types::upcast<T>(this->value);
        auto b = Utility::Types::upcast<T_OTHER>(
            shift_switch<(PRECISION - PRECISION_OTHER < 0)>::apply(
                other.value, PRECISION - PRECISION_OTHER
            )
        );
        return Utility::Types::choose_larger_type<fixed, fixed<T_OTHER, PRECISION_OTHER>>(
            (a * b) >> PRECISION
        );
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    fixed operator+(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        auto b = shift_switch<(PRECISION - PRECISION_OTHER < 0)>::apply(
            other.value, PRECISION - PRECISION_OTHER
        );
        return Utility::Types::choose_larger_type<fixed, fixed<T_OTHER, PRECISION_OTHER>>(
            (this->value + b)
        );
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    fixed operator-(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        auto b = shift_switch<(PRECISION - PRECISION_OTHER < 0)>::apply(
            other.value, PRECISION - PRECISION_OTHER
        );
        return Utility::Types::choose_larger_type<fixed, fixed<T_OTHER, PRECISION_OTHER>>(
            (this->value - b)
        );
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    fixed operator-() const {
        return fixed(-this->value);
    }

    // COMPARISONS

    // // FIXED VS FIXED

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    bool operator==(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        return this->value == other.value;
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    bool operator<=(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        return this->value <= other.value;
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    bool operator>=(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        return this->value >= other.value;
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    bool operator<(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        return this->value < other.value;
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    bool operator>(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        return this->value == other.value;
    }

    template<typename T_OTHER, uint8_t PRECISION_OTHER>
    bool operator!=(const fixed<T_OTHER, PRECISION_OTHER> & other) const {
        return this->value == other.value;
    }

    // // FIXED VS INT:

    template<typename T_OTHER>
    bool operator==(const T_OTHER & other) const {
        return this->value == (other << PRECISION);
    }

    template<typename T_OTHER>
    bool operator<=(const T_OTHER & other) const {
        return this->value <= (other << PRECISION);
    }

    template<typename T_OTHER>
    bool operator>=(const T_OTHER & other) const {
        return this->value >= (other << PRECISION);
    }

    template<typename T_OTHER>
    bool operator<(const T_OTHER & other) const {
        return this->value < (other << PRECISION);
    }

    template<typename T_OTHER>
    bool operator>(const T_OTHER & other) const {
        return this->value > (other << PRECISION);
    }

    template<typename T_OTHER>
    bool operator!=(const T_OTHER & other) const {
        return this->value != (other << PRECISION);
    }

private:
    T value;
};

// Literals

// // int8

constexpr fixed<int8_t, 1> operator"" fxp8_1(long double value) {
    return fixed<int8_t, 1>::float_to_fixed(value);
}

constexpr fixed<int8_t, 2> operator"" fxp8_2(long double value) {
    return fixed<int8_t, 2>::float_to_fixed(value);
}

constexpr fixed<int8_t, 3> operator"" fxp8_3(long double value) {
    return fixed<int8_t, 3>::float_to_fixed(value);
}

constexpr fixed<int8_t, 4> operator"" fxp8_4(long double value) {
    return fixed<int8_t, 4>::float_to_fixed(value);
}

constexpr fixed<int8_t, 5> operator"" fxp8_5(long double value) {
    return fixed<int8_t, 5>::float_to_fixed(value);
}

constexpr fixed<int8_t, 6> operator"" fxp8_6(long double value) {
    return fixed<int8_t, 6>::float_to_fixed(value);
}

constexpr fixed<int8_t, 7> operator"" fxp8_7(long double value) {
    return fixed<int8_t, 7>::float_to_fixed(value);
}

// // int16

constexpr fixed<int16_t, 1> operator"" fxp16_1(long double value) {
    return fixed<int16_t, 1>::float_to_fixed(value);
}

constexpr fixed<int16_t, 2> operator"" fxp16_2(long double value) {
    return fixed<int16_t, 2>::float_to_fixed(value);
}

constexpr fixed<int16_t, 3> operator"" fxp16_3(long double value) {
    return fixed<int16_t, 3>::float_to_fixed(value);
}

constexpr fixed<int16_t, 4> operator"" fxp16_4(long double value) {
    return fixed<int16_t, 4>::float_to_fixed(value);
}

constexpr fixed<int16_t, 5> operator"" fxp16_5(long double value) {
    return fixed<int16_t, 5>::float_to_fixed(value);
}

constexpr fixed<int16_t, 6> operator"" fxp16_6(long double value) {
    return fixed<int16_t, 6>::float_to_fixed(value);
}

constexpr fixed<int16_t, 7> operator"" fxp16_7(long double value) {
    return fixed<int16_t, 7>::float_to_fixed(value);
}

constexpr fixed<int16_t, 8> operator"" fxp16_8(long double value) {
    return fixed<int16_t, 8>::float_to_fixed(value);
}

constexpr fixed<int16_t, 9> operator"" fxp16_9(long double value) {
    return fixed<int16_t, 9>::float_to_fixed(value);
}

constexpr fixed<int16_t, 10> operator"" fxp16_10(long double value) {
    return fixed<int16_t, 10>::float_to_fixed(value);
}

constexpr fixed<int16_t, 11> operator"" fxp16_11(long double value) {
    return fixed<int16_t, 11>::float_to_fixed(value);
}

constexpr fixed<int16_t, 12> operator"" fxp16_12(long double value) {
    return fixed<int16_t, 12>::float_to_fixed(value);
}

constexpr fixed<int16_t, 13> operator"" fxp16_13(long double value) {
    return fixed<int16_t, 13>::float_to_fixed(value);
}

constexpr fixed<int16_t, 14> operator"" fxp16_14(long double value) {
    return fixed<int16_t, 14>::float_to_fixed(value);
}