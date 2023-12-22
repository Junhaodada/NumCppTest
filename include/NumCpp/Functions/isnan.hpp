
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Test for NaN and return result as a boolean.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.isnan.html
    ///
    /// @param inValue
    ///
    /// @return bool
    ///
    template<typename dtype>
    bool isnan(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (DtypeInfo<dtype>::isInteger())
        {
            return false;
        }

        return std::isnan(static_cast<double>(inValue)); // static_cast is needed for compiler error
    }

    //============================================================================
    // Method Description:
    /// Test element-wise for NaN and return result as a boolean array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.isnan.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> isnan(const NdArray<dtype>& inArray)
    {
        NdArray<bool> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> bool { return isnan(inValue); });

        return returnArray;
    }
} // namespace nc
