
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the truth value of (x1 >= x2) element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.greater_equal.html
    ///
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> greater_equal(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 >= inArray2;
    }
} // namespace nc
