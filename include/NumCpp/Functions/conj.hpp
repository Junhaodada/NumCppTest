
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
    /// Return the complex conjugate of the complex argument.
    ///
    /// NumPy Reference: https://numpy.org/devdocs/reference/generated/numpy.conj.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto conj(const std::complex<dtype>& inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::conj(inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the complex conjugate of the complex argument.
    ///
    /// NumPy Reference: https://numpy.org/devdocs/reference/generated/numpy.conj.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto conj(const NdArray<std::complex<dtype>>& inArray)
    {
        NdArray<decltype(nc::conj(std::complex<dtype>{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](auto& inValue) -> auto { return nc::conj(inValue); });

        return returnArray;
    }
} // namespace nc
