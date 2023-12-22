
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/Constants.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/Geocentric.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/geocentricRadius.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts from geocentric to geodetic
     *
     * @param point: the point of interest
     * @returns geodetic
     */
    [[nodiscard]] inline reference_frames::LLA geocentricToLLA(const reference_frames::Geocentric& point) noexcept
    {
        constexpr auto flatteningFactor =
            (reference_frames::constants::EARTH_EQUATORIAL_RADIUS - reference_frames::constants::EARTH_POLAR_RADIUS) /
            reference_frames::constants::EARTH_EQUATORIAL_RADIUS;

        const auto geodeticLatitude = std::atan((1. / utils::sqr(1. - flatteningFactor)) * std::tan(point.latitude));
        auto       geodetic         = reference_frames::LLA{ geodeticLatitude, point.longitude, 0. };
        geodetic.altitude           = point.radius - geocentricRadius(geodetic);
        return geodetic;
    }
} // namespace nc::coordinates::transforms
