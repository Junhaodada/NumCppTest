
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <complex>
#include <type_traits>

#include "boost/math/special_functions/hankel.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Spherical Hankel funcion of the second kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inV: the order of the bessel function
    /// @param inX: the input value
    /// @return double
    ///
    template<typename dtype1, typename dtype2>
    std::complex<double> spherical_hankel_2(dtype1 inV, dtype2 inX)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

        return boost::math::sph_hankel_2(inV, inX);
    }

    //============================================================================
    // Method Description:
    /// Spherical Hankel funcion of the second kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inV: the order of the bessel function
    /// @param inArray: the input value
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    auto spherical_hankel_2(dtype1 inV, const NdArray<dtype2>& inArray)
    {
        NdArray<decltype(spherical_hankel_2(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [inV](dtype2 inValue) -> auto { return spherical_hankel_2(inV, inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
