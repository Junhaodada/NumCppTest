
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
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> subtract(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 - inArray2;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> subtract(const NdArray<dtype>& inArray, dtype value)
    {
        return inArray - value;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> subtract(dtype value, const NdArray<dtype>& inArray)
    {
        return value - inArray;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> subtract(const NdArray<dtype>& inArray1, const NdArray<std::complex<dtype>>& inArray2)
    {
        return inArray1 - inArray2;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> subtract(const NdArray<std::complex<dtype>>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 - inArray2;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> subtract(const NdArray<dtype>& inArray, const std::complex<dtype>& value)
    {
        return inArray - value;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> subtract(const std::complex<dtype>& value, const NdArray<dtype>& inArray)
    {
        return value - inArray;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> subtract(const NdArray<std::complex<dtype>>& inArray, dtype value)
    {
        return inArray - value;
    }

    //============================================================================
    // Method Description:
    /// subtract arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.subtract.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> subtract(dtype value, const NdArray<std::complex<dtype>>& inArray)
    {
        return value - inArray;
    }
} // namespace nc
