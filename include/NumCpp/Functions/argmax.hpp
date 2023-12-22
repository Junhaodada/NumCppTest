
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
    /// Returns the indices of the maximum values along an axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.argmax.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<uint32> argmax(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.argmax(inAxis);
    }
} // namespace nc
