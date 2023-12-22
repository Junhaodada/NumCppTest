
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns x1 * 2^x2.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.ldexp.html
    ///
    /// @param inValue1
    /// @param inValue2
    ///
    /// @return value
    ///
    template<typename dtype>
    dtype ldexp(dtype inValue1, uint8 inValue2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return static_cast<dtype>(std::ldexp(static_cast<double>(inValue1), inValue2));
    }

    //============================================================================
    // Method Description:
    /// Returns x1 * 2^x2, element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.ldexp.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> ldexp(const NdArray<dtype>& inArray1, const NdArray<uint8>& inArray2)
    {
        if (inArray1.shape() != inArray2.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array shapes are not consistant.");
        }

        NdArray<dtype> returnArray(inArray1.shape());
        stl_algorithms::transform(inArray1.cbegin(),
                                  inArray1.cend(),
                                  inArray2.cbegin(),
                                  returnArray.begin(),
                                  [](dtype inValue1, uint8 inValue2) noexcept -> dtype
                                  { return ldexp(inValue1, inValue2); });

        return returnArray;
    }
} // namespace nc
