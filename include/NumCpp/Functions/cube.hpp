
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/cube.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Cubes the input
    ///
    /// @param inValue
    /// @return cubed value
    ///
    template<typename dtype>
    constexpr dtype cube(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return utils::cube(inValue);
    }

    //============================================================================
    // Method Description:
    /// Cubes the elements of the array
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> cube(const NdArray<dtype>& inArray)
    {
        NdArray<dtype> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> dtype { return cube(inValue); });

        return returnArray;
    }
} // namespace nc
