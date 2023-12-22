
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/isinf.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Test for negative inf and return result as a boolean.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.isneginf.html
    ///
    /// @param inValue
    ///
    /// @return bool
    ///
    template<typename dtype>
    bool isneginf(dtype inValue) noexcept
    {
        STATIC_ASSERT_FLOAT(dtype);

        return inValue < 0 && std::isinf(inValue);
    }

    //============================================================================
    // Method Description:
    /// Test element-wise for negative inf and return result as a boolean array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.isneginf.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> isneginf(const NdArray<dtype>& inArray)
    {
        NdArray<bool> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> bool { return isneginf(inValue); });

        return returnArray;
    }
} // namespace nc
