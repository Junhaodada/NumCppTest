
/// Description
/// Special Functions
///
#pragma once

#include <cmath>

#if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

#ifndef __cpp_lib_math_special_functions
#include "boost/math/special_functions/ellint_1.hpp"
#endif

#include <type_traits>

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Computes the incomplete elliptic integral of the first kind of k and p.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inK: elliptic modulus or eccentricity
    /// @param inP: Jacobi amplitude (measured in radians)
    /// @return calculated-result-type
    ///
    template<typename dtype1, typename dtype2>
    auto ellint_1(dtype1 inK, dtype2 inP)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

#ifdef __cpp_lib_math_special_functions
        return std::ellint_1(inK, inP);
#else
        return boost::math::ellint_1(inK, inP);
#endif
    }

    //============================================================================
    // Method Description:
    /// Computes the incomplete elliptic integral of the first kind of k and p.
    /// NOTE: Use of this function requires either using the Boost
    /// includes or a C++17 compliant compiler.
    ///
    /// @param inArrayK: elliptic modulus or eccentricity
    /// @param inArrayP: Jacobi amplitude (measured in radians)
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    auto ellint_1(const NdArray<dtype1>& inArrayK, const NdArray<dtype2>& inArrayP)
    {
        if (inArrayK.size() != inArrayP.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("Shapes of inArrayK and inArrayP must match.");
        }

        NdArray<decltype(ellint_1(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inArrayK.shape());

        stl_algorithms::transform(inArrayK.cbegin(),
                                  inArrayK.cend(),
                                  inArrayP.cbegin(),
                                  returnArray.begin(),
                                  [](dtype1 inK, dtype2 inP) -> auto { return ellint_1(inK, inP); });

        return returnArray;
    }
} // namespace nc::special

#endif // #if defined(__cpp_lib_math_special_functions) || !defined(NUMCPP_NO_USE_BOOST)
