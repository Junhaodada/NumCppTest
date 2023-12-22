
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
    /// Test whether all array elements along a given axis evaluate to True.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.all.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return bool
    ///
    template<typename dtype>
    NdArray<bool> all(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.all(inAxis);
    }
} // namespace nc
