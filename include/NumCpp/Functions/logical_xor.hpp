
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the truth value of x1 XOR x2 element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.logical_xor.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> logical_xor(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return broadcast::broadcaster<bool>(inArray1,
                                            inArray2,
                                            [](dtype inValue1, dtype inValue2) -> bool {
                                                return !utils::essentiallyEqual(inValue1, dtype{ 0 }) !=
                                                       !utils::essentiallyEqual(inValue2, dtype{ 0 });
                                            });
    }
} // namespace nc
