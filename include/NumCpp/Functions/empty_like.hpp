
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array with the same shape as a given array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.empty_like.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> empty_like(const NdArray<dtype>& inArray)
    {
        return NdArray<dtype>(inArray.shape());
    }
} // namespace nc
