
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <complex>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// maximum of inputs.
    ///
    /// Compare two value and returns a value containing the
    /// maxima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmax.html
    ///
    /// @param inValue1
    /// @param inValue2
    /// @return value
    ///
    template<typename dtype>
    dtype fmax(dtype inValue1, dtype inValue2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::max(inValue1,
                        inValue2,
                        [](const dtype value1, const dtype value2) noexcept -> bool { return value1 < value2; });
    }

    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// Compare two arrays and returns a new array containing the
    /// element - wise maxima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmax.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fmax(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return broadcast::broadcaster<dtype>(inArray1,
                                             inArray2,
                                             [](dtype inValue1, dtype inValue2) noexcept -> dtype
                                             { return fmax(inValue1, inValue2); });
    }

    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// Compare two arrays and returns a new array containing the
    /// element - wise maxima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmax.html
    ///
    /// @param inArray
    /// @param inScalar
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fmax(const NdArray<dtype>& inArray, const dtype& inScalar)
    {
        const NdArray<dtype> inArray2 = { inScalar };
        return fmax(inArray, inArray2);
    }

    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// Compare two arrays and returns a new array containing the
    /// element - wise maxima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmax.html
    ///
    /// @param inScalar
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fmax(const dtype& inScalar, const NdArray<dtype>& inArray)
    {
        return fmax(inArray, inScalar);
    }
} // namespace nc
