
/// Description
/// Performs Rodriques' rotation formula
/// https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
///
#pragma once

#include <cmath>

#include "NumCpp/NdArray.hpp"
#include "NumCpp/Vector/Vec3.hpp"

namespace nc::rotations
{
    //============================================================================
    // Method Description:
    /// Performs Rodriques' rotation formula
    /// https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
    ///
    /// @param k: the axis to rotate around
    /// @param theta: the angle in radians to rotate
    /// @param v: the vector to rotate
    ///
    /// @return Vec3
    ///
    inline Vec3 rodriguesRotation(const Vec3& k, double theta, const Vec3& v) noexcept
    {
        const auto kUnit = k.normalize();

        const auto vCosTheta = v * std::cos(theta);

        auto kCrossV = kUnit.cross(v);
        kCrossV *= std::sin(theta);

        const auto kDotV  = kUnit.dot(v);
        auto       kkDotV = kUnit * kDotV;
        kkDotV *= 1 - std::cos(theta);

        auto vec = vCosTheta + kCrossV;
        vec += kkDotV;

        return vec;
    }

    //============================================================================
    // Method Description:
    /// Performs Rodriques' rotation formula
    /// https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
    ///
    /// @param k: the axis to rotate around
    /// @param theta: the angle in radians to rotate
    /// @param v: the vector to rotate
    ///
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> rodriguesRotation(const NdArray<dtype>& k, double theta, const NdArray<dtype>& v)
    {
        return rodriguesRotation(Vec3(k), theta, Vec3(v)).toNdArray();
    }
} // namespace nc::rotations