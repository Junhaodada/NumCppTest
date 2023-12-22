
/// Description
/// Raises the input value to an integer power
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"

namespace nc::utils
{
    //============================================================================
    /// Raises the input value to an integer power
    ///
    /// @param inValue
    /// @param inPower
    ///
    /// @return inValue raised to inPower
    ///
    template<typename dtype>
    dtype power(dtype inValue, uint8 inPower) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        if (inPower == 0)
        {
            return static_cast<dtype>(1);
        }

        dtype returnVal = inValue;
        for (uint8 exponent = 1; exponent < inPower; ++exponent)
        {
            returnVal *= inValue;
        }
        return returnVal;
    }
} // namespace nc::utils
