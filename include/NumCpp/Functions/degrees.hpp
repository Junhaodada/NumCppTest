
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Functions/rad2deg.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Convert angles from degrees to radians.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.degrees.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    constexpr auto degrees(dtype inValue) noexcept
    {
        return rad2deg(inValue);
    }

    //============================================================================
    // Method Description:
    /// Convert angles from degrees to radians.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.degrees.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto degrees(const NdArray<dtype>& inArray)
    {
        return rad2deg(inArray);
    }
} // namespace nc
