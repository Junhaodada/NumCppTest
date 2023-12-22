
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
#include "NumCpp/Utils/powerf.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Raises the elements of the array to the input floating point power
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.power.html
    ///
    /// @param inValue
    /// @param inExponent
    /// @return value raised to the power
    ///
    template<typename dtype1, typename dtype2>
    auto powerf(dtype1 inValue, dtype2 inExponent) noexcept
    {
        return utils::powerf(inValue, inExponent);
    }

    //============================================================================
    // Method Description:
    /// Raises the elements of the array to the input floating point power
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.power.html
    ///
    /// @param inArray
    /// @param inExponent
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    auto powerf(const NdArray<dtype1>& inArray, dtype2 inExponent)
    {
        NdArray<decltype(powerf(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [inExponent](dtype1 inValue) noexcept -> auto
                                  { return nc::powerf(inValue, inExponent); });

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Raises the elements of the array to the input floating point powers
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.power.html
    ///
    /// @param inArray
    /// @param inExponents
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    auto powerf(const NdArray<dtype1>& inArray, const NdArray<dtype2>& inExponents)
    {
        if (inArray.shape() != inExponents.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array shapes are not consistant.");
        }

        NdArray<decltype(powerf(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  inExponents.cbegin(),
                                  returnArray.begin(),
                                  [](dtype1 inValue, dtype2 inExponent) noexcept -> auto
                                  { return nc::powerf(inValue, inExponent); });

        return returnArray;
    }
} // namespace nc
