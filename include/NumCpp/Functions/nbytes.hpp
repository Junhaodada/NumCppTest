
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns the number of bytes held by the array
    ///
    /// @param inArray
    /// @return number of bytes
    ///
    template<typename dtype>
    uint64 nbytes(const NdArray<dtype>& inArray) noexcept
    {
        return inArray.nbytes();
    }
} // namespace nc
