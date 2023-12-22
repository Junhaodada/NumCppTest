
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Permute the dimensions of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.transpose.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> transpose(const NdArray<dtype>& inArray)
    {
        return inArray.transpose();
    }
} // namespace nc
