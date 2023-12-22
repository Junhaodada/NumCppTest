
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
    /// Trigonometric inverse cosine
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arccos.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto arccos(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::acos(inValue);
    }

    //============================================================================
    // Method Description:
    /// Trigonometric inverse cosine, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arccos.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto arccos(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(arccos(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return arccos(inValue); });

        return returnArray;
    }
} // namespace nc
