
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Changes elements of an array based on conditional and input values.
    ///
    /// Sets a.flat[n] = values[n] for each n where mask.flat[n] == True.
    ///
    /// If values is not the same size as a and mask then it will repeat.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.putmask.html
    ///
    /// @param inArray
    /// @param inMask
    /// @param inValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& putmask(NdArray<dtype>& inArray, const NdArray<bool>& inMask, dtype inValue)
    {
        inArray.putMask(inMask, inValue);
        return inArray;
    }

    //============================================================================
    // Method Description:
    /// Changes elements of an array based on conditional and input values.
    ///
    /// Sets a.flat[n] = values[n] for each n where mask.flat[n] == True.
    ///
    /// If values is not the same size as a and mask then it will repeat.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.putmask.html
    ///
    /// @param inArray
    /// @param inMask
    /// @param inValues
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& putmask(NdArray<dtype>& inArray, const NdArray<bool>& inMask, const NdArray<dtype>& inValues)
    {
        inArray.putMask(inMask, inValues);
        return inArray;
    }
} // namespace nc
