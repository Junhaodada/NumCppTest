
/// Description
/// Nearest boundary1d
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter::boundary
{
    //============================================================================
    // Method Description:
    /// Nearest boundary1d
    ///
    /// @param inImage
    /// @param inBoundarySize
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> nearest1d(const NdArray<dtype>& inImage, uint32 inBoundarySize)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const uint32 outSize = inImage.size() + inBoundarySize * 2;

        NdArray<dtype> outArray(1, outSize);
        outArray.put(Slice(inBoundarySize, inBoundarySize + inImage.size()), inImage);

        // left
        outArray.put(Slice(0, inBoundarySize), inImage.front());

        // right
        outArray.put(Slice(inImage.size() + inBoundarySize, outSize), inImage.back());

        return outArray;
    }
} // namespace nc::filter::boundary
