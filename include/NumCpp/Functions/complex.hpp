
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
    /// Returns a std::complex from the input real and imag components
    ///
    /// @param inReal: the real component of the complex number
    /// @return value
    ///
    template<typename dtype>
    auto complex(dtype inReal)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::complex<dtype>(inReal);
    }

    //============================================================================
    // Method Description:
    /// Returns a std::complex from the input real and imag components
    ///
    /// @param inReal: the real component of the complex number
    /// @param inImag: the imaginary component of the complex number
    /// @return value
    ///
    template<typename dtype>
    auto complex(dtype inReal, dtype inImag)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::complex<dtype>(inReal, inImag);
    }

    //============================================================================
    // Method Description:
    /// Returns a std::complex from the input real and imag components
    ///
    /// @param inReal: the real component of the complex number
    /// @return NdArray
    ///
    template<typename dtype>
    auto complex(const NdArray<dtype>& inReal)
    {
        NdArray<decltype(nc::complex(dtype{ 0 }))> returnArray(inReal.shape());
        stl_algorithms::transform(inReal.cbegin(),
                                  inReal.cend(),
                                  returnArray.begin(),
                                  [](dtype real) -> auto { return nc::complex(real); });

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Returns a std::complex from the input real and imag components
    ///
    /// @param inReal: the real component of the complex number
    /// @param inImag: the imaginary component of the complex number
    /// @return NdArray
    ///
    template<typename dtype>
    auto complex(const NdArray<dtype>& inReal, const NdArray<dtype>& inImag)
    {
        if (inReal.shape() != inImag.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("Input real array must be the same shape as input imag array");
        }

        NdArray<decltype(nc::complex(dtype{ 0 }, dtype{ 0 }))> returnArray(inReal.shape());
        stl_algorithms::transform(inReal.cbegin(),
                                  inReal.cend(),
                                  inImag.cbegin(),
                                  returnArray.begin(),
                                  [](dtype real, dtype imag) -> auto { return nc::complex(real, imag); });

        return returnArray;
    }
} // namespace nc
