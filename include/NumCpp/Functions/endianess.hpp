
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the endianess of the array values.
    ///
    /// @param inArray
    /// @return Endian
    ///
    template<typename dtype>
    Endian endianess(const NdArray<dtype>& inArray) noexcept
    {
        return inArray.endianess();
    }
} // namespace nc
