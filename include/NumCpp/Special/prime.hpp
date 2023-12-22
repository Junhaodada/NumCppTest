
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <string>

#include "boost/math/special_functions/prime.hpp"

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// The function prime provides fast table lookup to the first 10000 prime numbers
    /// (starting from 2 as the zeroth prime: as 1 isn't terribly useful in practice).
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: the nth prime number to return
    /// @return uint32
    ///
    inline uint32 prime(uint32 n)
    {
        if (n > boost::math::max_prime)
        {
            THROW_INVALID_ARGUMENT_ERROR("input n must be less than or equal to " +
                                         std::to_string(boost::math::max_prime));
        }

        return boost::math::prime(n);
    }

    //============================================================================
    // Method Description:
    /// The function prime provides fast table lookup to the first 10000 prime numbers
    /// (starting from 2 as the zeroth prime: as 1 isn't terribly useful in practice).
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inArray
    /// @return NdArray<uint32>
    ///
    inline NdArray<uint32> prime(const NdArray<uint32>& inArray)
    {
        NdArray<uint32> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](uint32 inValue) -> uint32 { return prime(inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
