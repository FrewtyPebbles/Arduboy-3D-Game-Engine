#pragma once
#include "fraction.h"

static const F32B TRIG_LUT_PI_79[80] = {
    F32B::const_construct(0, 3000),  // 0·π/79
    F32B::const_construct(60, 3000),  // 1·π/79
    F32B::const_construct(119, 3000),  // 2·π/79
    F32B::const_construct(179, 3000),  // 3·π/79
    F32B::const_construct(238, 3000),  // 4·π/79
    F32B::const_construct(298, 3000),  // 5·π/79
    F32B::const_construct(357, 3000),  // 6·π/79
    F32B::const_construct(416, 3000),  // 7·π/79
    F32B::const_construct(475, 3000),  // 8·π/79
    F32B::const_construct(534, 3000),  // 9·π/79
    F32B::const_construct(593, 3000),  // 10·π/79
    F32B::const_construct(651, 3000),  // 11·π/79
    F32B::const_construct(709, 3000),  // 12·π/79
    F32B::const_construct(767, 3000),  // 13·π/79
    F32B::const_construct(824, 3000),  // 14·π/79
    F32B::const_construct(882, 3000),  // 15·π/79
    F32B::const_construct(938, 3000),  // 16·π/79
    F32B::const_construct(995, 3000),  // 17·π/79
    F32B::const_construct(1051, 3000),  // 18·π/79
    F32B::const_construct(1107, 3000),  // 19·π/79
    F32B::const_construct(1162, 3000),  // 20·π/79
    F32B::const_construct(1217, 3000),  // 21·π/79
    F32B::const_construct(1271, 3000),  // 22·π/79
    F32B::const_construct(1325, 3000),  // 23·π/79
    F32B::const_construct(1378, 3000),  // 24·π/79
    F32B::const_construct(1431, 3000),  // 25·π/79
    F32B::const_construct(1483, 3000),  // 26·π/79
    F32B::const_construct(1534, 3000),  // 27·π/79
    F32B::const_construct(1585, 3000),  // 28·π/79
    F32B::const_construct(1636, 3000),  // 29·π/79
    F32B::const_construct(1685, 3000),  // 30·π/79
    F32B::const_construct(1734, 3000),  // 31·π/79
    F32B::const_construct(1783, 3000),  // 32·π/79
    F32B::const_construct(1830, 3000),  // 33·π/79
    F32B::const_construct(1877, 3000),  // 34·π/79
    F32B::const_construct(1923, 3000),  // 35·π/79
    F32B::const_construct(1969, 3000),  // 36·π/79
    F32B::const_construct(2013, 3000),  // 37·π/79
    F32B::const_construct(2057, 3000),  // 38·π/79
    F32B::const_construct(2100, 3000),  // 39·π/79
    F32B::const_construct(2142, 3000),  // 40·π/79
    F32B::const_construct(2184, 3000),  // 41·π/79
    F32B::const_construct(2224, 3000),  // 42·π/79
    F32B::const_construct(2264, 3000),  // 43·π/79
    F32B::const_construct(2302, 3000),  // 44·π/79
    F32B::const_construct(2340, 3000),  // 45·π/79
    F32B::const_construct(2377, 3000),  // 46·π/79
    F32B::const_construct(2413, 3000),  // 47·π/79
    F32B::const_construct(2448, 3000),  // 48·π/79
    F32B::const_construct(2482, 3000),  // 49·π/79
    F32B::const_construct(2515, 3000),  // 50·π/79
    F32B::const_construct(2547, 3000),  // 51·π/79
    F32B::const_construct(2578, 3000),  // 52·π/79
    F32B::const_construct(2608, 3000),  // 53·π/79
    F32B::const_construct(2637, 3000),  // 54·π/79
    F32B::const_construct(2665, 3000),  // 55·π/79
    F32B::const_construct(2692, 3000),  // 56·π/79
    F32B::const_construct(2718, 3000),  // 57·π/79
    F32B::const_construct(2742, 3000),  // 58·π/79
    F32B::const_construct(2766, 3000),  // 59·π/79
    F32B::const_construct(2788, 3000),  // 60·π/79
    F32B::const_construct(2810, 3000),  // 61·π/79
    F32B::const_construct(2830, 3000),  // 62·π/79
    F32B::const_construct(2849, 3000),  // 63·π/79
    F32B::const_construct(2868, 3000),  // 64·π/79
    F32B::const_construct(2885, 3000),  // 65·π/79
    F32B::const_construct(2900, 3000),  // 66·π/79
    F32B::const_construct(2915, 3000),  // 67·π/79
    F32B::const_construct(2929, 3000),  // 68·π/79
    F32B::const_construct(2941, 3000),  // 69·π/79
    F32B::const_construct(2952, 3000),  // 70·π/79
    F32B::const_construct(2962, 3000),  // 71·π/79
    F32B::const_construct(2971, 3000),  // 72·π/79
    F32B::const_construct(2979, 3000),  // 73·π/79
    F32B::const_construct(2985, 3000),  // 74·π/79
    F32B::const_construct(2991, 3000),  // 75·π/79
    F32B::const_construct(2995, 3000),  // 76·π/79
    F32B::const_construct(2998, 3000),  // 77·π/79
    F32B::const_construct(2999, 3000),  // 78·π/79
    F32B::const_construct(3000, 3000),  // 79·π/79
};


namespace Utility {
    template<typename T>
    constexpr T factorial(T n){
        return (n <= 1) ? T(1) : T(n) * factorial<T>(n - 1);
    }

    // ----- sin(x) -----
    template<typename Num, typename Den>
    fraction<Num, Den> sin(const fraction<Num, Den>& x)
    {
        using Frac = fraction<Num, Den>;

        // π and 2π as fractions
        const Frac PI(355, 113);
        const Frac TWO_PI = PI * 2;

        // 1. Wrap to [0, 2π)
        Frac t = x % TWO_PI;
        if (t.numerator < 0)
            t = t + TWO_PI;

        // 2. Determine quadrant
        int quadrant = 0;
        if (t >= PI) { t = t - PI; quadrant += 2; }
        if (t >= PI / 2) { t = PI - t; quadrant += 1; }

        // 3. Compute LUT index
        int idx = (t.numerator * 48 + t.denominator / 2) / t.denominator; // round(t / (π/48))
        if (idx < 0) idx = 0;
        if (idx > 79) idx = 79;

        // 4. Lookup LUT
        Frac value = Frac(TRIG_LUT_PI_79[idx]);

        // 5. Apply quadrant sign
        if (quadrant == 0) return value;       // 0..π/2
        if (quadrant == 1) return value;       // mirrored 0..π/2
        if (quadrant == 2) return -value;      // π..3π/2
        if (quadrant == 3) return -value;      // mirrored π..3π/2

        return value; // fallback
    }




    // ----- cos(x) -----
    template<typename Num, typename Den>
    fraction<Num, Den> cos(const fraction<Num, Den>& x)
    {
        // Simply compute sin(x + π/2)
        const fraction<Num, Den> PI(355, 113);
        const fraction<Num, Den> PI_OVER_2 = PI / 2;
        return sin<Num, Den>(x + PI_OVER_2);
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
        return Utility::sin(x) / Utility::cos(x);
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