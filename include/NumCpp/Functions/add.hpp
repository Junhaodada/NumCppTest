
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
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> add(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 + inArray2;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> add(const NdArray<dtype>& inArray, dtype value)
    {
        return inArray + value;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> add(dtype value, const NdArray<dtype>& inArray)
    {
        return value + inArray;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> add(const NdArray<dtype>& inArray1, const NdArray<std::complex<dtype>>& inArray2)
    {
        return inArray1 + inArray2;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> add(const NdArray<std::complex<dtype>>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1 + inArray2;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> add(const NdArray<dtype>& inArray, const std::complex<dtype>& value)
    {
        return inArray + value;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> add(const std::complex<dtype>& value, const NdArray<dtype>& inArray)
    {
        return value + inArray;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param inArray
    /// @param value
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> add(const NdArray<std::complex<dtype>>& inArray, dtype value)
    {
        return inArray + value;
    }

    //============================================================================
    // Method Description:
    /// Add arguments element-wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.add.html
    ///
    /// @param value
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> add(dtype value, const NdArray<std::complex<dtype>>& inArray)
    {
        return value + inArray;
    }
} // namespace nc
