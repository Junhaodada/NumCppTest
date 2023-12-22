
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Internal/TypeTraits.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the remainder of division.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmod.html
    ///
    ///
    /// @param inValue1
    /// @param inValue2
    /// @return value
    ///
    template<typename dtype, std::enable_if_t<std::is_integral_v<dtype>, int> = 0>
    dtype fmod(dtype inValue1, dtype inValue2) noexcept
    {
        return inValue1 % inValue2;
    }

    //============================================================================
    // Method Description:
    /// Return the remainder of division.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmod.html
    ///
    ///
    /// @param inValue1
    /// @param inValue2
    /// @return value
    ///
    template<typename dtype, std::enable_if_t<std::is_floating_point_v<dtype>, int> = 0>
    dtype fmod(dtype inValue1, dtype inValue2) noexcept
    {
        return std::fmod(inValue1, inValue2);
    }

    //============================================================================
    // Method Description:
    /// Return the element-wise remainder of division.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmod.html
    ///
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fmod(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 % inArray2;
    }
} // namespace nc
