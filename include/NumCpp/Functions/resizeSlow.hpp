
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
    /// Return a new array with the specified shape. If new shape
    /// is larger than old shape then array will be padded with zeros.
    /// If new shape is smaller than the old shape then the data will
    /// be discarded.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.resize.html
    ///
    /// @param inArray
    /// @param inNumRows
    /// @param inNumCols
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& resizeSlow(NdArray<dtype>& inArray, uint32 inNumRows, uint32 inNumCols)
    {
        inArray.resizeSlow(inNumRows, inNumCols);
        return inArray;
    }

    //============================================================================
    // Method Description:
    /// Return a new array with the specified shape. If new shape
    /// is larger than old shape then array will be padded with zeros.
    /// If new shape is smaller than the old shape then the data will
    /// be discarded.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.resize.html
    ///
    /// @param inArray
    /// @param inNewShape
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& resizeSlow(NdArray<dtype>& inArray, const Shape& inNewShape)
    {
        inArray.resizeSlow(inNewShape);
        return inArray;
    }
} // namespace nc
