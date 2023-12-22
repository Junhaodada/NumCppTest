
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
    /// Shift the bits of an integer to the left.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.left_shift.html
    ///
    /// @param inArray
    /// @param inNumBits
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> left_shift(const NdArray<dtype>& inArray, uint8 inNumBits)
    {
        return inArray << inNumBits;
    }
} // namespace nc
