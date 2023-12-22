
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Constants.hpp"
#include "NumCpp/Functions/linspace.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the Hamming window.
    ///
    /// The Hanning window is a taper formed by using a weighted cosine.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.hanning.html
    ///
    /// @param m: Number of points in the output window. If zero or less, an empty array is returned.
    /// @return NdArray
    ///
    inline NdArray<double> hanning(int32 m)
    {
        if (m < 1)
        {
            return {};
        }

        const auto mDouble         = static_cast<double>(m);
        const auto twoPiDivMMinus1 = (2. * constants::pi) / (mDouble - 1.);

        NdArray<double> result(1, m);
        int32           i = 0;
        for (auto n : linspace(0., mDouble - 1., m, EndPoint::YES))
        {
            result[i++] = 0.5 - 0.5 * std::cos(twoPiDivMMinus1 * n);
        }

        return result;
    }
} // namespace nc
