
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/NED.hpp"
#include "NumCpp/Coordinates/Transforms/ECEFtoLLA.hpp"
#include "NumCpp/Coordinates/Transforms/NEDtoECEF.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts the NED coordinates to LLA
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *        https://en.wikipedia.org/wiki/Local_tangent_plane_coordinates
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns NED
     */
    [[nodiscard]] inline reference_frames::LLA NEDtoLLA(const reference_frames::NED&  target,
                                                        const reference_frames::ECEF& referencePoint) noexcept
    {
        return ECEFtoLLA(NEDtoECEF(target, referencePoint));
    }

    /**
     * @brief Converts the NED coordinates to LLA
     *        https://apps.dtic.mil/sti/pdfs/AD1170763.pdf
     *        Figure 11 https://apps.dtic.mil/sti/pdfs/AD1170763.pdf for a helpful diagram
     *        https://en.wikipedia.org/wiki/Local_tangent_plane_coordinates
     *
     * @param target: the target of interest
     * @param referencePoint: the referencePoint location
     * @returns NED
     */
    [[nodiscard]] inline reference_frames::LLA NEDtoLLA(const reference_frames::NED& target,
                                                        const reference_frames::LLA& referencePoint) noexcept
    {
        return ECEFtoLLA(NEDtoECEF(target, referencePoint));
    }
} // namespace nc::coordinates::transforms
