
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
    /// Inner product of two 1-D arrays.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.inner.html
    ///
    /// @param a: array 1
    /// @param b: array 2
    /// @return NdArray
    ///
    template<typename dtype>
    dtype inner(const NdArray<dtype>& a, const NdArray<dtype>& b)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        if (a.size() != b.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("Inputs 'a' and 'b' must have the same size");
        }

        return std::inner_product(a.cbegin(), a.cend(), b.cbegin(), dtype{ 0 });
    }
} // namespace nc
