
/// Description
/// Constant boundary1d
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter::boundary
{
    //============================================================================
    // Method Description:
    /// Constant boundary1d
    ///
    /// @param inImage
    /// @param inBoundarySize
    /// @param inConstantValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> constant1d(const NdArray<dtype>& inImage, uint32 inBoundarySize, dtype inConstantValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const uint32 outSize = inImage.size() + inBoundarySize * 2;

        NdArray<dtype> outArray(1, outSize);
        outArray.put(Slice(inBoundarySize, inBoundarySize + inImage.size()), inImage);

        // left
        outArray.put(Slice(0, inBoundarySize), inConstantValue);

        // right
        outArray.put(Slice(inImage.size() + inBoundarySize, outSize), inConstantValue);

        return outArray;
    }
} // namespace nc::filter::boundary
