
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Functions/dot.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Matrix product of two arrays.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.matmul.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> matmul(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return dot(inArray1, inArray2);
    }

    //============================================================================
    // Method Description:
    /// Matrix product of two arrays.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.matmul.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> matmul(const NdArray<dtype>& inArray1, const NdArray<std::complex<dtype>>& inArray2)
    {
        return dot(inArray1, inArray2);
    }

    //============================================================================
    // Method Description:
    /// Matrix product of two arrays.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.matmul.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> matmul(const NdArray<std::complex<dtype>>& inArray1, const NdArray<dtype>& inArray2)
    {
        return dot(inArray1, inArray2);
    }
} // namespace nc
