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
    fraction(const float& floating_point);
    fraction(const double& floating_point);

    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction(const fraction<OtherNumeratorType, OtherDenominatorType> & other);

    NumeratorType numerator;
    DenominatorType denominator;

    auto greatest_common_factor() -> Utility::Types::choose_larger_type<NumeratorType, DenominatorType>;
    // Alias
    inline auto gcf() -> Utility::Types::choose_larger_type<NumeratorType, DenominatorType>
        {return greatest_common_factor();}

    void simplify();

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator*(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator*(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    friend fraction<NumeratorType, DenominatorType> operator*(const int8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs * lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator*(const int16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs * lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator*(const int32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs * lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator*(const uint8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs * lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator*(const uint16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs * lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator*(const uint32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs * lhs;
    }

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator/(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator/(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    friend fraction<NumeratorType, DenominatorType> operator/(const int8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator),
            (rhs.numerator)
        );
    }
    friend fraction<NumeratorType, DenominatorType> operator/(const int16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator),
            (rhs.numerator)
        );
    }
    friend fraction<NumeratorType, DenominatorType> operator/(const int32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator),
            (rhs.numerator)
        );
    }
    friend fraction<NumeratorType, DenominatorType> operator/(const uint8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator),
            (rhs.numerator)
        );
    }
    friend fraction<NumeratorType, DenominatorType> operator/(const uint16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator),
            (rhs.numerator)
        );
    }
    friend fraction<NumeratorType, DenominatorType> operator/(const uint32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator),
            (rhs.numerator)
        );
    }

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator+(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator+(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    friend fraction<NumeratorType, DenominatorType> operator+(const int8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs + lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator+(const int16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs + lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator+(const int32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs + lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator+(const uint8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs + lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator+(const uint16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs + lhs;
    }
    friend fraction<NumeratorType, DenominatorType> operator+(const uint32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return rhs + lhs;
    }

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator-(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator-(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    friend fraction<NumeratorType, DenominatorType> operator-(const int8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator - rhs.numerator),
            (rhs.denominator)
        );
    }

    friend fraction<NumeratorType, DenominatorType> operator-(const int16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator - rhs.numerator),
            (rhs.denominator)
        );
    }

    friend fraction<NumeratorType, DenominatorType> operator-(const int32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (lhs * rhs.denominator - rhs.numerator),
            (rhs.denominator)
        );
    }

    friend fraction<NumeratorType, DenominatorType> operator-(const uint8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (static_cast<DenominatorType>(lhs) * rhs.denominator - rhs.numerator),
            (rhs.denominator)
        );
    }

    friend fraction<NumeratorType, DenominatorType> operator-(const uint16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (static_cast<DenominatorType>(lhs) * rhs.denominator - rhs.numerator),
            (rhs.denominator)
        );
    }

    friend fraction<NumeratorType, DenominatorType> operator-(const uint32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return fraction<NumeratorType, DenominatorType>(
            (static_cast<DenominatorType>(lhs) * rhs.denominator - rhs.numerator),
            (rhs.denominator)
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

    explicit operator float() const {
        return static_cast<float>(this->numerator)/static_cast<float>(this->denominator);
    }

    template <typename OtherNumeratorType, typename OtherDenominatorType>
    bool operator==(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;
    
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    bool operator!=(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    template <typename OtherNumeratorType, typename OtherDenominatorType>
    bool operator>=(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;
    
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    bool operator<=(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;
    
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    bool operator>(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    template <typename OtherNumeratorType, typename OtherDenominatorType>
    bool operator<(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    template <typename U>
    bool operator==(const U& other) const;
    
    template <typename U>
    bool operator!=(const U& other) const;

    template <typename U>
    bool operator>=(const U& other) const;
    
    template <typename U>
    bool operator<=(const U& other) const;
    
    template <typename U>
    bool operator>(const U& other) const;

    template <typename U>
    bool operator<(const U& other) const;

    friend bool operator==(float lhs, const fraction& rhs) {
        return rhs == lhs; // delegate
    }
};

template <typename NumeratorType, typename DenominatorType>
void fraction<NumeratorType, DenominatorType>::simplify() {
    Utility::Types::choose_larger_type<NumeratorType, DenominatorType> _gcf = gcf();
    if (_gcf > 1) {
        numerator /= _gcf;
        denominator /= _gcf;
    }
}


template <typename NumeratorType, typename DenominatorType>
fraction<NumeratorType, DenominatorType>::fraction(const float& floating_point) {
    float value = floating_point;
    bool neg = value < 0.0f;
    if (neg) value = -value;

    // Use 32-bit integers for all intermediate calculations
    int32_t n0 = 0, d0 = 1;
    int32_t n1 = 1, d1 = 0;

    float x = value;
    constexpr int32_t max_denominator = Utility::Types::numeric_limit<DenominatorType>::max;

    while (true) {
        int32_t a = static_cast<int32_t>(floor(x));
        int32_t n2 = a * n1 + n0;
        int32_t d2 = a * d1 + d0;

        if (d2 > max_denominator) break;

        n0 = n1; d0 = d1;
        n1 = n2; d1 = d2;

        float frac_part = x - a;
        if (frac_part == 0.0f) break;

        x = 1.0f / frac_part;
    }

    // Apply sign
    NumeratorType num = static_cast<NumeratorType>(neg ? -n1 : n1);
    DenominatorType denom = static_cast<DenominatorType>(d1);

    numerator = num;
    denominator = denom;

    simplify();
}

template <typename NumeratorType, typename DenominatorType>
fraction<NumeratorType, DenominatorType>::fraction(const double& floating_point) : fraction(static_cast<float>(floating_point)) {}

template <typename NumeratorType, typename DenominatorType>
fraction<NumeratorType, DenominatorType>::fraction(NumeratorType numerator, DenominatorType denominator)
 : numerator(numerator), denominator(denominator)
{simplify();}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
fraction<NumeratorType, DenominatorType>::fraction(const U& integer)
 : numerator(static_cast<NumeratorType>(integer)), denominator(static_cast<DenominatorType>(1))
{simplify();}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType>::fraction(const fraction<OtherNumeratorType, OtherDenominatorType> & other)
 : numerator(static_cast<NumeratorType>(other.numerator)), denominator(static_cast<NumeratorType>(other.denominator))
 {simplify();}

template <typename NumeratorType, typename DenominatorType>
auto fraction<NumeratorType, DenominatorType>::greatest_common_factor() -> Utility::Types::choose_larger_type<NumeratorType, DenominatorType> {
    auto num = static_cast<Utility::Types::make_unsigned_type<decltype(numerator)>>(numerator);
    auto denom = static_cast<Utility::Types::make_unsigned_type<decltype(denominator)>>(denominator);
    if (num == 0) return denom;
    if (denom == 0) return num;

    // Count common factors of 2
    uint8_t shift = __builtin_ctz(num | denom);

    // Remove all factors of 2 from numerator
    num >>= __builtin_ctz(num);
    do {
        // Remove all factors of 2 from denominator
        denom >>= __builtin_ctz(denom);

        // Make sure numerator <= denominator
        if (num > denom) {
            Utility::Types::choose_larger_type<NumeratorType, DenominatorType> temp = num;
            num = denom;
            denom = temp;
        }

        // Subtract
        denom = denom - num;

    } while (denom != 0);

    return num << shift;
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator*(const U& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other),
        (this->denominator)
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator*(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.numerator),
        (this->denominator * other.denominator)
    );
}



template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator/(const U& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator),
        (this->denominator * other)
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator/(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.denominator),
        (this->denominator * other.numerator)
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator+(const U& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator + this->denominator * other),
        (this->denominator)
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator+(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.denominator + other.numerator * this->denominator),
        (this->denominator * other.denominator)
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator-(const U& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator - this->denominator * other),
        (this->denominator)
    );
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator-(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    return fraction<NumeratorType, DenominatorType>(
        (this->numerator * other.denominator - other.numerator * this->denominator),
        (this->denominator * other.denominator)
    );
}


template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator*=(const U& other) {
    *this = *this * other;
    simplify();
}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator/=(const U& other) {
    *this = *this / other;
    simplify();
}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator+=(const U& other) {
    *this = *this + other;
    simplify();
}

template <typename NumeratorType, typename DenominatorType>
template<typename U>
void fraction<NumeratorType, DenominatorType>::operator-=(const U& other) {
    *this = *this - other;
    simplify();
}

template <typename NumeratorType, typename DenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator-() const {
    return fraction<NumeratorType, DenominatorType>(
        -this->numerator,
        this->denominator
    );
}


// COMPARISONS

// FRACTION COMPARISONS

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
bool fraction<NumeratorType, DenominatorType>::operator==(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    return this->numerator == other.numerator && this->denominator == other.denominator;
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
bool fraction<NumeratorType, DenominatorType>::operator!=(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    return !(*this == other);
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
bool fraction<NumeratorType, DenominatorType>::operator>=(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto difference = *this - other;
    return difference >= 0;
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
bool fraction<NumeratorType, DenominatorType>::operator<=(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto difference = *this - other;
    return difference <= 0;
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
bool fraction<NumeratorType, DenominatorType>::operator>(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto difference = *this - other;
    return difference > 0;
}

template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
bool fraction<NumeratorType, DenominatorType>::operator<(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    auto difference = *this - other;
    return difference < 0;
}

// INT COMPARISONS

template <typename NumeratorType, typename DenominatorType>
template <typename U>
bool fraction<NumeratorType, DenominatorType>::operator==(const U& other) const {
    return this->numerator == other && this->denominator == 1;
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
bool fraction<NumeratorType, DenominatorType>::operator!=(const U& other) const {
    return !(*this == other);
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
bool fraction<NumeratorType, DenominatorType>::operator>=(const U& other) const {
    auto whole = this->numerator / this->denominator;
    auto frac = this->numerator % this->denominator;
    return whole > other || whole == other && frac >= 0;
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
bool fraction<NumeratorType, DenominatorType>::operator<=(const U& other) const {
    auto whole = this->numerator / this->denominator;
    auto frac = this->numerator % this->denominator;
    return whole < other || whole == other && frac <= 0;
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
bool fraction<NumeratorType, DenominatorType>::operator>(const U& other) const {
    auto whole = this->numerator / this->denominator;
    auto frac = this->numerator % this->denominator;
    return whole > other || whole == other && frac > 0;
}

template <typename NumeratorType, typename DenominatorType>
template <typename U>
bool fraction<NumeratorType, DenominatorType>::operator<(const U& other) const {
    auto whole = this->numerator / this->denominator;
    auto frac = this->numerator % this->denominator;
    return whole < other || whole == other && frac < 0;
}