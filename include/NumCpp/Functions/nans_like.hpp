
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with nans.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> nans_like(const NdArray<dtype>& inArray)
    {
        NdArray<double> returnArray(inArray.shape());
        returnArray.nans();
        return returnArray;
    }
} // namespace nc
