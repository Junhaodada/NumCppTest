
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return element-wise remainder of division.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.mod.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> mod(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 % inArray2;
    }
} // namespace nc
