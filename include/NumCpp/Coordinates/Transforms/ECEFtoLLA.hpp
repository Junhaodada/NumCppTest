
/// Description
/// Coordinate Transforms
///
#pragma once

#include <cmath>

#include "NumCpp/Coordinates/ReferenceFrames/Constants.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/LLA.hpp"
#include "NumCpp/Core/Constants.hpp"
#include "NumCpp/Functions/sign.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts ECEF coordinates to LLA
     * 		  https://en.wikipedia.org/wiki/Geographic_coordinate_conversion#From_ECEF_to_geodetic_coordinates
     *
     * @param ecef the point of interest
     * @param tol Tolerance for the convergence of altitude (overriden if 10 iterations are processed)
     * @return LLA
     */
    [[nodiscard]] inline reference_frames::LLA ECEFtoLLA(const reference_frames::ECEF& ecef, double tol = 1e-8) noexcept
    {
        constexpr int  MAX_ITER = 10;
        constexpr auto E_SQR    = 1. - utils::sqr(reference_frames::constants::EARTH_POLAR_RADIUS /
                                               reference_frames::constants::EARTH_EQUATORIAL_RADIUS);

        const auto p   = std::hypot(ecef.x, ecef.y);
        const auto lon = std::atan2(ecef.y, ecef.x);

        double alt = 0.0;
        double lat = 0.0;

        if (p < tol)
        {
            lat = sign(ecef.z) * constants::pi / 2.;
            alt = std::abs(ecef.z) - reference_frames::constants::EARTH_POLAR_RADIUS;
        }
        else
        {
            // Iteratively update latitude and altitude.
            // This is expected to converge in ~4 iterations, but apply a maximum number of iterations incase tol is
            // too small
            double err  = 1.0;
            int    iter = 0;
            while (err > tol && iter < MAX_ITER)
            {
                double N = reference_frames::constants::EARTH_EQUATORIAL_RADIUS /
                           std::sqrt(1 - E_SQR * utils::sqr(std::sin(lat)));
                lat           = std::atan((ecef.z / p) / (1 - (N * E_SQR / (N + alt))));
                double newAlt = (p / std::cos(lat)) - N;
                err           = std::abs(alt - newAlt);
                alt           = newAlt;
                iter++;
            }
        }
        return { lat, lon, alt };
    }
} // namespace nc::coordinates::transforms
