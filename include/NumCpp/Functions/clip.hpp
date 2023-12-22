
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StdComplexOperators.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Clip (limit) the value.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.clip.html
    ///
    /// @param inValue
    /// @param inMinValue
    /// @param inMaxValue
    /// @return NdArray
    ///
    template<typename dtype>
    dtype clip(dtype inValue, dtype inMinValue, dtype inMaxValue)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

#ifdef __cpp_lib_clamp
        const auto comparitor = [](dtype lhs, dtype rhs) noexcept -> bool { return lhs < rhs; };

        return std::clamp(inValue, inMinValue, inMaxValue, comparitor);
#else
        if (inValue < inMinValue)
        {
            return inMinValue;
        }
        else if (inValue > inMaxValue)
        {
            return inMaxValue;
        }

        return inValue;
#endif
    }

    //============================================================================
    // Method Description:
    /// Clip (limit) the values in an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.clip.html
    ///
    /// @param inArray
    /// @param inMinValue
    /// @param inMaxValue
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> clip(const NdArray<dtype>& inArray, dtype inMinValue, dtype inMaxValue)
    {
        return inArray.clip(inMinValue, inMaxValue);
    }
} // namespace nc
