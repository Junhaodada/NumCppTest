
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
    /// Return the minimum of an array or minimum along an axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.amin.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return min value
    ///
    template<typename dtype>
    NdArray<dtype> amin(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.min(inAxis);
    }
} // namespace nc
