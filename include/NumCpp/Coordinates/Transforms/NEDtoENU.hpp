
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/ENU.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/NED.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts NED to ENU
     *
     * @param point: the NED coordinates
     * @returns ENU
     */
    [[nodiscard]] inline reference_frames::ENU NEDtoENU(const reference_frames::NED& point) noexcept
    {
        return { point.east(), point.north(), -point.down() };
    }
} // namespace nc::coordinates::transforms
