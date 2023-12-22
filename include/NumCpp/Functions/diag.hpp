
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/diagflat.hpp"
#include "NumCpp/Functions/diagonal.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Extract a diagonal or construct a diagonal array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.diag.html
    ///
    /// @param inArray
    /// @param k Diagonal in question. The default is 0.
    /// Use k>0 for diagonals above the main diagonal, and k<0
    /// for diagonals below the main diagonal.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> diag(const NdArray<dtype>& inArray, int32 k = 0)
    {
        if (inArray.isflat())
        {
            return diagflat(inArray, k);
        }

        return diagonal(inArray, k, Axis::ROW);
    }
} // namespace nc
