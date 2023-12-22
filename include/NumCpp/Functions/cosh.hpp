
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
    /// Hyperbolic Cosine.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.cosh.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto cosh(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::cosh(inValue);
    }

    //============================================================================
    // Method Description:
    /// Hyperbolic Cosine element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.cosh.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto cosh(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(cosh(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return cosh(inValue); });

        return returnArray;
    }
} // namespace nc
