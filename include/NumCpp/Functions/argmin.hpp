
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
    /// Returns the indices of the minimum values along an axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.argmin.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<uint32> argmin(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.argmin(inAxis);
    }
} // namespace nc
