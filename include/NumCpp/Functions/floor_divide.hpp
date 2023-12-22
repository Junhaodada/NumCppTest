
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/floor.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the largest integer smaller or equal to the division of the inputs.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.floor_divide.html
    ///
    /// @param inValue1
    /// @param inValue2
    /// @return value
    ///
    template<typename dtype>
    dtype floor_divide(dtype inValue1, dtype inValue2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::floor(inValue1 / inValue2);
    }

    //============================================================================
    // Method Description:
    /// Return the largest integer smaller or equal to the division of the inputs.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.floor_divide.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> floor_divide(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return floor(inArray1 / inArray2);
    }
} // namespace nc
