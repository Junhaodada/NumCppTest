
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
    /// Element-wise maximum of array elements.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.maximum.html
    ///
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> maximum(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const auto comparitor = [](const dtype& lhs, const dtype& rhs) noexcept -> bool { return lhs < rhs; };
        return broadcast::broadcaster<dtype>(inArray1,
                                             inArray2,
                                             [&comparitor](const dtype& value1, const dtype& value2)
                                             { return std::max(value1, value2, comparitor); });
    }

    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.maximum.html
    ///
    ///
    /// @param inArray
    /// @param inScalar
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> maximum(const NdArray<dtype>& inArray, const dtype& inScalar)
    {
        const NdArray<dtype> inArray2 = { inScalar };
        return maximum(inArray, inArray2);
    }

    //============================================================================
    // Method Description:
    /// Element-wise maximum of array elements.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.maximum.html
    ///
    ///
    /// @param inScalar
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> maximum(const dtype& inScalar, const NdArray<dtype>& inArray)
    {
        return maximum(inArray, inScalar);
    }
} // namespace nc
