
/// Description
/// Additional operator for std::complex<T>
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Less than operator for std::complex<T>
    ///
    /// @param lhs
    /// @param rhs
    /// @return bool true if lhs < rhs
    ///
    template<typename T>
    bool operator<(const std::complex<T>& lhs, const std::complex<T>& rhs) noexcept
    {
        if (!utils::essentiallyEqual(lhs.real(), rhs.real()))
        {
            return lhs.real() < rhs.real();
        }

        return lhs.imag() < rhs.imag();
    }

    //============================================================================
    // Method Description:
    /// Less than or equal operator for std::complex<T>
    ///
    /// @param lhs
    /// @param rhs
    /// @return bool true if lhs <= rhs
    ///
    template<typename T>
    bool operator<=(const std::complex<T>& lhs, const std::complex<T>& rhs) noexcept
    {
        if (!utils::essentiallyEqual(lhs.real(), rhs.real()))
        {
            return lhs.real() <= rhs.real();
        }

        return lhs.imag() <= rhs.imag();
    }

    //============================================================================
    // Method Description:
    /// Greater than operator for std::complex<T>
    ///
    /// @param lhs
    /// @param rhs
    /// @return bool true if lhs > rhs
    ///
    template<typename T>
    bool operator>(const std::complex<T>& lhs, const std::complex<T>& rhs) noexcept
    {
        return !(lhs <= rhs);
    }

    //============================================================================
    // Method Description:
    /// Greater than or equal operator for std::complex<T>
    ///
    /// @param lhs
    /// @param rhs
    /// @return bool true if lhs >= rhs
    ///
    template<typename T>
    bool operator>=(const std::complex<T>& lhs, const std::complex<T>& rhs) noexcept
    {
        return !(lhs < rhs);
    }

    //============================================================================
    // Method Description:
    /// Greater than or equal operator for std::complex<T>
    ///
    /// @param value
    /// @return std::complex<Out>
    ///
    template<typename Out, typename In>
    std::complex<Out> complex_cast(const std::complex<In>& value) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(Out);

        return std::complex<Out>(static_cast<Out>(value.real()), static_cast<Out>(value.imag()));
    }
} // namespace nc
