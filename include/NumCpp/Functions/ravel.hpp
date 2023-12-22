
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Flattens the array but does not make a copy.
    ///
    /// Numpy Reference: https://docs.scipy.org/doc/numpy/reference/generated/numpy.ravel.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& ravel(NdArray<dtype>& inArray) noexcept
    {
        inArray.ravel();
        return inArray;
    }
} // namespace nc
