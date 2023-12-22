
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
    /// Return specified diagonals.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.diagonal.html
    ///
    /// @param inArray
    /// @param inOffset (Defaults to 0)
    /// @param inAxis (Optional, default ROW) axis the offset is applied to
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> diagonal(const NdArray<dtype>& inArray, int32 inOffset = 0, Axis inAxis = Axis::ROW)
    {
        return inArray.diagonal(inOffset, inAxis);
    }
} // namespace nc
