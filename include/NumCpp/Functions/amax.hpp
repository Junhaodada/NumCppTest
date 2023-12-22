
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
    /// Return the maximum of an array or maximum along an axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.amax.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return max value
    ///
    template<typename dtype>
    NdArray<dtype> amax(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.max(inAxis);
    }
} // namespace nc
