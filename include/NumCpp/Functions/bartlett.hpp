
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Functions/linspace.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// The Bartlett window is very similar to a triangular window, except that the end
    /// points are at zero. It is often used in signal processing for tapering a signal,
    /// without generating too much ripple in the frequency domain.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.bartlett.html
    ///
    /// @param m: Number of points in the output window. If zero or less, an empty array is returned.
    /// @return NdArray
    ///
    inline NdArray<double> bartlett(int32 m)
    {
        if (m < 1)
        {
            return {};
        }

        const auto mDouble         = static_cast<double>(m);
        const auto mMinus1Over2    = (mDouble - 1.) / 2.;
        const auto mMinus1Over2Inv = 1. / mMinus1Over2;

        NdArray<double> result(1, m);
        int32           i = 0;
        for (auto n : linspace(0., mDouble - 1., m, EndPoint::YES))
        {
            result[i++] = mMinus1Over2Inv * (mMinus1Over2 - std::abs(n - mMinus1Over2));
        }

        return result;
    }
} // namespace nc
