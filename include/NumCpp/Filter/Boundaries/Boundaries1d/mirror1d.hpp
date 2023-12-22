
/// Description
/// Mirror boundary1d
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/fliplr.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter::boundary
{
    //============================================================================
    // Method Description:
    /// Mirror boundary1d
    ///
    /// @param inImage
    /// @param inBoundarySize
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> mirror1d(const NdArray<dtype>& inImage, uint32 inBoundarySize)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const uint32 outSize = inImage.size() + inBoundarySize * 2;

        NdArray<dtype> outArray(1, outSize);
        outArray.put(Slice(inBoundarySize, inBoundarySize + inImage.size()), inImage);

        // left
        outArray.put(Slice(0, inBoundarySize), fliplr(inImage[Slice(1, inBoundarySize + 1)]));

        // right
        outArray.put(Slice(inImage.size() + inBoundarySize, outSize),
                     fliplr(inImage[Slice(-static_cast<int32>(inBoundarySize) - 1, -1)]));

        return outArray;
    }
} // namespace nc::filter::boundary
