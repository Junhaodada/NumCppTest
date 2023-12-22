
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray/NdArrayCore.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Swaps the contents of two arrays
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    template<typename dtype>
    void swap(NdArray<dtype>& inArray1, NdArray<dtype>& inArray2) noexcept
    {
        NdArray<dtype> tmp(std::move(inArray1));
        inArray1 = std::move(inArray2);
        inArray2 = std::move(tmp);
    }
} // namespace nc
