
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
    /// Convert angles from radians to degrees.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.rad2deg.html
    ///
    /// @param inValue
    ///
    /// @return value
    ///
    template<typename dtype>
    constexpr auto rad2deg(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return inValue * 180. / constants::pi;
    }

    //============================================================================
    // Method Description:
    /// Convert angles from radians to degrees.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.rad2deg.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    auto rad2deg(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(rad2deg(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return rad2deg(inValue); });

        return returnArray;
    }
} // namespace nc
