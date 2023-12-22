
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
    /// returns whether or not a value is included the array
    ///
    /// @param inArray
    /// @param inValue
    /// @param inAxis (Optional, default NONE)
    /// @return bool
    ///
    template<typename dtype>
    NdArray<bool> contains(const NdArray<dtype>& inArray, dtype inValue, Axis inAxis = Axis::NONE)
    {
        return inArray.contains(inValue, inAxis);
    }
} // namespace nc
