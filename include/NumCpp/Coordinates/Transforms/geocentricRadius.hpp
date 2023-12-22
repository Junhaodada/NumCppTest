
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/Constants.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Returns the geocentric radius
     *
     * @param point: the point of interest
     * @returns radius
     */
    [[nodiscard]] inline double geocentricRadius(const reference_frames::LLA& point) noexcept
    {
        const auto cosLat = std::cos(point.latitude);
        const auto sinLat = std::sin(point.latitude);
        return std::sqrt((utils::sqr(utils::sqr(reference_frames::constants::EARTH_EQUATORIAL_RADIUS) * cosLat) +
                          utils::sqr(utils::sqr(reference_frames::constants::EARTH_POLAR_RADIUS) * sinLat)) /
                         (utils::sqr(reference_frames::constants::EARTH_EQUATORIAL_RADIUS * cosLat) +
                          utils::sqr(reference_frames::constants::EARTH_POLAR_RADIUS * sinLat)));
    }
} // namespace nc::coordinates::transforms
