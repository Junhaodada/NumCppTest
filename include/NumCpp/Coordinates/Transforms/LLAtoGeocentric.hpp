
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
     * @brief Converts from geodetic to geocentric
     *
     * @param point: the point of interest
     * @returns geocentric
     */
    [[nodiscard]] inline reference_frames::Geocentric LLAtoGeocentric(const reference_frames::LLA& point) noexcept
    {
        constexpr auto flatteningFactor =
            (reference_frames::constants::EARTH_EQUATORIAL_RADIUS - reference_frames::constants::EARTH_POLAR_RADIUS) /
            reference_frames::constants::EARTH_EQUATORIAL_RADIUS;
        const auto geocentricLatitude = atan(utils::sqr(1. - flatteningFactor) * std::tan(point.latitude));
        return reference_frames::Geocentric{ geocentricLatitude, point.longitude, geocentricRadius(point) };
    }
} // namespace nc::coordinates::transforms
