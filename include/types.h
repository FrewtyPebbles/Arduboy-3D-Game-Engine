#pragma once
#include <stdint.h>

namespace Utility {
    namespace Types {

        // CHOOSE SMALLER TYPE
        
        template <typename T1, typename T2, bool T1Smaller = (sizeof(T1) < sizeof(T2))>
        struct choose_smaller_type_impl {
            using type = T1;
        };

        // Specialization when T2 is smaller or equal
        template <typename T1, typename T2>
        struct choose_smaller_type_impl<T1, T2, false> {
            using type = T2;
        };

        // Alias
        template <typename T1, typename T2>
        using choose_smaller_type = typename choose_smaller_type_impl<T1, T2>::type;

        // CHOOSE LARGER TYPE

        template <typename T1, typename T2, bool T1Larger = (sizeof(T1) > sizeof(T2))>
        struct choose_larger_type_impl {
            using type = T1;
        };

        // Specialization when T2 is smaller or equal
        template <typename T1, typename T2>
        struct choose_larger_type_impl<T1, T2, false> {
            using type = T2;
        };

        // Alias
        template <typename T1, typename T2>
        using choose_larger_type = typename choose_larger_type_impl<T1, T2>::type;

        // MAKE UNSIGNED

        template <typename T>
        struct make_unsigned_type_impl {
            using type = T;
        };

        template <>
        struct make_unsigned_type_impl<int64_t> {
            using type = uint64_t;
        };

        template <>
        struct make_unsigned_type_impl<int32_t> {
            using type = uint32_t;
        };

        template <>
        struct make_unsigned_type_impl<int16_t> {
            using type = uint16_t;
        };

        template <>
        struct make_unsigned_type_impl<int8_t> {
            using type = uint8_t;
        };

        // Alias
        template <typename T>
        using make_unsigned_type = typename make_unsigned_type_impl<T>::type;

        // NUMERIC LIMIT

        template <typename T>
        struct numeric_limit {
            constexpr static T min = 0;
            constexpr static T max = 0;
        };

        template <>
        struct numeric_limit<uint8_t> {
            constexpr static uint8_t min = 0;
            constexpr static uint8_t max = 255;
        };

        template <>
        struct numeric_limit<uint16_t> {
            constexpr static uint16_t min = 0;
            constexpr static uint16_t max = 65535;
        };

        template <>
        struct numeric_limit<uint32_t> {
            constexpr static uint32_t min = 0;
            constexpr static uint32_t max = 4294967295;
        };

        template <>
        struct numeric_limit<uint64_t> {
            constexpr static uint64_t min = 0;
            constexpr static uint64_t max = 18446744073709551615ULL;
        };

        template <>
        struct numeric_limit<int8_t> {
            constexpr static int8_t min = -128;
            constexpr static int8_t max = 127;
        };

        template <>
        struct numeric_limit<int16_t> {
            constexpr static int16_t min = -32768;
            constexpr static int16_t max = 32767;
        };

        template <>
        struct numeric_limit<int32_t> {
            constexpr static int32_t min = -2147483648;
            constexpr static int32_t max = 2147483647;
        };

        template <>
        struct numeric_limit<int64_t> {
            constexpr static int64_t min = -9223372036854775807LL - 1;
            constexpr static int64_t max = 9223372036854775807;
        };
    };
}