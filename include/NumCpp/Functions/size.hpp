
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
    /// Return the number of elements.
    ///
    /// @param inArray
    /// @return uint32 size
    ///
    template<typename dtype>
    uint32 size(const NdArray<dtype>& inArray) noexcept
    {
        return inArray.size();
    }
} // namespace nc
