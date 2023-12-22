
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array with the bytes of the array elements
    /// swapped.
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> byteswap(const NdArray<dtype>& inArray)
    {
        NdArray<dtype> returnArray(inArray);
        returnArray.byteswap();
        return returnArray;
    }
} // namespace nc
