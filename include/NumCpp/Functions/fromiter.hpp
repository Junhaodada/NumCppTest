
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <iterator>
#include <vector>

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Create a new 1-dimensional array from an iterable object.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fromiter.html
    ///
    /// @param inBegin
    /// @param inEnd
    /// @return NdArray
    ///
    template<typename dtype, typename Iter>
    NdArray<dtype> fromiter(Iter inBegin, Iter inEnd)
    {
        return NdArray<dtype>(inBegin, inEnd);
    }
} // namespace nc
