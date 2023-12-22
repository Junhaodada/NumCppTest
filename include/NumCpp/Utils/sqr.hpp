
/// Description
/// Squares in input value
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"

namespace nc::utils
{
    //============================================================================
    /// Squares in input value
    ///
    /// @param inValue
    ///
    /// @return squared value
    ///
    template<typename dtype>
    constexpr dtype sqr(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return inValue * inValue;
    }
} // namespace nc::utils
