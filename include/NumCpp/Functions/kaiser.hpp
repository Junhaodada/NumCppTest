
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)

#include "NumCpp/Functions/linspace.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Special/bessel_in.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// The Kaiser window is a taper formed by using a Bessel function.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.kaiser.html
    ///
    /// @param m: Number of points in the output window. If zero or less, an empty array is returned.
    /// @param beta: shape parameter for the window
    /// @return NdArray
    ///
    inline NdArray<double> kaiser(int32 m, double beta)
    {
        if (m < 1)
        {
            return {};
        }

        const auto mDouble        = static_cast<double>(m);
        const auto mMinus1        = mDouble - 1.;
        const auto mMinus1Over2   = mMinus1 / 2.;
        const auto mMinus1Squared = utils::sqr(mMinus1);
        const auto i0Beta         = special::bessel_in(0, beta);

        NdArray<double> result(1, m);
        int32           i = 0;
        for (auto n : linspace(-mMinus1Over2, mMinus1Over2, m, EndPoint::YES))
        {
            auto value  = beta * std::sqrt(1. - (4. * utils::sqr(n)) / mMinus1Squared);
            result[i++] = special::bessel_in(0, value) / i0Beta;
        }

        return result;
    }
} // namespace nc

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
