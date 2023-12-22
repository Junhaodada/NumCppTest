
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute hyperbolic tangent.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.tanh.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto tanh(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::tanh(inValue);
    }

    //============================================================================
    // Method Description:
    /// Compute hyperbolic tangent element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.tanh.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto tanh(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(tanh(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return tanh(inValue); });

        return returnArray;
    }
} // namespace nc
