
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Evenly round to the given number of decimals.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.around.html
    ///
    /// @param inValue
    /// @param inNumDecimals: (Optional, default = 0)
    /// @return value
    ///
    template<typename dtype>
    dtype around(dtype inValue, uint8 inNumDecimals = 0)
    {
        NdArray<dtype> value = { inValue };
        return value.round(inNumDecimals).item();
    }

    //============================================================================
    // Method Description:
    /// Evenly round to the given number of decimals.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.around.html
    ///
    /// @param inArray
    /// @param inNumDecimals: (Optional, default = 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> around(const NdArray<dtype>& inArray, uint8 inNumDecimals = 0)
    {
        return inArray.round(inNumDecimals);
    }
} // namespace nc
