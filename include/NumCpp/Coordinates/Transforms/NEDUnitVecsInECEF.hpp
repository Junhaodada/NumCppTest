
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"
#include "NumCpp/Vector/Vec3.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief get the local NED unit vectors wrt the ECEF coordinate system
     *        https://gssc.esa.int/navipedia/index.php/Transformations_between_ECEF_and_ENU_coordinates
     *
     * @param location: the ECEF location
     * @return std::array<Vec3, 3>
     */
    [[nodiscard]] inline std::array<Vec3, 3> NEDUnitVecsInECEF(const reference_frames::ECEF& location) noexcept
    {
        const auto lla = ECEFtoLLA(location);

        const auto sinLat = std::sin(lla.latitude);
        const auto cosLat = std::cos(lla.latitude);
        const auto sinLon = std::sin(lla.longitude);
        const auto cosLon = std::cos(lla.longitude);

        const auto xHat = Vec3{ -cosLon * sinLat, -sinLon * sinLat, cosLat };
        const auto yHat = Vec3{ -sinLon, cosLon, 0. };
        const auto zHat = Vec3{ -cosLon * cosLat, -sinLon * cosLat, -sinLat };

        return { xHat, yHat, zHat };
    }
} // namespace nc::coordinates::transforms
