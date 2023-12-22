
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the floor of the input.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.floor.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    dtype floor(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::floor(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the floor of the input, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.floor.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> floor(const NdArray<dtype>& inArray)
    {
        NdArray<dtype> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> dtype { return floor(inValue); });

        return returnArray;
    }
} // namespace nc
