
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/Euler.hpp"
#include "NumCpp/Coordinates/Orientation.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/Transforms/NEDRollPitchYawToECEFEuler.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts ENU body roll/pitch/yaw to ECEF euler angles
     *
     * @param location: the ecef location
     * @param orientation: ned euler angles
     * @return Orientation
     */
    [[nodiscard]] inline Euler ENURollPitchYawToECEFEuler(const reference_frames::ECEF& location,
                                                          const Orientation&            orientation) noexcept
    {
        const auto nedOrientation = Orientation{ orientation.pitch, orientation.roll, -orientation.yaw };
        const auto nedEuler       = NEDRollPitchYawToECEFEuler(location, nedOrientation);
        return { nedEuler.theta, nedEuler.psi, -nedEuler.phi };
    }
} // namespace nc::coordinates::transforms
