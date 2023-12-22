
/// Description
/// Returns the linear interpolation between two points
///
#pragma once

namespace nc::utils
{
    //============================================================================
    /// Returns the linear interpolation between two points
    ///
    /// @param inValue1
    /// @param inValue2
    /// @param inPercent
    ///
    /// @return linear interpolated point
    ///
    constexpr double interp(double inValue1, double inValue2, double inPercent) noexcept
    {
        return inValue1 * (1. - inPercent) + inValue2 * inPercent;
    }
} // namespace nc::utils
