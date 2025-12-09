#pragma once
#include <stdint.h>
#include "types.h"

// This class simulates floating point arithmetic using fractions
template <typename NumeratorType, typename DenominatorType>
class fraction {
public:
    constexpr fraction() = default;
    fraction(NumeratorType numerator, DenominatorType denominator);
    template<typename U>
    fraction(const U& integer);
    fraction(const float& floating_point);
    fraction(const double& floating_point);

    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction(const fraction<OtherNumeratorType, OtherDenominatorType> & other);

    static constexpr fraction const_construct(NumeratorType numerator, DenominatorType denominator){
        fraction ret;
        ret.numerator = numerator;
        ret.denominator = denominator;
        return ret;
    }

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

    // MODULO

    template<typename Num, typename Den>
    static fraction<Num, Den> mod(const fraction<Num, Den>& x, const fraction<Num, Den>& y)
    {
        using Frac = fraction<Num, Den>;

        // Compute integer quotient floor(x / y)
        // Use 64-bit integer to avoid overflow if needed
        int64_t xn = x.numerator;
        int64_t xd = x.denominator;
        int64_t yn = y.numerator;
        int64_t yd = y.denominator;

        // x / y = (xn/xd) / (yn/yd) = (xn*yd) / (xd*yn)
        int64_t numerator_div = xn * yd;
        int64_t denominator_div = xd * yn;

        int64_t q = numerator_div / denominator_div; // floor division

        // x % y = x - y*q
        int64_t result_num = xn * yd - q * yn * xd;
        int64_t result_den = xd * yd;

        return Frac(static_cast<Num>(result_num), static_cast<Den>(result_den));
    }

    template<typename U>
    fraction<NumeratorType, DenominatorType> operator%(const U& other) const;
    template <typename OtherNumeratorType, typename OtherDenominatorType>
    fraction operator%(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const;

    friend fraction<NumeratorType, DenominatorType> operator%(const int8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return mod(lhs, rhs);
    }

    friend fraction<NumeratorType, DenominatorType> operator%(const int16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return mod(lhs, rhs);
    }

    friend fraction<NumeratorType, DenominatorType> operator%(const int32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return mod(lhs, rhs);
    }

    friend fraction<NumeratorType, DenominatorType> operator%(const uint8_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return mod(lhs, rhs);
    }

    friend fraction<NumeratorType, DenominatorType> operator%(const uint16_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return mod(lhs, rhs);
    }

    friend fraction<NumeratorType, DenominatorType> operator%(const uint32_t& lhs, const fraction<NumeratorType, DenominatorType>& rhs) {
        return mod(lhs, rhs);
    }

    // END MODULO

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

    void to_string(char * buffer) const {
        sprintf(buffer, "%ld/%ld", numerator, denominator);
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
 : numerator(numerator), denominator(denominator == 0 ? 1 : denominator)
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
    using LargeUnsigned = Utility::Types::make_unsigned_type<
        Utility::Types::choose_larger_type<NumeratorType, DenominatorType>
    >;
    
    // Absolute values - need to handle signed-to-unsigned conversion properly
    LargeUnsigned num = numerator < 0 ? static_cast<LargeUnsigned>(-static_cast<typename Utility::Types::make_unsigned_type<LargeUnsigned>>(numerator)) 
                                       : static_cast<LargeUnsigned>(numerator);
    LargeUnsigned denom = denominator < 0 ? static_cast<LargeUnsigned>(-static_cast<typename Utility::Types::make_unsigned_type<LargeUnsigned>>(denominator)) 
                                           : static_cast<LargeUnsigned>(denominator);
    
    if (num == 0) return static_cast<Utility::Types::choose_larger_type<NumeratorType, DenominatorType>>(denom);
    if (denom == 0) return static_cast<Utility::Types::choose_larger_type<NumeratorType, DenominatorType>>(num);
    
    // Count common factors of 2
    uint8_t shift = 0;
    while (((num | denom) & 1) == 0) {
        num >>= 1;
        denom >>= 1;
        ++shift;
    }
    
    // Remove all factors of 2 from numerator
    while ((num & 1) == 0) num >>= 1;
    
    while (denom != 0) {
        // Remove all factors of 2 from denominator
        while ((denom & 1) == 0) denom >>= 1;
        
        // Make sure num <= denom for subtraction
        if (num > denom) {
            LargeUnsigned t = num;
            num = denom;
            denom = t;
        }
        denom -= num;
    }
    
    return static_cast<Utility::Types::choose_larger_type<NumeratorType, DenominatorType>>(num << shift);
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

// MODULO

template <typename NumeratorType, typename DenominatorType>
template<typename U>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator%(const U& other) const {
    return fraction<NumeratorType, DenominatorType>::mod(*this, other);
}
template <typename NumeratorType, typename DenominatorType>
template <typename OtherNumeratorType, typename OtherDenominatorType>
fraction<NumeratorType, DenominatorType> fraction<NumeratorType, DenominatorType>::operator%(const fraction<OtherNumeratorType, OtherDenominatorType>& other) const {
    return fraction<NumeratorType, DenominatorType>::mod(*this, other);
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

// Aliases

typedef fraction<int8_t, int8_t> F16B;

typedef fraction<int16_t, int16_t> F32B;

typedef fraction<int32_t, int32_t> F64B;