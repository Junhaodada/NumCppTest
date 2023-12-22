
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ENU.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"
#include "NumCpp/Coordinates/Transforms/LLAtoECEF.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the ECEF coordinates to ENU
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *
     * @param target: the target of interest
     * @param referencePoint: the reference point
     * @returns ENU
     */
    [[nodiscard]] inline reference_frames::ENU ECEFtoENU(const reference_frames::ECEF& target,
                                                         const reference_frames::LLA&  referencePoint) noexcept
    {
        const auto sinLat = std::sin(referencePoint.latitude);
        const auto cosLat = std::cos(referencePoint.latitude);
        const auto sinLon = std::sin(referencePoint.longitude);
        const auto cosLon = std::cos(referencePoint.longitude);

        const auto referencePointECEF = LLAtoECEF(referencePoint);

        const auto x = target.x - referencePointECEF.x;
        const auto y = target.y - referencePointECEF.y;
        const auto z = target.z - referencePointECEF.z;

        return { -sinLon * x + cosLon * y,
                 -sinLat * cosLon * x - sinLat * sinLon * y + cosLat * z,
                 cosLat * cosLon * x + cosLat * sinLon * y + sinLat * z };
    }

    /**
     * @brief Converts the ECEF coordinates to ENU
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *
     * @param target: the target of interest
     * @param referencePoint: the reference point
     * @returns ENU
     */
    [[nodiscard]] inline reference_frames::ENU ECEFtoENU(const reference_frames::ECEF& target,
                                                         const reference_frames::ECEF& referencePoint) noexcept
    {
        return ECEFtoENU(target, ECEFtoLLA(referencePoint));
    }
} // namespace nc::coordinates::transforms
