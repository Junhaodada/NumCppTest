
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <type_traits>

#include "boost/math/special_functions/bessel_prime.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Derivcative of the Modified Cylindrical Bessel function of the second kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inV: the order of the bessel function
    /// @param inX: the input value
    /// @return calculated-result-type
    ///
    template<typename dtype1, typename dtype2>
    auto bessel_kn_prime(dtype1 inV, dtype2 inX)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

        return boost::math::cyl_bessel_k_prime(inV, inX);
    }

    //============================================================================
    // Method Description:
    /// Derivcative of the Modified Cylindrical Bessel function of the second kind
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inV: the order of the bessel function
    /// @param inArrayX: the input values
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    auto bessel_kn_prime(dtype1 inV, const NdArray<dtype2>& inArrayX)
    {
        NdArray<decltype(bessel_kn_prime(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inArrayX.shape());

        stl_algorithms::transform(inArrayX.cbegin(),
                                  inArrayX.cend(),
                                  returnArray.begin(),
                                  [inV](dtype2 inX) -> auto { return bessel_kn_prime(inV, inX); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
