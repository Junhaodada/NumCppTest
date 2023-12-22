
/// Description
/// extends the corner values
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
    /// extends the corner values
    ///
    /// @param inArray
    /// @param inBorderWidth
    ///
    template<typename dtype>
    void fillCorners(NdArray<dtype>& inArray, uint32 inBorderWidth)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const Shape inShape = inArray.shape();
        const auto  numRows = static_cast<int32>(inShape.rows);
        const auto  numCols = static_cast<int32>(inShape.cols);

        // top left
        inArray.put(Slice(0, inBorderWidth), Slice(0, inBorderWidth), inArray(inBorderWidth, inBorderWidth));

        // top right
        inArray.put(Slice(0, inBorderWidth),
                    Slice(numCols - inBorderWidth, numCols),
                    inArray(inBorderWidth, numCols - inBorderWidth - 1));

        // bottom left
        inArray.put(Slice(numRows - inBorderWidth, numRows),
                    Slice(0, inBorderWidth),
                    inArray(numRows - inBorderWidth - 1, inBorderWidth));

        // bottom right
        inArray.put(Slice(numRows - inBorderWidth, numRows),
                    Slice(numCols - inBorderWidth, numCols),
                    inArray(numRows - inBorderWidth - 1, numCols - inBorderWidth - 1));
    }

    //============================================================================
    // Method Description:
    /// extends the corner values
    ///
    /// @param inArray
    /// @param inBorderWidth
    /// @param inFillValue
    ///
    template<typename dtype>
    void fillCorners(NdArray<dtype>& inArray, uint32 inBorderWidth, dtype inFillValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const Shape inShape = inArray.shape();
        const auto  numRows = static_cast<int32>(inShape.rows);
        const auto  numCols = static_cast<int32>(inShape.cols);

        // top left
        inArray.put(Slice(0, inBorderWidth), Slice(0, inBorderWidth), inFillValue);

        // top right
        inArray.put(Slice(0, inBorderWidth), Slice(numCols - inBorderWidth, numCols), inFillValue);

        // bottom left
        inArray.put(Slice(numRows - inBorderWidth, numRows), Slice(0, inBorderWidth), inFillValue);

        // bottom right
        inArray.put(Slice(numRows - inBorderWidth, numRows), Slice(numCols - inBorderWidth, numCols), inFillValue);
    }
} // namespace nc::filter::boundary
