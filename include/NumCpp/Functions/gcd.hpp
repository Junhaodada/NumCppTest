
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <numeric>

#if defined(__cpp_lib_gcd_lcm) || !defined(NUMCPP_NO_USE_BOOST)

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

#ifndef NUMCPP_NO_USE_BOOST
#include "boost/integer/common_factor_rt.hpp"
#endif

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns the greatest common divisor of |x1| and |x2|.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.gcd.html
    ///
    /// @param inValue1
    /// @param inValue2
    /// @return dtype
    ///
    template<typename dtype>
    dtype gcd(dtype inValue1, dtype inValue2) noexcept
    {
        STATIC_ASSERT_INTEGER(dtype);

#ifdef __cpp_lib_gcd_lcm
        return std::gcd(inValue1, inValue2);
#else
        return boost::integer::gcd(inValue1, inValue2);
#endif // #ifdef __cpp_lib_gcd_lcm
    }

#ifndef NUMCPP_NO_USE_BOOST
    //============================================================================
    // Method Description:
    /// Returns the greatest common divisor of the values in the
    /// input array.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.gcd.html
    ///
    /// @param inArray
    /// @return NdArray<double>
    ///
    template<typename dtype>
    dtype gcd(const NdArray<dtype>& inArray)
    {
        STATIC_ASSERT_INTEGER(dtype);
        return boost::integer::gcd_range(inArray.cbegin(), inArray.cend()).first;
    }
#endif // #ifndef NUMCPP_NO_USE_BOOST
} // namespace nc

#endif // defined(__cpp_lib_gcd_lcm) || !defined(NUMCPP_NO_USE_BOOST)