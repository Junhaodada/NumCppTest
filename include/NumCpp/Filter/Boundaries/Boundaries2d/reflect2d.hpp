
/// Description
/// Reflects the boundaries
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/flipud.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter::boundary
{
    //============================================================================
    // Method Description:
    /// Reflects the boundaries
    ///
    /// @param inImage
    /// @param inBoundarySize
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> reflect2d(const NdArray<dtype>& inImage, uint32 inBoundarySize)
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

        for (uint32 row = 0; row < inBoundarySize; ++row)
        {
            // bottom
            outArray.put(row,
                         Slice(inBoundarySize, inBoundarySize + inShape.cols),
                         inImage(inBoundarySize - row - 1, Slice(0, inShape.cols)));

            // top
            outArray.put(row + inBoundarySize + inShape.rows,
                         Slice(inBoundarySize, inBoundarySize + inShape.cols),
                         inImage(inShape.rows - row - 1, Slice(0, inShape.cols)));
        }

        for (uint32 col = 0; col < inBoundarySize; ++col)
        {
            // left
            outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                         col,
                         inImage(Slice(0, inShape.rows), inBoundarySize - col - 1));

            // right
            outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                         col + inBoundarySize + inShape.cols,
                         inImage(Slice(0, inShape.rows), inShape.cols - col - 1));
        }

        // now fill in the corners
        NdArray<dtype> lowerLeft =
            flipud(outArray(Slice(inBoundarySize, 2 * inBoundarySize), Slice(0, inBoundarySize)));
        NdArray<dtype> lowerRight = flipud(
            outArray(Slice(inBoundarySize, 2 * inBoundarySize), Slice(outShape.cols - inBoundarySize, outShape.cols)));

        const uint32   upperRowStart = outShape.rows - 2 * inBoundarySize;
        NdArray<dtype> upperLeft =
            flipud(outArray(Slice(upperRowStart, upperRowStart + inBoundarySize), Slice(0, inBoundarySize)));
        NdArray<dtype> upperRight = flipud(outArray(Slice(upperRowStart, upperRowStart + inBoundarySize),
                                                    Slice(outShape.cols - inBoundarySize, outShape.cols)));

        outArray.put(Slice(0, inBoundarySize), Slice(0, inBoundarySize), lowerLeft);
        outArray.put(Slice(0, inBoundarySize), Slice(outShape.cols - inBoundarySize, outShape.cols), lowerRight);
        outArray.put(Slice(outShape.rows - inBoundarySize, outShape.rows), Slice(0, inBoundarySize), upperLeft);
        outArray.put(Slice(outShape.rows - inBoundarySize, outShape.rows),
                     Slice(outShape.cols - inBoundarySize, outShape.cols),
                     upperRight);

        return outArray;
    }
} // namespace nc::filter::boundary
