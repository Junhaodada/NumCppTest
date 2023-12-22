
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
    /// Compute tangent.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.tan.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto tan(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::tan(inValue);
    }

    //============================================================================
    // Method Description:
    /// Compute tangent element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.tan.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto tan(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(tan(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return tan(inValue); });

        return returnArray;
    }
} // namespace nc
