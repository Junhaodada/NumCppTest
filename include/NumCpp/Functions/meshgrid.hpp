
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <utility>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/arange.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return coordinate matrices from coordinate vectors.
    /// Make 2D coordinate arrays for vectorized evaluations of 2D scalar
    /// vector fields over 2D grids, given one - dimensional coordinate arrays x1, x2, ..., xn.
    /// If input arrays are not one dimensional they will be flattened.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.meshgrid.html
    ///
    /// @param inICoords
    /// @param inJCoords
    ///
    /// @return std::pair<NdArray<dtype>, NdArray<dtype> >, i and j matrices
    ///
    template<typename dtype>
    std::pair<NdArray<dtype>, NdArray<dtype>> meshgrid(const NdArray<dtype>& inICoords, const NdArray<dtype>& inJCoords)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const uint32 numRows      = inJCoords.size();
        const uint32 numCols      = inICoords.size();
        auto         returnArrayI = NdArray<dtype>(numRows, numCols);
        auto         returnArrayJ = NdArray<dtype>(numRows, numCols);

        // first the I array
        for (uint32 row = 0; row < numRows; ++row)
        {
            for (uint32 col = 0; col < numCols; ++col)
            {
                returnArrayI(row, col) = inICoords[col];
            }
        }

        // then the I array
        for (uint32 col = 0; col < numCols; ++col)
        {
            for (uint32 row = 0; row < numRows; ++row)
            {
                returnArrayJ(row, col) = inJCoords[row];
            }
        }

        return std::make_pair(returnArrayI, returnArrayJ);
    }

    //============================================================================
    // Method Description:
    /// Return coordinate matrices from coordinate vectors.
    /// Make 2D coordinate arrays for vectorized evaluations of 2D scalar
    /// vector fields over 2D grids, given one - dimensional coordinate arrays x1, x2, ..., xn.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.meshgrid.html
    ///
    /// @param inSlice1
    /// @param inSlice2
    ///
    /// @return std::pair<NdArray<dtype>, NdArray<dtype> >, i and j matrices
    ///
    template<typename dtype>
    std::pair<NdArray<dtype>, NdArray<dtype>> meshgrid(const Slice& inSlice1, const Slice& inSlice2)
    {
        return meshgrid(arange<dtype>(inSlice1), arange<dtype>(inSlice2));
    }

} // namespace nc
