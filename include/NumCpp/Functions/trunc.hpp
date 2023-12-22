
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
    /// Return the truncated value of the input.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.trunc.html
    ///
    /// @param inValue
    ///
    /// @return value
    ///
    template<typename dtype>
    dtype trunc(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::trunc(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the truncated value of the input, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.trunc.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> trunc(const NdArray<dtype>& inArray)
    {
        NdArray<dtype> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> dtype { return trunc(inValue); });

        return returnArray;
    }
} // namespace nc
