
/// Description
/// samples a 1D gaussian of input mean and sigma
///
#pragma once

#include <cmath>

#include "NumCpp/Utils/sqr.hpp"

namespace nc::utils
{
    //============================================================================
    // Method Description:
    /// samples a 1D gaussian of input mean and sigma
    ///
    /// @param inX
    /// @param inMu
    /// @param inSigma
    ///
    /// @return dtype
    ///
    inline double gaussian1d(double inX, double inMu, double inSigma) noexcept
    {
        double exponent = sqr(inX - inMu);
        exponent /= 2;
        exponent /= sqr(inSigma);
        return std::exp(-exponent);
    }
} // namespace nc::utils
