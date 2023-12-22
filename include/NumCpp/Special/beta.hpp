
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
#include "boost/math/special_functions/beta.hpp"
#endif

#include <type_traits>

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// The beta function.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param a
    /// @param b
    /// @return calculated-result-type
    ///
    template<typename dtype1, typename dtype2>
    auto beta(dtype1 a, dtype2 b)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

#ifdef __cpp_lib_math_special_functions
        return std::beta(a, b);
#else
        return boost::math::beta(a, b);
#endif
    }

    //============================================================================
    // Method Description:
    /// The beta function.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inArrayA
    /// @param inArrayB
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    auto beta(const NdArray<dtype1>& inArrayA, const NdArray<dtype2>& inArrayB)
    {
        NdArray<decltype(beta(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inArrayB.shape());

        stl_algorithms::transform(inArrayA.cbegin(),
                                  inArrayA.cend(),
                                  inArrayB.cbegin(),
                                  returnArray.begin(),
                                  [](dtype1 a, dtype2 b) -> auto { return beta(a, b); });

        return returnArray;
    }
} // namespace nc::special

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
