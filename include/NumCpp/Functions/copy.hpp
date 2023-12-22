
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return an array copy of the given object.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.copy.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> copy(const NdArray<dtype>& inArray)
    {
        return NdArray<dtype>(inArray);
    }
} // namespace nc
