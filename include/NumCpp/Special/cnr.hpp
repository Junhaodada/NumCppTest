
/// Description
/// Special Functions
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Special/factorial.hpp"
#include "NumCpp/Special/pnr.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Returns the number of combinations of n choose r. C(n, r)
    ///
    /// @param n: the total number of items
    /// @param r: the number of items taken
    /// @return double
    ///
    inline double cnr(uint32 n, uint32 r)
    {
        return pnr(n, r) / factorial(r);
    }
} // namespace nc::special
