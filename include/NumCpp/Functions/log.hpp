
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
    /// Natural logarithm.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log.html
    ///
    /// @param inValue
    ///
    /// @return value
    ///
    template<typename dtype>
    auto log(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::log(inValue);
    }

    //============================================================================
    // Method Description:
    /// Natural logarithm, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.log.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto log(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(log(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return log(inValue); });

        return returnArray;
    }
} // namespace nc
