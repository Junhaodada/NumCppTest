
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Functions/full.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a full array with the same shape and type as a given array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.full_like.html
    ///
    /// @param inArray
    /// @param inFillValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> full_like(const NdArray<dtype>& inArray, dtype inFillValue)
    {
        return full(inArray.shape(), inFillValue);
    }
} // namespace nc
