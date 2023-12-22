
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include "boost/math/special_functions/gamma.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Returns natural log of the true gamma of value z.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inValue
    /// @return calculated-result-type
    ///
    template<typename dtype>
    auto log_gamma(dtype inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return boost::math::lgamma(inValue);
    }

    //============================================================================
    // Method Description:
    /// Returns natural log of the true gamma of values in array.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto log_gamma(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(log_gamma(dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) -> auto { return log_gamma(inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
