
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
    /// Rearranges the elements in the array in such a way that
    /// value of the element in kth position is in the position it
    /// would be in a sorted array. All elements smaller than the kth
    /// element are moved before this element and all equal or greater
    /// are moved behind it. The ordering of the elements in the two
    /// partitions is undefined.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.partition.html
    ///
    /// @param inArray
    /// @param inKth: kth element
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> partition(const NdArray<dtype>& inArray, uint32 inKth, Axis inAxis = Axis::NONE)
    {
        NdArray<dtype> returnArray(inArray);
        returnArray.partition(inKth, inAxis);
        return returnArray;
    }
} // namespace nc
