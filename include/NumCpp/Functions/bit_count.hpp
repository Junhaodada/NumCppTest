
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Computes the number of 1-bits in an integer
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    constexpr int bit_count(dtype inValue) noexcept
    {
        STATIC_ASSERT_UNSIGNED_INTEGER(dtype);

        int count = 0;
        for (int bit = 0; bit < DtypeInfo<dtype>::bits(); ++bit)
        {
            count += static_cast<int>((inValue & (dtype{ 1 } << bit)) >> bit);
        }

        return count;
    }

    //============================================================================
    // Method Description:
    /// Computes the number of 1-bits in an integer
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<int> bit_count(const NdArray<dtype>& inArray)
    {
        NdArray<int> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> int { return bit_count(inValue); });

        return returnArray;
    }
} // namespace nc
