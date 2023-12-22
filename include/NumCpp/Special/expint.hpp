
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
#include "boost/math/special_functions/expint.hpp"
#endif

#include <type_traits>

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Exponential integral Ei.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inX: value
    /// @return calculated-result-type
    ///
    template<typename dtype>
    auto expint(dtype inX)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_math_special_functions
        return std::expint(inX);
#else
        return boost::math::expint(inX);
#endif
    }

    //============================================================================
    // Method Description:
    /// Exponential integral Ei.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inArrayX: value
    /// @return NdArray
    ///
    template<typename dtype>
    auto expint(const NdArray<dtype>& inArrayX)
    {
        NdArray<decltype(expint(dtype{ 0 }))> returnArray(inArrayX.shape());

        stl_algorithms::transform(inArrayX.cbegin(),
                                  inArrayX.cend(),
                                  returnArray.begin(),
                                  [](dtype inX) -> auto { return expint(inX); });

        return returnArray;
    }
} // namespace nc::special

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
