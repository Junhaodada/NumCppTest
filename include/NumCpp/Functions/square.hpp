
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the square of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.square.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    constexpr dtype square(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return utils::sqr(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the square of an array, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.square.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> square(const NdArray<dtype>& inArray)
    {
        NdArray<dtype> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> dtype { return square(inValue); });

        return returnArray;
    }
} // namespace nc
