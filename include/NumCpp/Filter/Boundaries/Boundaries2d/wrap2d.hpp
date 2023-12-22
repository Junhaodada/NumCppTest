
/// Description
/// Wrap boundary
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
    /// Wrap boundary
    ///
    /// @param inImage
    /// @param inBoundarySize
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> wrap2d(const NdArray<dtype>& inImage, uint32 inBoundarySize)
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

        // bottom
        outArray.put(Slice(0, inBoundarySize),
                     Slice(inBoundarySize, inBoundarySize + inShape.cols),
                     inImage(Slice(inShape.rows - inBoundarySize, inShape.rows), Slice(0, inShape.cols)));

        // top
        outArray.put(Slice(inShape.rows + inBoundarySize, outShape.rows),
                     Slice(inBoundarySize, inBoundarySize + inShape.cols),
                     inImage(Slice(0, inBoundarySize), Slice(0, inShape.cols)));

        // left
        outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                     Slice(0, inBoundarySize),
                     inImage(Slice(0, inShape.rows), Slice(inShape.cols - inBoundarySize, inShape.cols)));

        // right
        outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                     Slice(inShape.cols + inBoundarySize, outShape.cols),
                     inImage(Slice(0, inShape.rows), Slice(0, inBoundarySize)));

        // now fill in the corners
        NdArray<dtype> lowerLeft = outArray(Slice(inBoundarySize, 2 * inBoundarySize), Slice(0, inBoundarySize));
        NdArray<dtype> lowerRight =
            outArray(Slice(inBoundarySize, 2 * inBoundarySize), Slice(outShape.cols - inBoundarySize, outShape.cols));

        const uint32   upperRowStart = outShape.rows - 2 * inBoundarySize;
        NdArray<dtype> upperLeft =
            outArray(Slice(upperRowStart, upperRowStart + inBoundarySize), Slice(0, inBoundarySize));
        NdArray<dtype> upperRight = outArray(Slice(upperRowStart, upperRowStart + inBoundarySize),
                                             Slice(outShape.cols - inBoundarySize, outShape.cols));

        outArray.put(Slice(0, inBoundarySize), Slice(0, inBoundarySize), upperLeft);
        outArray.put(Slice(0, inBoundarySize), Slice(outShape.cols - inBoundarySize, outShape.cols), upperRight);
        outArray.put(Slice(outShape.rows - inBoundarySize, outShape.rows), Slice(0, inBoundarySize), lowerLeft);
        outArray.put(Slice(outShape.rows - inBoundarySize, outShape.rows),
                     Slice(outShape.cols - inBoundarySize, outShape.cols),
                     lowerRight);

        return outArray;
    }
} // namespace nc::filter::boundary
