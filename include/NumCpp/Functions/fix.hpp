
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Round to nearest integer towards zero.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fix.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    dtype fix(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return inValue > 0 ? std::floor(inValue) : std::ceil(inValue);
    }

    //============================================================================
    // Method Description:
    /// Round to nearest integer towards zero.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fix.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fix(const NdArray<dtype>& inArray)
    {
        NdArray<double> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> double { return fix(inValue); });

        return returnArray;
    }
} // namespace nc
