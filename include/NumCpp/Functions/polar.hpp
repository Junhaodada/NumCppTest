
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns a complex number with magnitude r and phase angle theta.
    ///
    /// @param magnitude
    /// @param phaseAngle
    ///
    /// @return std::complex
    ///
    template<typename dtype>
    auto polar(dtype magnitude, dtype phaseAngle)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::polar(magnitude, phaseAngle);
    }

    //============================================================================
    // Method Description:
    /// Returns a complex number with magnitude r and phase angle theta.
    ///
    /// @param magnitude
    /// @param phaseAngle
    /// @return NdArray<std::complex>
    ///
    template<typename dtype>
    auto polar(const NdArray<dtype>& magnitude, const NdArray<dtype>& phaseAngle)
    {
        if (magnitude.shape() != phaseAngle.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("Input magnitude and phaseAngle arrays must be the same shape");
        }

        NdArray<decltype(nc::polar(dtype{ 0 }, dtype{ 0 }))> returnArray(magnitude.shape());
        stl_algorithms::transform(magnitude.cbegin(),
                                  magnitude.cend(),
                                  phaseAngle.begin(),
                                  returnArray.begin(),
                                  [](dtype mag, dtype angle) -> auto { return nc::polar(mag, angle); });

        return returnArray;
    }
} // namespace nc
