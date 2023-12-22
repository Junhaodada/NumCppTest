
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
    /// Hyperbolic sine.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sinh.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto sinh(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::sinh(inValue);
    }

    //============================================================================
    // Method Description:
    /// Hyperbolic sine, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sinh.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto sinh(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(sinh(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return sinh(inValue); });

        return returnArray;
    }
} // namespace nc
