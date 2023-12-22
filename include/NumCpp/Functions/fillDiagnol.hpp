
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
    /// Fill the main diagonal of the given array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fill_diagonal.html
    ///
    /// @param inArray
    /// @param inValue
    ///
    template<typename dtype>
    void fillDiagonal(NdArray<dtype>& inArray, dtype inValue) noexcept
    {
        const auto inShape = inArray.shape();
        for (uint32 row = 0; row < inShape.rows; ++row)
        {
            if (row < inShape.cols)
            {
                inArray(row, row) = inValue;
            }
        }
    }
} // namespace nc
