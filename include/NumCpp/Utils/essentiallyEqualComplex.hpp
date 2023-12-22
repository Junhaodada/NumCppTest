
/// Description
/// tests that 2 floating point values are "essentially equal"
///
#pragma once

#include <cmath>
#include <complex>
#include <string>

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StdComplexOperators.hpp"
#include "NumCpp/Core/Internal/TypeTraits.hpp"

namespace nc::utils
{
    //============================================================================
    /// tests that 2 complex values are "essentially equal"
    ///
    /// @param inValue1
    /// @param inValue2
    ///
    /// @return bool
    ///
    template<typename dtype, std::enable_if_t<std::is_integral<dtype>::value, int> = 0>
    bool essentiallyEqual(const std::complex<dtype>& inValue1, const std::complex<dtype>& inValue2) noexcept
    {
        return inValue1 == inValue2;
    }

    //============================================================================
    /// tests that 2 complex values are "essentially equal"
    ///
    /// @param inValue1
    /// @param inValue2
    /// @param inEpsilon
    ///
    /// @return bool
    ///
    template<typename dtype, std::enable_if_t<std::is_floating_point<dtype>::value, int> = 0>
    bool essentiallyEqual(const std::complex<dtype>& inValue1,
                          const std::complex<dtype>& inValue2,
                          const std::complex<dtype>& inEpsilon) noexcept
    {
        const auto absValue1 = std::abs(inValue1);
        const auto absValue2 = std::abs(inValue2);
        return std::abs(inValue1 - inValue2) <= ((absValue1 > absValue2 ? absValue2 : absValue1) * std::abs(inEpsilon));
    }

    //============================================================================
    /// tests that 2 floating point values are "essentially equal"
    ///
    /// @param inValue1
    /// @param inValue2
    ///
    /// @return bool
    ///
    template<typename dtype, std::enable_if_t<std::is_floating_point<dtype>::value, int> = 0>
    bool essentiallyEqual(const std::complex<dtype>& inValue1, const std::complex<dtype>& inValue2) noexcept
    {
        return essentiallyEqual(inValue1, inValue2, DtypeInfo<std::complex<dtype>>::epsilon());
    }
} // namespace nc::utils
