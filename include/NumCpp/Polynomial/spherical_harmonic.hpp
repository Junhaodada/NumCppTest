
/// Description
/// Special Functions
///
#pragma once

#ifndef NUMCPP_NO_USE_BOOST

#include <complex>

#include "boost/math/special_functions/spherical_harmonic.hpp"

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::polynomial
{
    //============================================================================
    // Method Description:
    /// Returns the value of the Spherical Harmonic Ynm(theta, phi).
    /// The spherical harmonics Ynm(theta, phi) are the angular portion of the
    /// solution to Laplace's equation in spherical coordinates where azimuthal
    /// symmetry is not present.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: order of the harmonic
    /// @param m: degree of the harmonic
    /// @param theta: Azimuthal (longitudinal) coordinate; must be in [0, 2*pi].
    /// @param phi: Polar (colatitudinal) coordinate; must be in [0, pi].
    /// @return double
    ///
    template<typename dtype1, typename dtype2>
    std::complex<double> spherical_harmonic(uint32 n, int32 m, dtype1 theta, dtype2 phi)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

        return boost::math::spherical_harmonic(m, n, static_cast<double>(phi), static_cast<double>(theta));
    }

    //============================================================================
    // Method Description:
    /// Returns the real part of the Spherical Harmonic Ynm(theta, phi).
    /// The spherical harmonics Ynm(theta, phi) are the angular portion of the
    /// solution to Laplace's equation in spherical coordinates where azimuthal
    /// symmetry is not present.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: order of the harmonic
    /// @param m: degree of the harmonic
    /// @param theta: Azimuthal (longitudinal) coordinate; must be in [0, 2*pi].
    /// @param phi: Polar (colatitudinal) coordinate; must be in [0, pi].
    /// @return double
    ///
    template<typename dtype1, typename dtype2>
    double spherical_harmonic_r(uint32 n, int32 m, dtype1 theta, dtype2 phi)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

        return boost::math::spherical_harmonic_r(m, n, static_cast<double>(phi), static_cast<double>(theta));
    }

    //============================================================================
    // Method Description:
    /// Returns the imaginary part of the Spherical Harmonic Ynm(theta, phi).
    /// The spherical harmonics Ynm(theta, phi) are the angular portion of the
    /// solution to Laplace's equation in spherical coordinates where azimuthal
    /// symmetry is not present.
    /// NOTE: Use of this function requires using the Boost includes.
    ///
    /// @param n: order of the harmonic
    /// @param m: degree of the harmonic
    /// @param theta: Azimuthal (longitudinal) coordinate; must be in [0, 2*pi].
    /// @param phi: Polar (colatitudinal) coordinate; must be in [0, pi].
    /// @return double
    ///
    template<typename dtype1, typename dtype2>
    double spherical_harmonic_i(uint32 n, int32 m, dtype1 theta, dtype2 phi)
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

        return boost::math::spherical_harmonic_i(m, n, static_cast<double>(phi), static_cast<double>(theta));
    }
} // namespace nc::polynomial

#endif // #ifndef NUMCPP_NO_USE_BOOST
