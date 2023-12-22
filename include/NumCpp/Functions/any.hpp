
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
    /// Test whether any array element along a given axis evaluates to True.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.any.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> any(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.any(inAxis);
    }
} // namespace nc
