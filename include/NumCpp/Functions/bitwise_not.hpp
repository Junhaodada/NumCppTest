
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the bit-wise NOT the input array element-wise.
    ///
    /// inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> bitwise_not(const NdArray<dtype>& inArray)
    {
        return ~inArray;
    }
} // namespace nc
