
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
    /// Calculate 2**p for all p in the input value.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.exp2.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto exp2(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::exp2(inValue);
    }

    //============================================================================
    // Method Description:
    /// Calculate 2**p for all p in the input array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.exp2.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto exp2(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(exp2(dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return exp2(inValue); });

        return returnArray;
    }
} // namespace nc
