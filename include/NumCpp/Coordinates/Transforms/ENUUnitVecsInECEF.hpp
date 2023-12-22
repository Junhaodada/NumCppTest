
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/Transforms/NEDUnitVecsInECEF.hpp"
#include "NumCpp/Vector/Vec3.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief get the local ENU unit vectors wrt the ECEF coordinate system
     *        // https://gssc.esa.int/navipedia/index.php/Transformations_between_ECEF_and_ENU_coordinates
     *
     * @param location: the ECEF location
     * @return std::array<Vec3, 3>
     */
    [[nodiscard]] inline std::array<Vec3, 3> ENUUnitVecsInECEF(const reference_frames::ECEF& location) noexcept
    {
        const auto& [xHat, yHat, zHat] = NEDUnitVecsInECEF(location);
        return { yHat, xHat, -zHat };
    }
} // namespace nc::coordinates::transforms
