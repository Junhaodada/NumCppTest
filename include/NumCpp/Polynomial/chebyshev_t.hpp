
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include "boost/math/special_functions/chebyshev.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::polynomial
{
    //============================================================================
    // Method Description:
    /// Chebyshev Polynomial of the first kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: the order of the chebyshev polynomial
    /// @param x: the input value
    /// @return double
    ///
    template<typename dtype>
    double chebyshev_t(uint32 n, dtype x)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return boost::math::chebyshev_t(n, static_cast<double>(x));
    }

    //============================================================================
    // Method Description:
    /// Chebyshev Polynomial of the first kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: the order of the chebyshev polynomial
    /// @param inArrayX: the input value
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> chebyshev_t(uint32 n, const NdArray<dtype>& inArrayX)
    {
        NdArray<double> returnArray(inArrayX.shape());

        const auto function = [n](dtype x) -> double { return chebyshev_t(n, x); };

        stl_algorithms::transform(inArrayX.cbegin(), inArrayX.cend(), returnArray.begin(), function);

        return returnArray;
    }
} // namespace nc::polynomial

#endif // #ifndef NUMCPP_NO_USE_BOOST
