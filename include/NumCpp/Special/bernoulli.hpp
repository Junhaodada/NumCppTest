
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include "boost/math/special_functions/bernoulli.hpp"

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Both return the nth Bernoulli number B2n.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n
    /// @return double
    ///
    inline double bernoilli(uint32 n)
    {
        if (n == 1)
        {
            return 0.5;
        }
        if (n % 2 != 0)
        {
            return 0.;
        }

        return boost::math::bernoulli_b2n<double>(n / 2);
    }

    //============================================================================
    // Method Description:
    /// Both return the nth Bernoulli number B2n.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param inArray
    /// @return NdArray<double>
    ///
    inline NdArray<double> bernoilli(const NdArray<uint32>& inArray)
    {
        NdArray<double> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](uint32 inValue) -> double { return bernoilli(inValue); });

        return returnArray;
    }
} // namespace nc::special

#endif // #ifndef NUMCPP_NO_USE_BOOST
