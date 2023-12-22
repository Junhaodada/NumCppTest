
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/ENU.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/NED.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts ENU to NED
     *
     * @param point: the ENU coordinates
     * @returns NED
     */
    [[nodiscard]] inline reference_frames::NED ENUtoNED(const reference_frames::ENU& point) noexcept
    {
        return { point.north(), point.east(), -point.up() };
    }
} // namespace nc::coordinates::transforms
