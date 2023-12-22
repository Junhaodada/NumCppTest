
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
    /// Round value to the given number of decimals.
    ///
    /// @param inValue
    /// @param inDecimals
    ///
    /// @return value
    ///
    template<typename dtype>
    dtype round(dtype inValue, uint8 inDecimals = 0)
    {
        NdArray<dtype> input = { inValue };
        return input.round(inDecimals).item();
    }

    //============================================================================
    // Method Description:
    /// Round an array to the given number of decimals.
    ///
    /// @param inArray
    /// @param inDecimals
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> round(const NdArray<dtype>& inArray, uint8 inDecimals = 0)
    {
        return inArray.round(inDecimals);
    }
} // namespace nc
