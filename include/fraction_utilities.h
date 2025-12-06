#pragma once
#include "fraction.h"

namespace Utility {
    template<typename T>
    constexpr T factorial(int8_t n){
        return (n <= 1) ? T(1) : T(n) * factorial<T>(n - 1);
    }

    // ----- sin(x) -----
    template<typename Num, typename Den>
    fraction<Num, Den> sin(const fraction<Num, Den>& x, uint8_t terms = 10)
    {
        using Frac = fraction<Num, Den>;
        
        Frac sum(0);
        Frac power = x;                // x^1
        int8_t sign = 1;

        for (uint8_t k = 0; k < terms; ++k)
        {
            int16_t n = 2 * k + 1;         // odd power
            int16_t _factorial = Utility::factorial<int16_t>(n);

            Frac term = power / _factorial;
            if (!sign)
                term = Frac(0) - term;

            sum = sum + term;

            // update for next iteration
            power = power * x * x;     // multiply by x^2
            sign ^= 1;                 // flip sign
        }

        return sum;
    }

    // ----- cos(x) -----
    template<typename Num, typename Den>
    fraction<Num, Den> cos(const fraction<Num, Den>& x, uint8_t terms = 10)
    {
        using Frac = fraction<Num, Den>;

        Frac sum(1);                  // 0th term = 1
        Frac power(1);                // x^0
        int8_t sign = 1;

        for (uint8_t k = 1; k < terms; ++k)
        {
            int16_t n = 2 * k;            // even power
            power = power * x * x;    // x^(2k)
            int16_t _factorial = Utility::factorial<int16_t>(n);

            Frac term = power / _factorial;

            if (!sign)
                term = Frac(0) - term;

            sum = sum + term;

            sign ^= 1;
        }

        return sum;
    }

    template<typename Num, typename Den>
    fraction<Num,Den> atan(const fraction<Num,Den>& z)
    {
        using Frac = fraction<Num, Den>;
        
        // CONSTANTS (using template types)
        // π ≈ 355/113
        static const Frac PI_FRAC(355, 113);

        // π/4
        static const Frac PI_OVER_4 = PI_FRAC / 4;

        // 0.2447 and 0.0663 as rational numbers
        static const Frac A(2447, 10000);  // 0.2447
        static const Frac B(663, 10000);   // 0.0663

        // |z|
        Frac abs_z = (z.numerator < 0) ? Frac(0) - z : z;

        // inner = A + B*|z|
        Frac inner = A + (B * abs_z);

        // term = z * (1 - |z|) * inner
        Frac term = z * (Frac(1) - abs_z) * inner;

        // result = π/4 * z - term
        return (PI_OVER_4 * z) - term;
    }

    template<typename Num, typename Den>
    fraction<Num, Den> atan2(const fraction<Num, Den>& y, const fraction<Num, Den>& x)
    {
        using Frac = fraction<Num, Den>;

        static const Frac PI_FRAC(355, 113);
        static const Frac PI_OVER_2 = PI_FRAC / 2;
        static const Frac NEG_PI_OVER_2 = Frac(0) - PI_OVER_2;

        // Case x > 0
        if (x.numerator > 0)
        {
            return Utility::atan(y / x);
        }

        // Case x < 0 and y ≥ 0
        if (x.numerator < 0 && y.numerator >= 0)
        {
            return Utility::atan(y / x) + PI_FRAC;
        }

        // Case x < 0 and y < 0
        if (x.numerator < 0 && y.numerator < 0)
        {
            return Utility::atan(y / x) - PI_FRAC;
        }

        // Case x = 0, y > 0
        if (x.numerator == 0 && y.numerator > 0)
        {
            return PI_OVER_2;
        }

        // Case x = 0, y < 0
        if (x.numerator == 0 && y.numerator < 0)
        {
            return NEG_PI_OVER_2;
        }

        // Undefined if (x = 0, y = 0) → return 0
        return Frac(0);
    }

    template<typename Num, typename Den>
    fraction<Num,Den> tan(const fraction<Num,Den>& x, uint8_t terms = 10)
    {
        return Utility::sin(x, terms) / Utility::cos(x, terms);
    }

    template<typename Num, typename Den>
    fraction<Num,Den> asin(const fraction<Num,Den>& x) {
        using Frac = fraction<Num, Den>;

        // Coefficients of Maclaurin series as fractions:
        // asin(x) ≈ x + x^3*(1/6) + x^5*(3/40) + x^7*(5/112)
        static const Frac C1(1, 6);    // 1/6
        static const Frac C2(3, 40);   // 3/40
        static const Frac C3(5, 112);  // 5/112

        Frac x2 = x * x;       // x^2
        Frac x3 = x2 * x;      // x^3
        Frac x4 = x2 * x2;     // x^4
        Frac x5 = x3 * x2;     // x^5
        Frac x7 = x5 * x2;     // x^7

        // Polynomial approximation
        Frac poly = C1 + C2 * x2 + C3 * x4;

        return x + x3 * poly; // asin(x) ≈ x + x^3*(poly)
    }

    template<typename Num, typename Den>
    fraction<Num,Den> acos(const fraction<Num,Den>& x)
    {
        using Frac = fraction<Num,Den>;

        static const Frac PI_FRAC(355, 113);
        static const Frac PI_OVER_2 = PI_FRAC / 2;

        return PI_OVER_2 - Utility::asin(x);
    }
    
    template<typename T>
    T wrap_euler_angle_degrees(T angle) {
        angle %= static_cast<T>(360);
        return angle < static_cast<T>(0) ? angle + static_cast<T>(360) : angle;
    }

    template<typename N, typename D>
    fraction<N,D> wrap_euler_angle_radians(const fraction<N,D>& angle) {
        using Fr = fraction<N,D>;

        // Rational approximation of pi and 2*pi
        static const Fr PI_FRAC(355, 113);       // π ≈ 355/113
        static const Fr TWO_PI_FRAC(710, 113);   // 2π ≈ 710/113

        // Compute integer k = floor(angle / 2pi)
        // angle / TWO_PI_FRAC = (angle.num * TWO_PI.den) / (angle.den * TWO_PI.num)
        int64_t k_num = static_cast<int64_t>(angle.numerator) * TWO_PI_FRAC.denominator;
        int64_t k_den = static_cast<int64_t>(angle.denominator) * TWO_PI_FRAC.numerator;

        // Floor division for negative numbers
        int64_t k = k_num / k_den;
        if ((k_num < 0) && (k_num % k_den != 0)) {
            k -= 1;
        }

        // Wrap to [0, 2π)
        Fr result = angle - Fr(static_cast<N>(k)) * TWO_PI_FRAC;

        // Shift to [-π, π)
        if (result > PI_FRAC) {
            result = result - TWO_PI_FRAC;
        }

        return result;
    }


};