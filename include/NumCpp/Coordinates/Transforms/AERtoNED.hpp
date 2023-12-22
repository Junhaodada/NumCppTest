
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/NED.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the spherical inertial coordinates (NED) to Cartesian XYZ (NED).
     *        NOTE: positive elevation is defined as the negative z (up) direction
     *
     * @param aer: 2D Inertial azimuth and elevation
     * @return NED
     */
    [[nodiscard]] inline reference_frames::NED AERtoNED(const reference_frames::AER aer) noexcept
    {
        const auto north = aer.range * std::cos(aer.el) * std::cos(aer.az);
        const auto east  = aer.range * std::cos(aer.el) * std::sin(aer.az);
        const auto down  = aer.range * std::sin(-aer.el);
        return { north, east, down };
    }
} // namespace nc::coordinates::transforms
