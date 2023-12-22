
/// Description
/// trims the boundary off to make the image back to the original size
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
    /// trims the boundary off to make the image back to the original size
    ///
    /// @param inImageWithBoundary
    /// @param inSize
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> trimBoundary1d(const NdArray<dtype>& inImageWithBoundary, uint32 inSize)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        uint32 boundarySize = inSize / 2; // integer division
        uint32 imageSize    = inImageWithBoundary.size() - boundarySize * 2;

        return inImageWithBoundary[Slice(boundarySize, boundarySize + imageSize)];
    }
} // namespace nc::filter::boundary
