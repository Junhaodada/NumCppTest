
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
    /// Range of values (maximum - minimum) along an axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.ptp.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> ptp(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        return inArray.ptp(inAxis);
    }
} // namespace nc
