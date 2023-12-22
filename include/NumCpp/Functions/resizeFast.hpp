
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
    /// Change shape and size of array in-place. All previous
    /// data of the array is lost.
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
    NdArray<dtype>& resizeFast(NdArray<dtype>& inArray, uint32 inNumRows, uint32 inNumCols)
    {
        inArray.resizeFast(inNumRows, inNumCols);
        return inArray;
    }

    //============================================================================
    // Method Description:
    /// Change shape and size of array in-place. All previous
    /// data of the array is lost.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.resize.html
    ///
    /// @param inArray
    /// @param inNewShape
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& resizeFast(NdArray<dtype>& inArray, const Shape& inNewShape)
    {
        inArray.resizeFast(inNewShape);
        return inArray;
    }
} // namespace nc
