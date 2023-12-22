
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
    /// Test for inf and return result as a boolean.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.isinf.html
    ///
    /// @param inValue
    ///
    /// @return bool
    ///
    template<typename dtype>
    bool isinf(dtype inValue) noexcept
    {
        STATIC_ASSERT_FLOAT(dtype);

        return std::isinf(inValue);
    }

    //============================================================================
    // Method Description:
    /// Test element-wise for inf and return result as a boolean array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.isinf.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> isinf(const NdArray<dtype>& inArray)
    {
        NdArray<bool> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> bool { return isinf(inValue); });

        return returnArray;
    }
} // namespace nc
