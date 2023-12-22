
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Slice.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Pads an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.pad.html
    ///
    /// @param inArray
    /// @param inPadWidth
    /// @param inPadValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> pad(const NdArray<dtype>& inArray, uint16 inPadWidth, dtype inPadValue)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const Shape inShape = inArray.shape();
        Shape       outShape(inShape);
        outShape.rows += 2 * inPadWidth;
        outShape.cols += 2 * inPadWidth;

        NdArray<dtype> returnArray(outShape);
        returnArray.fill(inPadValue);
        returnArray.put(Slice(inPadWidth, inPadWidth + inShape.rows),
                        Slice(inPadWidth, inPadWidth + inShape.cols),
                        inArray);

        return returnArray;
    }
} // namespace nc
