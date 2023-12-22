
/// Description
/// Raises the input value to a floating point power
///
#pragma once

#include <cmath>
#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/TypeTraits.hpp"

namespace nc::utils
{
    //============================================================================
    /// Raises the input value to a floating point power
    ///
    /// @param inValue
    /// @param inPower
    ///
    /// @return inValue raised to inPower
    ///
    template<typename dtype1, typename dtype2>
    auto powerf(dtype1 inValue, const dtype2 inPower) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype1);

        return std::pow(inValue, inPower);
    }
} // namespace nc::utils
