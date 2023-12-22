
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
    /// Base-2 logarithm of x.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log2.html
    ///
    /// @param inValue
    ///
    /// @return value
    ///
    template<typename dtype>
    auto log2(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::log2(inValue);
    }

    //============================================================================
    // Method Description:
    /// Base-2 logarithm of x.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log2.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto log2(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(log2(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return log2(inValue); });

        return returnArray;
    }
} // namespace nc
