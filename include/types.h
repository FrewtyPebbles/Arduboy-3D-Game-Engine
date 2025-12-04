#pragma once

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
    };
}