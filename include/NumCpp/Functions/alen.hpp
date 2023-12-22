
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
    /// Return the length of the first dimension of the input array.
    ///
    /// @param inArray
    /// @return length uint16
    ///
    template<typename dtype>
    uint32 alen(const NdArray<dtype>& inArray) noexcept
    {
        return inArray.shape().rows;
    }
} // namespace nc
