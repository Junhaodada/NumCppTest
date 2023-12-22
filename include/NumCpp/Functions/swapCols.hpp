
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray/NdArrayCore.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Swaps cols of the array
    ///
    /// @param inArray
    /// @param colIdx1
    /// @param colIdx2
    ///
    template<typename dtype>
    NdArray<dtype>& swapCols(NdArray<dtype>& inArray, int32 colIdx1, int32 colIdx2) noexcept
    {
        inArray.swapCols(colIdx1, colIdx2);
        return inArray;
    }
} // namespace nc
