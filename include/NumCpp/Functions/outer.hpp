
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// The outer product of two vectors.  Inputs are flattened if not already 1-dimensional.
    ///
    /// NumPy Reference: https://numpy.org/devdocs/reference/generated/numpy.outer.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> outer(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const auto size = inArray1.size();

        if (size != inArray2.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("Input arrays must be the same length");
        }

        auto returnArray = NdArray<dtype>(size);
        for (uint32 row = 0; row < size; ++row)
        {
            const auto array1Value = inArray1[row];

            std::transform(inArray2.begin(),
                           inArray2.end(),
                           returnArray.begin(row),
                           [array1Value](dtype value) -> dtype { return array1Value * value; });
        }

        return returnArray;
    }
} // namespace nc
