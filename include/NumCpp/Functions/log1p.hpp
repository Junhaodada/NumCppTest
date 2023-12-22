
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
    /// Return the natural logarithm of one plus the input array.
    ///
    /// Calculates log(1 + x).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log1p.html
    ///
    /// @param inValue
    ///
    /// @return value
    ///
    template<typename dtype>
    auto log1p(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::log1p(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the natural logarithm of one plus the input array, element-wise.
    ///
    /// Calculates log(1 + x).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log1p.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto log1p(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(log1p(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return log1p(inValue); });

        return returnArray;
    }
} // namespace nc
