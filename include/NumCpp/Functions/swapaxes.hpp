
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Interchange two axes of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.swapaxes.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> swapaxes(const NdArray<dtype>& inArray)
    {
        return inArray.swapaxes();
    }
} // namespace nc
