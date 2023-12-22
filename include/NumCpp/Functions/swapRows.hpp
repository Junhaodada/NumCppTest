
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray/NdArrayCore.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Swaps rows of the array
    ///
    /// @param inArray
    /// @param rowIdx1
    /// @param rowIdx2
    ///
    template<typename dtype>
    NdArray<dtype>& swapRows(NdArray<dtype>& inArray, int32 rowIdx1, int32 rowIdx2) noexcept
    {
        inArray.swapRows(rowIdx1, rowIdx2);
        return inArray;
    }
} // namespace nc
