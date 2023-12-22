
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/flip.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Flip array in the up/down direction.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.flipud.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> flipud(const NdArray<dtype>& inArray)
    {
        return flip(inArray, Axis::ROW);
    }
} // namespace nc
