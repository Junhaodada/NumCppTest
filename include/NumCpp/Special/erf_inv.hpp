
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include "boost/math/special_functions/erf.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Returns the inverse error function of z, that is a value x such that:
    /// z = erf(x).
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inValue
    /// @return calculated-result-type
    ///
    template<typename dtype>
    auto erf_inv(dtype inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return boost::math::erf_inv(inValue);
    }

    //============================================================================
    // Method Description:
    /// Returns the inverse error function of z, that is a value x such that:
    /// z = erf(x).
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto erf_inv(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(erf_inv(dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) -> auto { return erf_inv(inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
