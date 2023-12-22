
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
    /// The Blackman window is a taper formed by using the first three terms of a summation of
    /// cosines. It was designed to have close to the minimal leakage possible. It is close to
    /// optimal, only slightly worse than a Kaiser window.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.blackman.html
    ///
    /// @param m: Number of points in the output window. If zero or less, an empty array is returned.
    /// @return NdArray
    ///
    inline NdArray<double> blackman(int32 m)
    {
        if (m < 1)
        {
            return {};
        }

        const auto mDouble = static_cast<double>(m);

        NdArray<double> result(1, m);
        int32           i = 0;
        for (auto n : linspace(0., mDouble, m, EndPoint::YES))
        {
            const auto nOverM = n / mDouble;
            result[i++] =
                0.42 - 0.5 * std::cos(2. * constants::pi * nOverM) + 0.08 * std::cos(4. * constants::pi * nOverM);
        }

        return result;
    }
} // namespace nc
