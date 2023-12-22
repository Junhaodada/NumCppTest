
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/AERtoNED.hpp"
#include "NumCpp/Coordinates/Transforms/LLAtoECEF.hpp"
#include "NumCpp/Coordinates/Transforms/NEDtoECEF.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the spherical inertial coordinates (NED) to Cartesian XYZ (ENU).
     *        NOTE: positive elevation is defined as the positive z (up) direction
     *
     * @param target: the target position
     * @param referencePoint: the reference position
     * @return ECEF
     */
    [[nodiscard]] inline reference_frames::ECEF AERtoECEF(const reference_frames::AER   target,
                                                          const reference_frames::ECEF& referencePoint) noexcept
    {
        return NEDtoECEF(AERtoNED(target), referencePoint);
    }

    /**
     * @brief Converts the spherical inertial coordinates (NED) to Cartesian XYZ (ENU).
     *        NOTE: positive elevation is defined as the positive z (up) direction
     *
     * @param target: the target position
     * @param referencePoint: the reference position
     * @return ECEF
     */
    [[nodiscard]] inline reference_frames::ECEF AERtoECEF(const reference_frames::AER  target,
                                                          const reference_frames::LLA& referencePoint) noexcept
    {
        return AERtoECEF(target, LLAtoECEF(referencePoint));
    }
} // namespace nc::coordinates::transforms
