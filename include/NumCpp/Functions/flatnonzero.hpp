
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return indices that are non-zero in the flattened version of a.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.flatnonzero.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<uint32> flatnonzero(const NdArray<dtype>& inArray)
    {
        return inArray.flatnonzero();
    }
} // namespace nc
