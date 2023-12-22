
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
    /// Calculate the exponential of the input value.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.exp.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto exp(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::exp(inValue);
    }

    //============================================================================
    // Method Description:
    /// Calculate the exponential of all elements in the input array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.exp.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto exp(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(exp(dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return exp(inValue); });

        return returnArray;
    }
} // namespace nc
