
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
    /// Return the sum along diagonals of the array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.trace.html
    ///
    /// @param inArray
    /// @param inOffset: (Offset from main diaganol, default = 0, negative=above, positve=below)
    /// @param inAxis (Optional, default ROW)
    /// @return NdArray
    ///
    template<typename dtype>
    dtype trace(const NdArray<dtype>& inArray, int16 inOffset = 0, Axis inAxis = Axis::ROW) noexcept
    {
        return inArray.trace(inOffset, inAxis);
    }
} // namespace nc
