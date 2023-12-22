
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoAER.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the LLA coordinates to Az El with geodedic up
     *        https://geospace-code.github.io/matmap3d/enu2aer.html
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint
     * @returns AER
     */
    [[nodiscard]] inline reference_frames::AER LLAtoAER(const reference_frames::LLA& target,
                                                        const reference_frames::LLA& referencePoint) noexcept
    {
        return ECEFtoAER(LLAtoECEF(target), referencePoint);
    }

    /**
     * @brief Converts the LLA coordinates to Az El with geodedic up
     *        https://geospace-code.github.io/matmap3d/enu2aer.html
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint
     * @returns AER
     */
    [[nodiscard]] inline reference_frames::AER LLAtoAER(const reference_frames::LLA&  target,
                                                        const reference_frames::ECEF& referencePoint) noexcept
    {
        return LLAtoAER(target, ECEFtoLLA(referencePoint));
    }
} // namespace nc::coordinates::transforms
