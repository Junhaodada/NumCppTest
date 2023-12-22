
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the maximum of an array or maximum along an axis.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> max(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.max(inAxis);
    }
} // namespace nc
