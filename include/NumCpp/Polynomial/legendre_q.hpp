
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include "boost/math/special_functions/legendre.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::polynomial
{
    //============================================================================
    // Method Description:
    /// Legendre Polynomial of the second kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: the order of the legendre polynomial
    /// @param x: the input value. Requires -1 <= x <= 1
    /// @return double
    ///
    template<typename dtype>
    double legendre_q(int32 n, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (x < -1. || x > 1.)
        {
            THROW_INVALID_ARGUMENT_ERROR("input x must be of the range [-1, 1].");
        }

        return boost::math::legendre_q(n, static_cast<double>(x));
    }

    //============================================================================
    // Method Description:
    /// Legendre Polynomial of the second kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: the order of the legendre polynomial
    /// @param inArrayX: the input value. Requires -1 <= x <= 1
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> legendre_q(int32 n, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [n](dtype x) -> double { return legendre_q(n, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }
} // namespace nc::polynomial

#endif // #ifndef NUMCPP_NO_USE_BOOST
