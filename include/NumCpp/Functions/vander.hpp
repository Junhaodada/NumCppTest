
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <utility>

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StdComplexOperators.hpp"
#include "NumCpp/Functions/fliplr.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/powerf.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Generate a Vandermonde matrix.
    /// The columns of the output matrix are powers of the input vector. The order of the powers is determined by the
    /// increasing boolean argument. Specifically, when increasing is False, the i-th output column is the input vector
    /// raised element-wise to the power of N - i - 1. Such a matrix with a geometric progression in each row is named
    /// for Alexandre- Theophile Vandermonde.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.vander.html
    ///
    /// @param x: 1-D input array, otherwise the array will be flattened
    /// @param n: Number of columns in the output. If N is not specified, a square array is returned (N = len(x)).
    /// @param increasing: Order of the powers of the columns. If True, the powers increase from left to right, if False
    /// (the default) they are reversed.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto vander(const NdArray<dtype>& x, uint32 n, Increasing increasing = Increasing::YES)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        NdArray<decltype(std::pow(std::declval<dtype>(), uint32{ 0 }))> result(x.size(), n);
        for (uint32 row = 0; row < x.size(); ++row)
        {
            for (uint32 col = 0; col < n; ++col)
            {
                result(row, col) = std::pow(x[row], col);
            }
        }

        if (increasing == Increasing::NO)
        {
            return fliplr(result);
        }

        return result;
    }

    //============================================================================
    // Method Description:
    /// Generate a Vandermonde matrix.
    /// The columns of the output matrix are powers of the input vector. The order of the powers is determined by the
    /// increasing boolean argument. Specifically, when increasing is False, the i-th output column is the input vector
    /// raised element-wise to the power of N - i - 1. Such a matrix with a geometric progression in each row is named
    /// for Alexandre- Theophile Vandermonde.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.vander.html
    ///
    /// @param x: 1-D input array, otherwise the array will be flattened
    /// @param increasing: Order of the powers of the columns. If True, the powers increase from left to right, if False
    /// (the default) they are reversed.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto vander(const NdArray<dtype>& x, Increasing increasing = Increasing::YES)
    {
        return vander(x, x.size(), increasing);
    }
} // namespace nc
