
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
    /// Repeat elements of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.repeat.html
    ///
    /// @param inArray
    /// @param inNumRows
    /// @param inNumCols
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> repeat(const NdArray<dtype>& inArray, uint32 inNumRows, uint32 inNumCols)
    {
        return inArray.repeat(inNumRows, inNumCols);
    }

    //============================================================================
    // Method Description:
    /// Repeat elements of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.repeat.html
    ///
    /// @param inArray
    /// @param inRepeatShape
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> repeat(const NdArray<dtype>& inArray, const Shape& inRepeatShape)
    {
        return inArray.repeat(inRepeatShape);
    }
} // namespace nc
