
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
    /// Return the base 10 logarithm of the input array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log10.html
    ///
    /// @param inValue
    ///
    /// @return value
    ///
    template<typename dtype>
    auto log10(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::log10(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the base 10 logarithm of the input array, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log10.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto log10(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(log10(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return log10(inValue); });

        return returnArray;
    }
} // namespace nc
