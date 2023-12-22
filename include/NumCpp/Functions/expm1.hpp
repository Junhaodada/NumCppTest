
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
    /// Calculate exp(x) - 1 for the input value.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.expm1.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto expm1(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::exp(inValue) - dtype{ 1 };
    }

    //============================================================================
    // Method Description:
    /// Calculate exp(x) - 1 for all elements in the array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.expm1.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto expm1(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(expm1(dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return expm1(inValue); });

        return returnArray;
    }
} // namespace nc
