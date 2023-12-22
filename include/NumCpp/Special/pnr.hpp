
/// Description
/// Special Functions
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Special/factorial.hpp"

#ifndef NUMCPP_NO_USE_BOOST
#include "boost/math/special_functions/factorials.hpp"
#endif

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Returns the number of permutaions of n choose r. P(n, r)
    ///
    /// @param n: the total number of items
    /// @param r: the number of items taken
    /// @return double
    ///
    inline double pnr(uint32 n, uint32 r)
    {
        if (r > n)
        {
            return 0.;
        }
        else if (r == n)
        {
            return factorial(n);
        }

        double combinations = 1.;

#ifndef NUMCPP_NO_USE_BOOST
        if (n <= boost::math::max_factorial<double>::value)
        {
            const double nFactorial      = factorial(n);
            const double nMinusRFactoral = factorial(n - r);

            combinations = nFactorial / nMinusRFactoral;
        }
        else
        {
#endif
            const uint32 lower = n - r + 1;
            combinations       = static_cast<double>(lower);
            for (uint32 i = lower + 1; i <= n; ++i)
            {
                combinations *= static_cast<double>(i);
            }
#ifndef NUMCPP_NO_USE_BOOST
        }
#endif

        return combinations;
    }
} // namespace nc::special
