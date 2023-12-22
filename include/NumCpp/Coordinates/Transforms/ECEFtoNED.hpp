
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/NED.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoENU.hpp"
#include "NumCpp/Coordinates/Transforms/ENUtoNED.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the ECEF coordinates to NED
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns NED
     */
    [[nodiscard]] inline reference_frames::NED ECEFtoNED(const reference_frames::ECEF& target,
                                                         const reference_frames::LLA&  referencePoint) noexcept
    {
        return ENUtoNED(ECEFtoENU(target, referencePoint));
    }

    /**
     * @brief Converts the ECEF coordinates to NED
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns NED
     */
    [[nodiscard]] inline reference_frames::NED ECEFtoNED(const reference_frames::ECEF& target,
                                                         const reference_frames::ECEF& referencePoint) noexcept
    {
        return ENUtoNED(ECEFtoENU(target, referencePoint));
    }
} // namespace nc::coordinates::transforms
