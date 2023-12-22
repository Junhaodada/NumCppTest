
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Write flattened array to an STL vector
    ///
    /// @param inArray
    /// @return std::vector
    ///
    template<typename dtype>
    std::vector<dtype> toStlVector(const NdArray<dtype>& inArray)
    {
        return inArray.toStlVector();
    }
} // namespace nc
