
/// Description
/// Nearest boundary
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/fillCorners.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter::boundary
{
    //============================================================================
    // Method Description:
    /// Nearest boundary
    ///
    /// @param inImage
    /// @param inBoundarySize
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> nearest2d(const NdArray<dtype>& inImage, uint32 inBoundarySize)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const Shape inShape = inImage.shape();
        Shape       outShape(inShape);
        outShape.rows += inBoundarySize * 2;
        outShape.cols += inBoundarySize * 2;

        NdArray<dtype> outArray(outShape);
        outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                     Slice(inBoundarySize, inBoundarySize + inShape.cols),
                     inImage);
        fillCorners(outArray, inBoundarySize);

        for (uint32 row = 0; row < inBoundarySize; ++row)
        {
            // bottom
            outArray.put(row, Slice(inBoundarySize, inBoundarySize + inShape.cols), inImage(0, Slice(0, inShape.cols)));

            // top
            outArray.put(row + inBoundarySize + inShape.rows,
                         Slice(inBoundarySize, inBoundarySize + inShape.cols),
                         inImage(inShape.rows - 1, Slice(0, inShape.cols)));
        }

        for (uint32 col = 0; col < inBoundarySize; ++col)
        {
            // left
            outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows), col, inImage(Slice(0, inShape.rows), 0));

            // right
            outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                         col + inBoundarySize + inShape.cols,
                         inImage(Slice(0, inShape.rows), inShape.cols - 1));
        }

        return outArray;
    }
} // namespace nc::filter::boundary
