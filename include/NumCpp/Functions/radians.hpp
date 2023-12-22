
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Functions/deg2rad.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Convert angles from degrees to radians.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.radians.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    constexpr auto radians(dtype inValue) noexcept
    {
        return deg2rad(inValue);
    }

    //============================================================================
    // Method Description:
    /// Convert angles from degrees to radians.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.radians.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto radians(const NdArray<dtype>& inArray)
    {
        return deg2rad(inArray);
    }
} // namespace nc
