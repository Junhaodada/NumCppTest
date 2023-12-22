
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <complex>

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the positive square-root of a value.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sqrt.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto sqrt(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::sqrt(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the positive square-root of an array, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sqrt.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto sqrt(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(sqrt(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return sqrt(inValue); });

        return returnArray;
    }
} // namespace nc
