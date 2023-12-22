
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Functions/array_equiv.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// True if two arrays have the same shape and elements, False otherwise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.array_equal.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return bool
    ///
    template<typename dtype>
    bool array_equal(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2) noexcept
    {
        if (inArray1.shape() != inArray2.shape())
        {
            return false;
        }

        return array_equiv(inArray1, inArray2);
    }
} // namespace nc
