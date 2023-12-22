
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the identity array.
    ///
    /// The identity array is a square array with ones on the main diagonal.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.identity.html
    ///
    /// @param inSquareSize
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> identity(uint32 inSquareSize)
    {
        NdArray<dtype> returnArray(inSquareSize);
        returnArray.zeros();
        for (uint32 i = 0; i < inSquareSize; ++i)
        {
            returnArray(i, i) = dtype{ 1 };
        }

        return returnArray;
    }
} // namespace nc
