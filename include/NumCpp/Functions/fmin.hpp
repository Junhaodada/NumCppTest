
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
#include "NumCpp/NdArray/NdArrayBroadcast.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// minimum of inputs.
    ///
    /// Compare two value and returns a value containing the
    /// minima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmin.html
    ///
    /// @param inValue1
    /// @param inValue2
    /// @return value
    ///
    template<typename dtype>
    dtype fmin(dtype inValue1, dtype inValue2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::min(inValue1,
                        inValue2,
                        [](const dtype value1, const dtype value2) noexcept -> bool { return value1 < value2; });
    }

    //============================================================================
    // Method Description:
    /// Element-wise minimum of array elements.
    ///
    /// Compare two arrays and returns a new array containing the
    /// element - wise minima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmin.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fmin(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return broadcast::broadcaster<dtype>(inArray1,
                                             inArray2,
                                             [](dtype inValue1, dtype inValue2) noexcept -> dtype
                                             { return fmin(inValue1, inValue2); });
    }

    //============================================================================
    // Method Description:
    /// Element-wise minimum of array elements.
    ///
    /// Compare two arrays and returns a new array containing the
    /// element - wise minima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmin.html
    ///
    /// @param inArray
    /// @param inScalar
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fmin(const NdArray<dtype>& inArray, const dtype& inScalar)
    {
        const NdArray<dtype> inArray2 = { inScalar };
        return fmin(inArray, inArray2);
    }

    //============================================================================
    // Method Description:
    /// Element-wise minimum of array elements.
    ///
    /// Compare two arrays and returns a new array containing the
    /// element - wise minima
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fmin.html
    ///
    /// @param inScalar
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fmin(const dtype& inScalar, const NdArray<dtype>& inArray)
    {
        return fmin(inArray, inScalar);
    }
} // namespace nc
