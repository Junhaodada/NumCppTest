
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Change the sign of x1 to that of x2, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.copysign.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> copySign(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inArray1.shape() != inArray2.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input arrays are not consistant.");
        }

        NdArray<dtype> returnArray(inArray1.shape());
        stl_algorithms::transform(inArray1.cbegin(),
                                  inArray1.cend(),
                                  inArray2.cbegin(),
                                  returnArray.begin(),
                                  [](dtype inValue1, dtype inValue2) -> dtype
                                  { return inValue2 < dtype{ 0 } ? std::abs(inValue1) * -1 : std::abs(inValue1); });

        return returnArray;
    }
} // namespace nc
