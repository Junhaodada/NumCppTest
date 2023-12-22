
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/AER.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoENU.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"
#include "NumCpp/Functions/wrap2Pi.hpp"

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
    [[nodiscard]] inline reference_frames::AER ECEFtoAER(const reference_frames::ECEF& target,
                                                         const reference_frames::LLA&  referencePoint) noexcept
    {
        const auto targetENU = ECEFtoENU(target, referencePoint);
        const auto targetENUnormalizedCart =
            normalize(Cartesian{ targetENU.east(), targetENU.north(), targetENU.up() });
        const auto& east  = targetENUnormalizedCart.x;
        const auto& north = targetENUnormalizedCart.y;
        const auto& up    = targetENUnormalizedCart.z;

        const auto referencePointECEF = LLAtoECEF(referencePoint);
        const auto range              = norm(target - referencePointECEF);

        return { wrap2Pi(std::atan2(east, north)), std::asin(up), range };
    }

    /**
     * @brief Converts the LLA coordinates to Az El with geodedic up
     *        https://geospace-code.github.io/matmap3d/enu2aer.html
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint
     * @returns AER
     */
    [[nodiscard]] inline reference_frames::AER ECEFtoAER(const reference_frames::ECEF& target,
                                                         const reference_frames::ECEF& referencePoint) noexcept
    {
        return ECEFtoAER(target, ECEFtoLLA(referencePoint));
    }
} // namespace nc::coordinates::transforms
