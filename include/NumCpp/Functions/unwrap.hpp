
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
    /// Unwrap by changing deltas between values to 2*pi complement.
    /// Unwraps to [-pi, pi].
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.unwrap.html
    ///
    /// @param inValue
    ///
    /// @return value
    ///
    template<typename dtype>
    dtype unwrap(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return static_cast<dtype>(std::atan2(std::sin(inValue), std::cos(inValue)));
    }

    //============================================================================
    // Method Description:
    /// Unwrap by changing deltas between values to 2*pi complement.
    /// Unwraps to [-pi, pi].
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.unwrap.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> unwrap(const NdArray<dtype>& inArray)
    {
        NdArray<dtype> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> dtype { return unwrap(inValue); });

        return returnArray;
    }
} // namespace nc
