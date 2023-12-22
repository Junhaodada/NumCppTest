
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the bit-wise XOR of two arrays element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.bitwise_xor.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> bitwise_xor(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 ^ inArray2;
    }
} // namespace nc
