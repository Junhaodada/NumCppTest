
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
    /// Hankel funcion of the first kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inV: the order of the bessel function
    /// @param inX: the input value
    /// @return std::complex<double>
    ///
    template<typename dtype1, typename dtype2>
    auto cyclic_hankel_1(dtype1 inV, dtype2 inX)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

        return boost::math::cyl_hankel_1(inV, inX);
    }

    //============================================================================
    // Method Description:
    /// Hankel funcion of the first kind.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inV: the order of the bessel function
    /// @param inX: the input array
    /// @return NdArray<std::complex>
    ///
    template<typename dtype1, typename dtype2>
    auto cyclic_hankel_1(dtype1 inV, const NdArray<dtype2>& inX)
    {
        NdArray<decltype(cyclic_hankel_1(dtype1{ 0 }, dtype2{ 0 }))> returnArray(inX.shape());

        stl_algorithms::transform(inX.cbegin(),
                                  inX.cend(),
                                  returnArray.begin(),
                                  [inV](dtype2 x) -> auto { return cyclic_hankel_1(inV, x); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
