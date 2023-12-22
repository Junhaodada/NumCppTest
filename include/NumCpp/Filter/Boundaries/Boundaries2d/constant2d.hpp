
/// Description
/// Constant boundary
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
    /// Constant boundary
    ///
    /// @param inImage
    /// @param inBoundarySize
    /// @param inConstantValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> constant2d(const NdArray<dtype>& inImage, uint32 inBoundarySize, dtype inConstantValue)
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
        fillCorners(outArray, inBoundarySize, inConstantValue);

        outArray.put(Slice(0, inBoundarySize),
                     Slice(inBoundarySize, inBoundarySize + inShape.cols),
                     inConstantValue); /// bottom
        outArray.put(Slice(outShape.rows - inBoundarySize, outShape.rows),
                     Slice(inBoundarySize, inBoundarySize + inShape.cols),
                     inConstantValue); /// top
        outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                     Slice(0, inBoundarySize),
                     inConstantValue); /// left
        outArray.put(Slice(inBoundarySize, inBoundarySize + inShape.rows),
                     Slice(outShape.cols - inBoundarySize, outShape.cols),
                     inConstantValue); /// right

        return outArray;
    }
} // namespace nc::filter::boundary
