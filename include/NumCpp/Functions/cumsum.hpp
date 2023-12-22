
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
    /// Return the cumulative sum of the elements along a given axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.cumsum.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> cumsum(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.cumsum(inAxis);
    }
} // namespace nc
