
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/Euler.hpp"
#include "NumCpp/Coordinates/Orientation.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/Transforms/NEDUnitVecsInECEF.hpp"
#include "NumCpp/Functions/wrap.hpp"
#include "NumCpp/Rotations/Quaternion.hpp"
#include "NumCpp/Vector/Vec3.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts ECEF euler angles to body roll/pitch/yaw
     *
     * @param location: the ecef location
     * @param orientation: ecef euler angles
     * @return NED Orientation
     */
    [[nodiscard]] inline Orientation ECEFEulerToNEDRollPitchYaw(const reference_frames::ECEF& location,
                                                                const Euler&                  orientation) noexcept
    {
        const auto x0 = Vec3::right();
        const auto y0 = Vec3::up();
        const auto z0 = Vec3::forward();

        // first rotation array, z0 by psi
        const auto quatPsi = rotations::Quaternion{ z0, orientation.psi };

        // rotate
        const auto x1 = quatPsi * x0;
        const auto y1 = quatPsi * y0;

        // second rotation array, y1 by theta
        const auto quatTheta = rotations::Quaternion{ y1, orientation.theta };

        // rotate
        const auto x2 = quatTheta * x1;
        const auto y2 = quatTheta * y1;

        // third rotation array, x2 by phi
        const auto quatPhi = rotations::Quaternion{ x2, orientation.phi };

        // rotate
        const auto x3 = quatPhi * x2;
        const auto y3 = quatPhi * y2;

        // get the local NED unit vectors wrt the ECEF coordinate system
        const auto& [xHat0, yHat0, zHat0] = NEDUnitVecsInECEF(location);

        // calculate yaw and pitch
        const auto yaw   = std::atan2(x3.dot(yHat0), x3.dot(xHat0));
        const auto pitch = std::atan(-x3.dot(zHat0) / std::hypot(x3.dot(xHat0), x3.dot(yHat0)));

        // calculate roll
        const auto yHat2 = (rotations::Quaternion{ zHat0, yaw } * yHat0);
        const auto zHat2 = (rotations::Quaternion{ yHat2, pitch } * zHat0);
        const auto roll  = std::atan2(y3.dot(zHat2), y3.dot(yHat2));

        return { wrap(roll), pitch, wrap(yaw) };
    }
} // namespace nc::coordinates::transforms
