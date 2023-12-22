
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Replaces the matching elements of an array with the new value
    ///
    /// @param inArray
    /// @param oldValue: the value to replace
    /// @param newValue: the value to replace with
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> replace(const NdArray<dtype>& inArray, dtype oldValue, dtype newValue)
    {
        auto returnArray = inArray.copy();
        returnArray.replace(oldValue, newValue);
        return returnArray;
    }
} // namespace nc
