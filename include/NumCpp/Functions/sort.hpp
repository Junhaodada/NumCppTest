
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
    /// Return a sorted copy of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sort.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> sort(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        NdArray<dtype> returnArray(inArray);
        returnArray.sort(inAxis);
        return returnArray;
    }
} // namespace nc
