
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
    /// Returns the indices that would sort an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.argsort.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<uint32> argsort(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.argsort(inAxis);
    }
} // namespace nc
