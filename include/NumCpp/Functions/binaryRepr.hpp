
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <bitset>
#include <string>

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the binary representation of the input number as a string.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.binary_repr.html
    ///
    /// @param inValue
    /// @return std::string
    ///
    template<typename dtype>
    std::string binaryRepr(dtype inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::bitset<DtypeInfo<dtype>::bits()>(inValue).to_string();
    }
} // namespace nc
