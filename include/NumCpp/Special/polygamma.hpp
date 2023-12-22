
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include "boost/math/special_functions/polygamma.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Returns the polygamma function of inValue. Polygamma is defined as the
    /// n'th derivative of the digamma function.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: the nth derivative
    /// @param inValue
    /// @return calculated-result-type
    ///
    template<typename dtype>
    auto polygamma(uint32 n, dtype inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return boost::math::polygamma(n, inValue);
    }

    //============================================================================
    // Method Description:
    /// Returns the polygamma function of the values in inArray. Polygamma is defined as the
    /// n'th derivative of the digamma function.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: the nth derivative
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto polygamma(uint32 n, const NdArray<dtype>& inArray)
    {
        NdArray<decltype(polygamma(n, dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [n](dtype inValue) -> auto { return polygamma(n, inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
