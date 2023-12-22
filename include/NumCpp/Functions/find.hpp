
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <limits>

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Find flat indices of nonzero elements.
    ///
    /// @param mask: the mask to apply to the array
    /// @param n: the first n indices to return (optional, default all)
    ///
    /// @return NdArray
    ///
    inline NdArray<uint32> find(const NdArray<bool>& mask, uint32 n = std::numeric_limits<uint32>::max())
    {
        NdArray<uint32> indices = mask.flatnonzero();

        if (indices.size() <= n)
        {
            return indices;
        }

        return indices[Slice(0, n)];
    }
} // namespace nc
