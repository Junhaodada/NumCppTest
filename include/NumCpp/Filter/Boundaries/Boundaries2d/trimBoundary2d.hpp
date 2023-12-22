
/// Description
/// trims the boundary off to make the image back to the original size
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
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
    NdArray<dtype> trimBoundary2d(const NdArray<dtype>& inImageWithBoundary, uint32 inSize)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        Shape  inShape      = inImageWithBoundary.shape();
        uint32 boundarySize = inSize / 2; /// integer division

        inShape.rows -= boundarySize * 2;
        inShape.cols -= boundarySize * 2;

        return inImageWithBoundary(Slice(boundarySize, boundarySize + inShape.rows),
                                   Slice(boundarySize, boundarySize + inShape.cols));
    }
} // namespace nc::filter::boundary
