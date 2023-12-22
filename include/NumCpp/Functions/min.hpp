
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the minimum of an array or minimum along an axis.
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> min(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.min(inAxis);
    }
} // namespace nc
