
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the truth value of x1 AND x2 element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.logical_and.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> logical_and(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 && inArray2;
    }
} // namespace nc
