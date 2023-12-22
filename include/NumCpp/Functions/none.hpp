
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
    /// Test whether no array elements along a given axis evaluate to True.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.all.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return bool
    ///
    template<typename dtype>
    NdArray<bool> none(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.none(inAxis);
    }
} // namespace nc
