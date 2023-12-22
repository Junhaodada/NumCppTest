
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Copies values from one array to another
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.copyto.html
    ///
    /// @param inDestArray
    /// @param inSrcArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& copyto(NdArray<dtype>& inDestArray, const NdArray<dtype>& inSrcArray)
    {
        inDestArray = inSrcArray;
        return inDestArray;
    }
} // namespace nc
