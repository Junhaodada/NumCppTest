
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
    /// Calculate the absolute value.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.absolute.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto abs(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::abs(inValue);
    }

    //============================================================================
    // Method Description:
    /// Calculate the absolute value element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.absolute.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto abs(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(nc::abs(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return nc::abs(inValue); });

        return returnArray;
    }
} // namespace nc
