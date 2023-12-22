
/// Description
/// samples a 2D gaussian of mean zero and input STD sigma
///
#pragma once

#include <cmath>

#include "NumCpp/Utils/sqr.hpp"

namespace nc::utils
{
    //============================================================================
    // Method Description:
    /// samples a 2D gaussian of mean zero and input STD sigma
    ///
    /// @param inX
    /// @param inY
    /// @param inSigma
    ///
    /// @return dtype
    ///
    inline double gaussian(double inX, double inY, double inSigma) noexcept
    {
        double exponent = sqr(inX) + sqr(inY);
        exponent /= 2;
        exponent /= sqr(inSigma);
        return std::exp(-exponent);
    }
} // namespace nc::utils
