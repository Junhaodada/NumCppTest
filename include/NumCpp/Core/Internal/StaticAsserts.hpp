
/// Description
/// Some helper routines for checking types
///
#pragma once

#include <type_traits>

#include "NumCpp/Core/Internal/TypeTraits.hpp"

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STATIC_ASSERT_VALID_DTYPE(dtype) \
    static_assert(nc::is_valid_dtype_v<dtype>, "Template type is not a valid dtype for NdArray")

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STATIC_ASSERT_ARITHMETIC(dtype) \
    static_assert(std::is_arithmetic_v<dtype>, "Can only be used with arithmetic types")

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STATIC_ASSERT_INTEGER(dtype) static_assert(std::is_integral_v<dtype>, "Can only be used with integer types")

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STATIC_ASSERT_UNSIGNED_INTEGER(dtype) \
    static_assert(std::is_integral_v<dtype> && std::is_unsigned_v<dtype>, "Can only be used with integer types")

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STATIC_ASSERT_FLOAT(dtype) static_assert(std::is_floating_point_v<dtype>, "Can only be used with float types")

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STATIC_ASSERT_COMPLEX(dtype) static_assert(nc::is_complex_v<dtype>, "Can only be used with std::complex types")

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype)                        \
    static_assert(std::is_arithmetic_v<dtype> || nc::is_complex_v<dtype>, \
                  "Can only be used with arithmetic types or std::complex types")
