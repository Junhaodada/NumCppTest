
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/NED.hpp"
#include "NumCpp/Functions/wrap2Pi.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the Cartesian XYZ (NED) coordinates to 2d speherical inertial coordinates.
     *        Range is not used.
     *        NOTE: positive elevation is defined as the negative z (up) direction
     *
     * @param target: coordinates to convert
     * @returns AER
     */
    [[nodiscard]] inline reference_frames::AER NEDtoAER(const reference_frames::NED& target) noexcept
    {
        const auto hypotXy = std::hypot(target.x, target.y);
        const auto el      = -std::atan2(target.z, hypotXy);
        const auto az      = wrap2Pi(std::atan2(target.y, target.x));
        const auto r       = std::hypot(target.x, target.y);
        const auto range   = std::hypot(r, target.z);
        return { az, el, range };
    }
} // namespace nc::coordinates::transforms
