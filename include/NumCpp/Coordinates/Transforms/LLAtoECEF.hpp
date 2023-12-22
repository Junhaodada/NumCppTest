
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/Constants.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the LLA coordinates to ECEF
     *        https://en.wikipedia.org/wiki/Geographic_coordinate_conversion#From_geodetic_to_ECEF_coordinates
     *
     * @param point: the point of interest
     * @returns Cartesian
     */
    [[nodiscard]] inline reference_frames::ECEF LLAtoECEF(const reference_frames::LLA& point) noexcept
    {
        constexpr auto B2_DIV_A2 = utils::sqr(reference_frames::constants::EARTH_POLAR_RADIUS /
                                              reference_frames::constants::EARTH_EQUATORIAL_RADIUS);
        constexpr auto E_SQR     = 1. - B2_DIV_A2;

        const auto sinLat = std::sin(point.latitude);
        const auto cosLat = std::cos(point.latitude);
        const auto sinLon = std::sin(point.longitude);
        const auto cosLon = std::cos(point.longitude);

        const auto primeVerticalMeridian =
            reference_frames::constants::EARTH_EQUATORIAL_RADIUS / std::sqrt(1. - E_SQR * utils::sqr(sinLat));

        return reference_frames::ECEF{ (primeVerticalMeridian + point.altitude) * cosLat * cosLon,
                                       (primeVerticalMeridian + point.altitude) * cosLat * sinLon,
                                       (B2_DIV_A2 * primeVerticalMeridian + point.altitude) * sinLat };
    }
} // namespace nc::coordinates::transforms
