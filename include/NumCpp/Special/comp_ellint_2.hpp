
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
#include "boost/math/special_functions/ellint_2.hpp"
#endif

#include <type_traits>

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Computes the complete elliptic integral of the second kind of k.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inK: elliptic modulus or eccentricity
    /// @return calculated-result-type
    ///
    template<typename dtype>
    auto comp_ellint_2(dtype inK)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_math_special_functions
        return std::comp_ellint_2(inK);
#else
        return boost::math::ellint_2(inK);
#endif
    }

    //============================================================================
    // Method Description:
    /// Computes the complete elliptic integral of the second kind of k.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inArrayK: elliptic modulus or eccentricity
    /// @return NdArray
    ///
    template<typename dtype>
    auto comp_ellint_2(const NdArray<dtype>& inArrayK)
    {
        NdArray<decltype(comp_ellint_2(dtype{ 0 }))> returnArray(inArrayK.shape());

        stl_algorithms::transform(inArrayK.cbegin(),
                                  inArrayK.cend(),
                                  returnArray.begin(),
                                  [](dtype inK) -> auto { return comp_ellint_2(inK); });

        return returnArray;
    }
} // namespace nc::special

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
