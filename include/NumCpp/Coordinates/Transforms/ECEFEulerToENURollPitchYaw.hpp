
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/Euler.hpp"
#include "NumCpp/Coordinates/Orientation.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFEulerToNEDRollPitchYaw.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts ECEF euler angles to body roll/pitch/yaw
     *
     * @param location: the ecef location
     * @param orientation: ecef euler angles
     * @return ENU Orientation
     */
    [[nodiscard]] inline Orientation ECEFEulerToENURollPitchYaw(const reference_frames::ECEF& location,
                                                                const Euler&                  orientation) noexcept
    {
        const auto nedOrientation = ECEFEulerToNEDRollPitchYaw(location, orientation);
        return { nedOrientation.pitch, nedOrientation.roll, -nedOrientation.yaw };
    }
} // namespace nc::coordinates::transforms
