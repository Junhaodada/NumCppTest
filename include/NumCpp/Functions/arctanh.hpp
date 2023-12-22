
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
    /// Trigonometric inverse hyperbolic tangent.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arctanh.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto arctanh(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::atanh(inValue);
    }

    //============================================================================
    // Method Description:
    /// Trigonometric inverse hyperbolic tangent, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arctanh.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto arctanh(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(arctanh(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return arctanh(inValue); });

        return returnArray;
    }
} // namespace nc
