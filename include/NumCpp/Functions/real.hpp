
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the real part of the complex argument.
    ///
    /// NumPy Reference: https://numpy.org/devdocs/reference/generated/numpy.real.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto real(const std::complex<dtype>& inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::real(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the real part of the complex argument.
    ///
    /// NumPy Reference: https://numpy.org/devdocs/reference/generated/numpy.real.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto real(const NdArray<std::complex<dtype>>& inArray)
    {
        NdArray<decltype(nc::real(std::complex<dtype>{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](auto& inValue) -> auto { return nc::real(inValue); });

        return returnArray;
    }
} // namespace nc
