
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
    /// Sum of array elements over a given axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sum.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> sum(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.sum(inAxis);
    }
} // namespace nc
