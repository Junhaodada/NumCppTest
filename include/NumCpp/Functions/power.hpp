
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/power.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Raises the elements of the array to the input integer power
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.power.html
    ///
    /// @param inValue
    /// @param inExponent
    /// @return value raised to the power
    ///
    template<typename dtype>
    constexpr dtype power(dtype inValue, uint8 inExponent) noexcept
    {
        return utils::power(inValue, inExponent);
    }

    //============================================================================
    // Method Description:
    /// Raises the elements of the array to the input integer power
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.power.html
    ///
    /// @param inArray
    /// @param inExponent
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> power(const NdArray<dtype>& inArray, uint8 inExponent)
    {
        NdArray<dtype> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [inExponent](dtype inValue) noexcept -> dtype
                                  { return nc::power(inValue, inExponent); });

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Raises the elements of the array to the input integer powers
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.power.html
    ///
    /// @param inArray
    /// @param inExponents
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> power(const NdArray<dtype>& inArray, const NdArray<uint8>& inExponents)
    {
        if (inArray.shape() != inExponents.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array shapes are not consistant.");
        }

        NdArray<dtype> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  inExponents.cbegin(),
                                  returnArray.begin(),
                                  [](dtype inValue, uint8 inExponent) -> dtype
                                  { return nc::power(inValue, inExponent); });

        return returnArray;
    }
} // namespace nc
