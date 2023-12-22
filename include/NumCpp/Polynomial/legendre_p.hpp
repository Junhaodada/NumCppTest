
/// Description
/// Special Functions
///
#pragma once

#include <cmath>

#if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

#ifndef __cpp_lib_math_special_functions
#include "boost/math/special_functions/legendre.hpp"
#endif

namespace nc::polynomial
{
    //============================================================================
    // Method Description:
    /// Legendre Polynomial of the first kind.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the degree of the legendre polynomial
    /// @param x: the input value. Requires -1 <= x <= 1
    /// @return double
    ///
    template<typename dtype>
    double legendre_p(uint32 n, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (x < -1. || x > 1.)
        {
            THROW_INVALID_ARGUMENT_ERROR("input x must be of the range [-1, 1].");
        }

#ifdef __cpp_lib_math_special_functions
        return std::legendre(n, static_cast<double>(x));
#else
        return boost::math::legendre_p(n, static_cast<double>(x));
#endif
    }

    //============================================================================
    // Method Description:
    /// Associated Legendre Polynomial of the first kind.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param m: the order of the legendre polynomial
    /// @param n: the degree of the legendre polynomial
    /// @param x: the input value. Requires -1 <= x <= 1
    /// @return double
    ///
    template<typename dtype>
    double legendre_p(uint32 m, uint32 n, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (x < -1. || x > 1.)
        {
            THROW_INVALID_ARGUMENT_ERROR("input x must be of the range [-1, 1].");
        }

#ifdef __cpp_lib_math_special_functions

        auto value = std::assoc_legendre(n, m, static_cast<double>(x));

#ifdef __GNUC__
#if __GNUC__ != 7 && __GNUC__ != 8

        // gcc std::assoc_legendre is not standard compliant
        value *= n % 2 == 0 ? 1 : -1;

#endif // #if __GNUC__ != 7 && __GNUC__ != 8
#endif // #ifdef __GNUC__

#ifdef __clang__
#if __clang_major__ != 7 && __clang_major__ != 8

        // clang uses gcc headers where std::assoc_legendre is not standard compliant
        value *= n % 2 == 0 ? 1 : -1;

#endif // #if __clang_major__ != 6 && __clang_major__ != 7 && __clang_major__ != 8
#endif // #ifdef __clang__

#ifdef _MSC_VER

        value *= n % 2 == 0 ? 1 : -1;

#endif // #ifdef _MSC_VER

        return value;

#else // #ifdef __cpp_lib_math_special_functions

        return boost::math::legendre_p(n, m, static_cast<double>(x));

#endif // #ifdef __cpp_lib_math_special_functions
    }

    //============================================================================
    // Method Description:
    /// Legendre Polynomial of the first kind.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the degree of the legendre polynomial
    /// @param inArrayX: the input value. Requires -1 <= x <= 1
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> legendre_p(uint32 n, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [n](dtype x) -> double { return legendre_p(n, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Associated Legendre Polynomial of the first kind.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param m: the order of the legendre polynomial
    /// @param n: the degree of the legendre polynomial
    /// @param inArrayX: the input value. Requires -1 <= x <= 1
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> legendre_p(uint32 m, uint32 n, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [m, n](dtype x) -> double { return legendre_p(m, n, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }
} // namespace nc::polynomial

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
