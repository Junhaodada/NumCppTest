
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
    /// Logarithm of an arbitrary base
    ///
    /// @param inValue
    /// @param inBase: the logorithm base
    ///
    /// @return value
    ///
    template<typename dtype>
    auto logb(dtype inValue, dtype inBase) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::log(inValue) / std::log(inBase);
    }

    //============================================================================
    // Method Description:
    /// Logarithm of an arbitrary base
    ///
    /// @param inArray
    /// @param inBase: the logorithm base
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto logb(const NdArray<dtype>& inArray, dtype inBase)
    {
        NdArray<decltype(logb(dtype{ 0 }, dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [inBase](dtype inValue) noexcept -> auto { return logb(inValue, inBase); });

        return returnArray;
    }
} // namespace nc
