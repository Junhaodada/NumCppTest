
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with inFillValue
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.full.html
    ///
    /// @param inSquareSize
    /// @param inFillValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> full(uint32 inSquareSize, dtype inFillValue)
    {
        NdArray<dtype> returnArray(inSquareSize, inSquareSize);
        returnArray.fill(inFillValue);
        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with inFillValue
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.full.html
    ///
    /// @param inNumRows
    /// @param inNumCols
    /// @param inFillValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> full(uint32 inNumRows, uint32 inNumCols, dtype inFillValue)
    {
        NdArray<dtype> returnArray(inNumRows, inNumCols);
        returnArray.fill(inFillValue);
        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with inFillValue
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.full.html
    ///
    /// @param inShape
    /// @param inFillValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> full(const Shape& inShape, dtype inFillValue)
    {
        return full(inShape.rows, inShape.cols, inFillValue);
    }
} // namespace nc
