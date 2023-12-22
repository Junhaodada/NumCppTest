
/// Description
/// Converts the number into a string
///
#pragma once

#include <complex>
#include <sstream>
#include <string>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"

namespace nc::utils
{
    //============================================================================
    /// Converts the value into a string
    ///
    /// @param inValue
    ///
    /// @return std::string
    ///
    template<typename dtype>
    std::string value2str(dtype inValue)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        std::stringstream ss;
        ss << inValue;
        return ss.str();
    }
} // namespace nc::utils
