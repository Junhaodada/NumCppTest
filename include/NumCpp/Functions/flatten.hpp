
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a copy of the array collapsed into one dimension.
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> flatten(const NdArray<dtype>& inArray)
    {
        return inArray.flatten();
    }
} // namespace nc
