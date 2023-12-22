
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StdComplexOperators.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns an element-wise indication of the sign of a number.
    ///
    /// The sign function returns - 1 if x < 0, 0 if x == 0, 1 if x > 0.
    /// nan is returned for nan inputs.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sign.html
    ///
    /// @param inValue
    /// @return NdArray
    ///
    template<typename dtype>
    int8 sign(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        if (inValue < dtype{ 0 })
        {
            return -1;
        }

        if (inValue > dtype{ 0 })
        {
            return 1;
        }

        return 0;
    }

    //============================================================================
    // Method Description:
    /// Returns an element-wise indication of the sign of a number.
    ///
    /// The sign function returns - 1 if x < 0, 0 if x == 0, 1 if x > 0.
    /// nan is returned for nan inputs.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sign.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<int8> sign(const NdArray<dtype>& inArray)
    {
        NdArray<int8> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> int8 { return sign(inValue); });

        return returnArray;
    }
} // namespace nc
