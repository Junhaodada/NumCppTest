
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns element-wise True where signbit is set (less than zero).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.signbit.html
    ///
    /// @param inValue
    /// @return NdArray
    ///
    template<typename dtype>
    bool signbit(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return inValue < dtype{ 0 } ? true : false;
    }

    //============================================================================
    // Method Description:
    /// Returns element-wise True where signbit is set (less than zero).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.signbit.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> signbit(const NdArray<dtype>& inArray)
    {
        NdArray<bool> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> bool { return signbit(inValue); });

        return returnArray;
    }
} // namespace nc
