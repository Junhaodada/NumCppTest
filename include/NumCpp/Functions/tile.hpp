
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Construct an array by repeating A the number of times given by reps.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.tile.html
    ///
    /// @param inArray
    /// @param inNumRows
    /// @param inNumCols
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> tile(const NdArray<dtype>& inArray, uint32 inNumRows, uint32 inNumCols)
    {
        return inArray.repeat(inNumRows, inNumCols);
    }

    //============================================================================
    // Method Description:
    /// Construct an array by repeating A the number of times given by reps.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.tile.html
    ///
    /// @param inArray
    /// @param inReps
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> tile(const NdArray<dtype>& inArray, const Shape& inReps)
    {
        return inArray.repeat(inReps);
    }
} // namespace nc
