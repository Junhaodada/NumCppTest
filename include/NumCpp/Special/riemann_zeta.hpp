
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
#include "boost/math/special_functions/zeta.hpp"
#endif

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// The Riemann Zeta function
    /// https://en.wikipedia.org/wiki/Riemann_zeta_function
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inValue
    /// @return calculated-result-type
    ///
    template<typename dtype>
    auto riemann_zeta(dtype inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_math_special_functions
        return std::riemann_zeta(inValue);
#else
        return boost::math::zeta(inValue);
#endif
    }

    //============================================================================
    // Method Description:
    /// The Riemann Zeta function
    /// https://en.wikipedia.org/wiki/Riemann_zeta_function
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto riemann_zeta(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(riemann_zeta(dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) -> auto { return riemann_zeta(inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
