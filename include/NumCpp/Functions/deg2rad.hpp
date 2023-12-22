
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Constants.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Convert angles from degrees to radians.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.deg2rad.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    constexpr auto deg2rad(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return inValue * constants::pi / 180.;
    }

    //============================================================================
    // Method Description:
    /// Convert angles from degrees to radians.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.deg2rad.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto deg2rad(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(deg2rad(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return deg2rad(inValue); });

        return returnArray;
    }
} // namespace nc
