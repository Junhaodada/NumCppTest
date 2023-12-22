
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Trigonometric inverse hyperbolic sine.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arcsinh.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto arcsinh(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::asinh(inValue);
    }

    //============================================================================
    // Method Description:
    /// Trigonometric inverse hyperbolic sine, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arcsinh.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto arcsinh(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(arcsinh(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return arcsinh(inValue); });

        return returnArray;
    }
} // namespace nc
