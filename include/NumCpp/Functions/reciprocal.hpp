
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StdComplexOperators.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the reciprocal of the argument, element-wise.
    ///
    /// Calculates 1 / x.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.reciprocal.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> reciprocal(const NdArray<dtype>& inArray)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        NdArray<double> returnArray(inArray.shape());

        uint32 counter = 0;
        std::for_each(inArray.cbegin(),
                      inArray.cend(),
                      [&returnArray, &counter](dtype value) noexcept -> void
                      { returnArray[counter++] = 1. / static_cast<double>(value); });

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Return the reciprocal of the argument, element-wise.
    ///
    /// Calculates 1 / x.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.reciprocal.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<double>> reciprocal(const NdArray<std::complex<dtype>>& inArray)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        NdArray<std::complex<double>> returnArray(inArray.shape());

        uint32 counter = 0;
        std::for_each(inArray.cbegin(),
                      inArray.cend(),
                      [&returnArray, &counter](std::complex<dtype> value) -> void
                      { returnArray[counter++] = std::complex<double>(1.) / complex_cast<double>(value); });

        return returnArray;
    }
} // namespace nc
