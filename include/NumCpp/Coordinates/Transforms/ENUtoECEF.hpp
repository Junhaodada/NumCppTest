
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ENU.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/Transforms/ENUtoNED.hpp"
#include "NumCpp/Coordinates/Transforms/LLAtoECEF.hpp"
#include "NumCpp/Coordinates/Transforms/NEDtoECEF.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the ENU coordinates to ECEF
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *        https://en.wikipedia.org/wiki/Local_tangent_plane_coordinates
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns ENU
     */
    [[nodiscard]] inline reference_frames::ECEF ENUtoECEF(const reference_frames::ENU&  target,
                                                          const reference_frames::ECEF& referencePoint) noexcept
    {
        return NEDtoECEF(ENUtoNED(target), referencePoint);
    }

    /**
     * @brief Converts the ENU coordinates to ECEF
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *        https://en.wikipedia.org/wiki/Local_tangent_plane_coordinates
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns ENU
     */
    [[nodiscard]] inline reference_frames::ECEF ENUtoECEF(const reference_frames::ENU& target,
                                                          const reference_frames::LLA& referencePoint) noexcept
    {
        return ENUtoECEF(target, LLAtoECEF(referencePoint));
    }
} // namespace nc::coordinates::transforms
