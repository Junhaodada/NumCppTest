
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/AERtoECEF.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"
#include "NumCpp/Coordinates/Transforms/LLAtoECEF.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the spherical inertial coordinates (NED) to Cartesian XYZ (ENU).
     *        NOTE: positive elevation is defined as the positive z (up) direction
     *
     * @param target: the target position
     * @param referencePoint: the reference position
     * @return LLA
     */
    [[nodiscard]] inline reference_frames::LLA AERtoLLA(const reference_frames::AER   target,
                                                        const reference_frames::ECEF& referencePoint) noexcept
    {
        return ECEFtoLLA(AERtoECEF(target, referencePoint));
    }

    /**
     * @brief Converts the spherical inertial coordinates (NED) to Cartesian XYZ (ENU).
     *        NOTE: positive elevation is defined as the positive z (up) direction
     *
     * @param target: the target position
     * @param referencePoint: the reference position
     * @return LLA
     */
    [[nodiscard]] inline reference_frames::LLA AERtoLLA(const reference_frames::AER  target,
                                                        const reference_frames::LLA& referencePoint) noexcept
    {
        return ECEFtoLLA(AERtoECEF(target, referencePoint));
    }
} // namespace nc::coordinates::transforms
