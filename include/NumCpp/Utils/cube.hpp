
/// Description
/// Cubes in input value
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"

namespace nc::utils
{
    //============================================================================
    /// Cubes in input value
    ///
    /// @param inValue
    ///
    /// @return cubed value
    ///
    template<typename dtype>
    constexpr dtype cube(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return inValue * inValue * inValue;
    }
} // namespace nc::utils
