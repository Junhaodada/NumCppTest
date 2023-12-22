
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Create a two-dimensional array with the flattened input as a diagonal.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.diagflat.html
    ///
    /// @param inArray
    /// @param k Diagonal to set; 0, the default, corresponds to the �main� diagonal,
    /// a positive (negative) k giving the number of the diagonal above (below) the main.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> diagflat(const NdArray<dtype>& inArray, int32 k = 0)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const auto     absK = static_cast<uint32>(std::abs(k));
        NdArray<dtype> returnArray(inArray.size() + absK);

        const uint32 rowOffset = k < 0 ? absK : 0;
        const uint32 colOffset = k > 0 ? absK : 0;

        returnArray.zeros();
        for (uint32 i = 0; i < inArray.size(); ++i)
        {
            returnArray(i + rowOffset, i + colOffset) = inArray[i];
        }

        return returnArray;
    }
} // namespace nc
