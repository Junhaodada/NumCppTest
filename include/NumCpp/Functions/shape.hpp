
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the shape of the array
    ///
    /// @param inArray
    /// @return Shape
    ///
    template<typename dtype>
    Shape shape(const NdArray<dtype>& inArray) noexcept
    {
        return inArray.shape();
    }
} // namespace nc
