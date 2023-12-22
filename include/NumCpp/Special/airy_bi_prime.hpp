
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include "boost/math/special_functions/airy.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// The derivative of the second linearly independent solution to the differential equation y'' - yz = 0.
    /// http://mathworld.wolfram.com/AiryFunctions.html
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inValue
    /// @return calculated-result-type
    ///
    template<typename dtype>
    auto airy_bi_prime(dtype inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return boost::math::airy_bi_prime(inValue);
    }

    //============================================================================
    // Method Description:
    /// The derivative of the second linearly independent solution to the differential equation y'' - yz = 0.
    /// http://mathworld.wolfram.com/AiryFunctions.html
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto airy_bi_prime(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(airy_bi_prime(dtype{ 0 }))> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) -> auto { return airy_bi_prime(inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
