
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Constants.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Functions/full.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with nans.
    /// Only really works for dtype = float/double
    ///
    /// @param inSquareSize
    /// @return NdArray
    ///
    inline NdArray<double> nans(uint32 inSquareSize)
    {
        return full(inSquareSize, constants::nan);
    }

    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with nans.
    /// Only really works for dtype = float/double
    ///
    /// @param inNumRows
    /// @param inNumCols
    /// @return NdArray
    ///
    inline NdArray<double> nans(uint32 inNumRows, uint32 inNumCols)
    {
        return full(inNumRows, inNumCols, constants::nan);
    }

    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with nans.
    /// Only really works for dtype = float/double
    ///
    /// @param inShape
    /// @return NdArray
    ///
    inline NdArray<double> nans(const Shape& inShape)
    {
        return full(inShape, constants::nan);
    }
} // namespace nc
