
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ENU.hpp"
#include "NumCpp/Coordinates/Transforms/ENUtoNED.hpp"
#include "NumCpp/Coordinates/Transforms/NEDtoAER.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the ENU coordinates to 2d speherical inertial coordinates.
     *        Range is not used.
     *        NOTE: positive elevation is defined as the positive z (up) direction
     *
     * @param target: coordinates to convert
     * @returns AER
     */
    [[nodiscard]] inline reference_frames::AER ENUtoAER(const reference_frames::ENU& target) noexcept
    {
        return NEDtoAER(ENUtoNED(target));
    }
} // namespace nc::coordinates::transforms
