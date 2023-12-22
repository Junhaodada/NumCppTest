
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
    /// Gives a new shape to an array without changing its data.
    ///
    /// The new shape should be compatible with the original shape. If an single integer,
    /// then the result will be a 1-D array of that length. One shape dimension
    /// can be -1. In this case, the value is inferred from the length of the
    /// array and remaining dimensions.
    ///
    /// @param inArray
    /// @param inSize
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& reshape(NdArray<dtype>& inArray, uint32 inSize)
    {
        inArray.reshape(inSize);
        return inArray;
    }

    //============================================================================
    // Method Description:
    /// Gives a new shape to an array without changing its data.
    ///
    /// The new shape should be compatible with the original shape. If an single integer,
    /// then the result will be a 1-D array of that length. One shape dimension
    /// can be -1. In this case, the value is inferred from the length of the
    /// array and remaining dimensions.
    ///
    /// @param inArray
    /// @param inNumRows
    /// @param inNumCols
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& reshape(NdArray<dtype>& inArray, int32 inNumRows, int32 inNumCols)
    {
        inArray.reshape(inNumRows, inNumCols);
        return inArray;
    }

    //============================================================================
    // Method Description:
    /// Gives a new shape to an array without changing its data.
    ///
    /// The new shape should be compatible with the original shape. If an single integer,
    /// then the result will be a 1-D array of that length. One shape dimension
    /// can be -1. In this case, the value is inferred from the length of the
    /// array and remaining dimensions.
    ///
    /// @param inArray
    /// @param inNewShape
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype>& reshape(NdArray<dtype>& inArray, const Shape& inNewShape)
    {
        inArray.reshape(inNewShape);
        return inArray;
    }
} // namespace nc
