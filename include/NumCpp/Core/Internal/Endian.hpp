
/// Description
/// Functions for determining and swaping endianess
///
#pragma once

#include <array>
#include <climits>

#include "NumCpp/Core/Types.hpp"

namespace nc::endian
{
    //============================================================================
    // Function Description:
    /// Determines the endianess of the system
    ///
    /// @return bool true if the system is little endian
    ///
    inline bool isLittleEndian() noexcept
    {
        union
        {
            uint32              i{};
            std::array<char, 4> c;
        } fourBytes = { 0x01020304 }; // NOLINT(cppcoreguidelines-avoid-magic-numbers)

        // NOLINTNEXTLINE(cppcoreguidelines-pro-type-union-access)
        return fourBytes.c[0] == 4;
    }

    //============================================================================
    // Function Description:
    /// Swaps the bytes of the input value
    ///
    /// @param value
    /// @return byte swapped value
    ///
    template<typename dtype>
    dtype byteSwap(dtype value) noexcept
    {
        STATIC_ASSERT_INTEGER(dtype);
        static_assert(CHAR_BIT == 8, "CHAR_BIT != 8"); // NOLINT(cppcoreguidelines-avoid-magic-numbers)

        union
        {
            dtype                            value;
            std::array<uint8, sizeof(dtype)> value8;
        } source, dest;

        source.value = value;

        for (std::size_t k = 0; k < sizeof(dtype); ++k)
        {
            dest.value8[k] = source.value8[sizeof(dtype) - k - 1];
        }

        return dest.value;
    }
} // namespace nc::endian