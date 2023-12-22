
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Trigonometric inverse tangent.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arctan2.html
    ///
    /// @param inY
    /// @param inX
    /// @return value
    ///
    template<typename dtype>
    auto arctan2(dtype inY, dtype inX) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::atan2(inY, inX);
    }

    //============================================================================
    // Method Description:
    /// Trigonometric inverse tangent, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arctan2.html
    ///
    /// @param inY
    /// @param inX
    /// @return NdArray
    ///
    template<typename dtype>
    auto arctan2(const NdArray<dtype>& inY, const NdArray<dtype>& inX)
    {
        if (inX.shape() != inY.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array shapes are not consistant.");
        }

        NdArray<decltype(arctan2(dtype{ 0 }, dtype{ 0 }))> returnArray(inY.shape());
        stl_algorithms::transform(inY.cbegin(),
                                  inY.cend(),
                                  inX.cbegin(),
                                  returnArray.begin(),
                                  [](dtype y, dtype x) noexcept -> auto { return arctan2(y, x); });

        return returnArray;
    }
} // namespace nc
