
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
    /// Trigonometric inverse tangent.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arctan.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto arctan(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::atan(inValue);
    }

    //============================================================================
    // Method Description:
    /// Trigonometric inverse tangent, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arctan.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto arctan(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(arctan(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return arctan(inValue); });

        return returnArray;
    }
} // namespace nc
