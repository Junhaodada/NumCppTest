
/// Description
/// Special Functions
///
#pragma once

#include <cmath>

#if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

#ifndef __cpp_lib_math_special_functions
#include "boost/math/special_functions/laguerre.hpp"
#endif

namespace nc::polynomial
{
    //============================================================================
    // Method Description:
    /// Laguerre Polynomial.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the leguerre polynomial
    /// @param x: the input value
    /// @return double
    ///
    template<typename dtype>
    double laguerre(uint32 n, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_math_special_functions
        return std::laguerre(n, static_cast<double>(x));
#else
        return boost::math::laguerre(n, static_cast<double>(x));
#endif
    }

    //============================================================================
    // Method Description:
    /// Associated Laguerre Polynomial.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the leguerre polynomial
    /// @param m: the degree of the legendre polynomial
    /// @param x: the input value
    /// @return double
    ///
    template<typename dtype>
    double laguerre(uint32 n, uint32 m, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_math_special_functions
        return std::assoc_laguerre(m, n, static_cast<double>(x));
#else
        return boost::math::laguerre(m, n, static_cast<double>(x));
#endif
    }

    //============================================================================
    // Method Description:
    /// Laguerre Polynomial.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the leguerre polynomial
    /// @param inArrayX: the input value
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> laguerre(uint32 n, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [n](dtype x) -> double { return laguerre(n, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Associated Laguerre Polynomial.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the leguerre polynomial
    /// @param m: the degree of the legendre polynomial
    /// @param inArrayX: the input value
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> laguerre(uint32 n, uint32 m, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [n, m](dtype x) -> double { return laguerre(n, m, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }
} // namespace nc::polynomial

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
