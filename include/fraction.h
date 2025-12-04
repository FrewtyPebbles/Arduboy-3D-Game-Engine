#pragma once
#include <stdint.h>
#include "types.h"

// This class simulates floating point arithmetic using fractions
template <typename NumeratorType, typename DenominatorType>
class fraction {
public:
    fraction(NumeratorType numerator, DenominatorType denominator);
    template<typename U>
    fraction(const U& integer);

    NumeratorType numerator;
    DenominatorType denominator;

    auto greatest_common_factor() -> Utility::Types::choose_larger_type<NumeratorType, DenominatorType>;
    // Alias
    inline auto gcf() -> Utility::Types::choose_larger_type<NumeratorType, DenominatorType>
        {return greatest_common_factor();}

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator*(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator*(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    template<typename U>
    friend fraction<NumeratorType, DenominatorType> operator*(const U& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs * lhs;
    }

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator/(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator/(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    template<typename U>
    friend fraction<NumeratorType, DenominatorType> operator/(const U& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        auto gcf_value = rhs.gcf();
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator) / gcf_value,
            (rhs.numerator) / gcf_value
        );
    }

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator+(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator+(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    template<typename U>
    friend fraction<NumeratorType, DenominatorType> operator+(const U& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs + lhs;
    }

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator-(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator-(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    template<typename U>
    friend fraction<NumeratorType, DenominatorType> operator-(const U& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        auto gcf_value = rhs.gcf();
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator - rhs.numerator) / gcf_value,
            (rhs.denominator) / gcf_value
        );
    }

    fraction<NumeratorType, DenominatorType> operator-() const;

    template<typename U>
    void operator*=(const U& other);

    template<typename U>
    void operator/=(const U& other);

    template<typename U>
    void operator+=(const U& other);

    template<typename U>
    void operator-=(const U& other);

    explicit operator int() const {
        return static_cast<int>(this->numerator/this->denominator);
    }
};

template <typename NumeratorType, typename DenominatorType>
fraction<NumeratorType, DenominatorType>::fraction(NumeratorType numerator, DenominatorType denominator) : numerator(numerator), denominator(denominator) {}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
fraction<NumeratorType, DenominatorType>::fraction(const U& integer) : numerator(static_cast<NumeratorType>(integer)), denominator(static_cast<DenominatorType>(1)) {}

template <typename NumeratorType, typename DenominatorType>
auto fraction<NumeratorType, DenominatorType>::greatest_common_factor() -> Utility::Types::choose_larger_type<NumeratorType, DenominatorType> {
    if (numerator == 0) return denominator;
    if (denominator == 0) return numerator;

    // Count common factors of 2
    uint8_t shift = __builtin_ctz(numerator | denominator);

    // Remove all factors of 2 from numerator
    numerator >>= __builtin_ctz(numerator);

    do {
        // Remove all factors of 2 from denominator
        denominator >>= __builtin_ctz(denominator);

        // Make sure numerator <= denominator
        if (numerator > denominator) {
            Utility::Types::choose_larger_type<NumeratorType, DenominatorType> temp = numerator;
            numerator = denominator;
            denominator = temp;
        }

        // Subtract
        denominator = denominator - numerator;

    } while (denominator != 0);

    return numerator << shift;
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator*(const U& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other) / gcf_value,
        (this->denominator) / gcf_value
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator*(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.numerator) / gcf_value,
        (this->denominator * other.denominator) / gcf_value
    );
}



template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator/(const U& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator) / gcf_value,
        (this->denominator * other) / gcf_value
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator/(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.denominator) / gcf_value,
        (this->denominator * other.numerator) / gcf_value
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator+(const U& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator + this->denominator * other) / gcf_value,
        (this->denominator) / gcf_value
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator+(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.denominator + other.numerator * this->denominator) / gcf_value,
        (this->denominator * other.denominator) / gcf_value
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator-(const U& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator - this->denominator * other) / gcf_value,
        (this->denominator) / gcf_value
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator-(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto gcf_value = gcf();
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.denominator - other.numerator * this->denominator) / gcf_value,
        (this->denominator * other.denominator) / gcf_value
    );
}


template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator*=(const U& other) {
    *this = *this * other;
}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator/=(const U& other) {
    *this = *this / other;
}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator+=(const U& other) {
    *this = *this + other;
}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator-=(const U& other) {
    *this = *this - other;
}