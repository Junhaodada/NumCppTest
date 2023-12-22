
/// Description
/// Converts the number into a string
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"

namespace nc::utils
{
    //============================================================================
    /// Converts the number into a string
    ///
    /// @param inNumber
    ///
    /// @return std::string
    ///
    template<typename dtype>
    std::string num2str(dtype inNumber)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::to_string(inNumber);
    }
} // namespace nc::utils
