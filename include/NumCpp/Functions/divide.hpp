
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> divide(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 / inArray2;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> divide(const NdArray<dtype>& inArray, dtype value)
    {
        return inArray / value;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> divide(dtype value, const NdArray<dtype>& inArray)
    {
        return value / inArray;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> divide(const NdArray<dtype>& inArray1, const NdArray<std::complex<dtype>>& inArray2)
    {
        return inArray1 / inArray2;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> divide(const NdArray<std::complex<dtype>>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 / inArray2;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> divide(const NdArray<dtype>& inArray, const std::complex<dtype>& value)
    {
        return inArray / value;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> divide(const std::complex<dtype>& value, const NdArray<dtype>& inArray)
    {
        return value / inArray;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> divide(const NdArray<std::complex<dtype>>& inArray, dtype value)
    {
        return inArray / value;
    }

    //============================================================================
    // Method Description:
    /// divide arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.divide.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> divide(dtype value, const NdArray<std::complex<dtype>>& inArray)
    {
        return value / inArray;
    }
} // namespace nc
