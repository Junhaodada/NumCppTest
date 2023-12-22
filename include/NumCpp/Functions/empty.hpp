
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
    /// Return a new array of given shape and type, without initializing entries.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.empty.html
    ///
    /// @param inNumRows
    /// @param inNumCols
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> empty(uint32 inNumRows, uint32 inNumCols)
    {
        return NdArray<dtype>(inNumRows, inNumCols);
    }

    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, without initializing entries.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.empty.html
    ///
    /// @param inShape
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> empty(const Shape& inShape)
    {
        return NdArray<dtype>(inShape);
    }
} // namespace nc
