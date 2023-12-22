
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Find the indices of array elements that are non-zero, grouped by element.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.argwhere.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<uint32> argwhere(const NdArray<dtype>& inArray)
    {
        return inArray.flatnonzero();
    }
} // namespace nc
