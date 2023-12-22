
/// Description
/// Applies a threshold to an image
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::imageProcessing
{
    //============================================================================
    // Method Description:
    /// Applies a threshold to an image
    ///
    /// @param inImageArray
    /// @param inThreshold
    /// @return NdArray of booleans of pixels that exceeded the threshold
    ///
    template<typename dtype>
    NdArray<bool> applyThreshold(const NdArray<dtype>& inImageArray, dtype inThreshold)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return inImageArray > inThreshold;
    }
} // namespace nc::imageProcessing
