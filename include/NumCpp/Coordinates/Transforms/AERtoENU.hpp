
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/NED.hpp"
#include "NumCpp/Coordinates/Transforms/AERtoNED.hpp"
#include "NumCpp/Coordinates/Transforms/NEDtoENU.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the spherical inertial coordinates (NED) to Cartesian XYZ (ENU).
     *        NOTE: positive elevation is defined as the positive z (up) direction
     *
     * @param aer 2D Inertial azimuth and elevation
     * @return ENU
     */
    [[nodiscard]] inline reference_frames::ENU AERtoENU(const reference_frames::AER aer) noexcept
    {
        return NEDtoENU(AERtoNED(aer));
    }
} // namespace nc::coordinates::transforms
