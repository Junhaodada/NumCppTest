
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ENU.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"
#include "NumCpp/Coordinates/Transforms/LLAtoNED.hpp"
#include "NumCpp/Coordinates/Transforms/NEDtoENU.hpp"

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
    [[nodiscard]] inline reference_frames::ENU LLAtoENU(const reference_frames::LLA& target,
                                                        const reference_frames::LLA& referencePoint) noexcept
    {
        return NEDtoENU(LLAtoNED(target, referencePoint));
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
    [[nodiscard]] inline reference_frames::ENU LLAtoENU(const reference_frames::LLA&  target,
                                                        const reference_frames::ECEF& referencePoint) noexcept
    {
        return LLAtoENU(target, ECEFtoLLA(referencePoint));
    }
} // namespace nc::coordinates::transforms
