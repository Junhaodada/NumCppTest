
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <utility>

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the indices of the flattened array of the
    /// elements that are non-zero.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.nonzero.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    std::pair<NdArray<uint32>, NdArray<uint32>> nonzero(const NdArray<dtype>& inArray)
    {
        return inArray.nonzero();
    }
} // namespace nc
