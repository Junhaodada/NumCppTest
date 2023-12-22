
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
#include "boost/math/special_functions/hermite.hpp"
#endif

namespace nc::polynomial
{
    //============================================================================
    // Method Description:
    /// Hermite Polynomial
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the hermite polynomial
    /// @param x: the input value
    /// @return double
    ///
    template<typename dtype>
    double hermite(uint32 n, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_math_special_functions
        return std::hermite(n, static_cast<double>(x));
#else
        return boost::math::hermite(n, static_cast<double>(x));
#endif
    }

    //============================================================================
    // Method Description:
    /// Hermite Polynomial.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param n: the order of the hermite polynomial
    /// @param inArrayX: the input value
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> hermite(uint32 n, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [n](dtype x) -> double { return hermite(n, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }
} // namespace nc::polynomial

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
