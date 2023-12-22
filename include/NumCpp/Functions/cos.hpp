
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
    /// Cosine
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.cos.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto cos(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::cos(inValue);
    }

    //============================================================================
    // Method Description:
    /// Cosine element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.cos.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto cos(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(cos(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return cos(inValue); });

        return returnArray;
    }
} // namespace nc
