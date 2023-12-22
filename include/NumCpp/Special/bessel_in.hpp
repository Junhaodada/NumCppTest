
/// Description
/// Special Functions
///
#pragma once

#include <cmath>

#if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

#ifndef __cpp_lib_math_special_functions
#include "boost/math/special_functions/bessel.hpp"
#endif

#include <type_traits>

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Modified Cylindrical Bessel function of the first kind.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inV: the order of the bessel function
    /// @param inX: the input value
    /// @return calculated-result-type
    ///
    template<typename dtype1, typename dtype2>
    auto bessel_in(dtype1 inV, dtype2 inX)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

#ifdef __cpp_lib_math_special_functions
        return std::cyl_bessel_i(static_cast<double>(inV), static_cast<double>(inX));
#else
        return boost::math::cyl_bessel_i(static_cast<double>(inV), static_cast<double>(inX));
#endif
    }

    //============================================================================
    // Method Description:
    /// Modified Cylindrical Bessel function of the first kind.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inV: the order of the bessel function
    /// @param inArrayX: the input values
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    auto bessel_in(dtype1 inV, const NdArray<dtype2>& inArrayX)
    {
        NdArray<decltype(bessel_in(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inArrayX.shape());

        stl_algorithms::transform(inArrayX.cbegin(),
                                  inArrayX.cend(),
                                  returnArray.begin(),
                                  [inV](dtype2 inX) -> auto { return bessel_in(inV, inX); });

        return returnArray;
    }
} // namespace nc::special

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
