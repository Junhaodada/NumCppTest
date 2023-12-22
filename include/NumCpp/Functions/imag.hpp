
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the imaginar  part of the complex argument.
    ///
    /// NumPy Reference: https://numpy.org/devdocs/reference/generated/numpy.imag.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto imag(const std::complex<dtype>& inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::imag(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the imaginary part of the complex argument.
    ///
    /// NumPy Reference: https://numpy.org/devdocs/reference/generated/numpy.imag.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto imag(const NdArray<std::complex<dtype>>& inArray)
    {
        NdArray<decltype(nc::imag(std::complex<dtype>{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](auto& inValue) -> auto { return nc::imag(inValue); });

        return returnArray;
    }
} // namespace nc
