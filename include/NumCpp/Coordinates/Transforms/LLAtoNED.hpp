
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ENU.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoNED.hpp"
#include "NumCpp/Coordinates/Transforms/LLAtoECEF.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the LLA coordinates to NED
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns NED
     */
    [[nodiscard]] inline reference_frames::NED LLAtoNED(const reference_frames::LLA& target,
                                                        const reference_frames::LLA& referencePoint) noexcept
    {
        return ECEFtoNED(LLAtoECEF(target), referencePoint);
    }

    /**
     * @brief Converts the LLA coordinates to NED
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns NED
     */
    [[nodiscard]] inline reference_frames::NED LLAtoNED(const reference_frames::LLA&  target,
                                                        const reference_frames::ECEF& referencePoint) noexcept
    {
        return LLAtoNED(target, ECEFtoLLA(referencePoint));
    }
} // namespace nc::coordinates::transforms
