
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <complex>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StdComplexOperators.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Logarithm of the sum of exponentiations of the inputs.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.logaddexp.html
    ///
    /// @param x1
    /// @param x2
    ///
    /// @return value
    ///
    template<typename dtype>
    auto logaddexp(dtype x1, dtype x2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::log(std::exp(x1) + std::exp(x2));
    }

    //============================================================================
    // Method Description:
    /// Logarithm of the sum of exponentiations of the inputs, element-wise.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.logaddexp.html
    ///
    /// @param x1
    /// @param x2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto logaddexp(const NdArray<dtype>& x1, const NdArray<dtype>& x2)
    {
        if (x1.size() != x2.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("Inputs 'x1', and 'x2' must be the same size");
        }

        NdArray<decltype(logaddexp(dtype{ 0 }, dtype{ 0 }))> returnArray(x1.shape());
        stl_algorithms::transform(x1.cbegin(),
                                  x1.cend(),
                                  x2.cbegin(),
                                  returnArray.begin(),
                                  [](dtype inX1, dtype inX2) noexcept -> auto { return logaddexp(inX1, inX2); });

        return returnArray;
    }
} // namespace nc
