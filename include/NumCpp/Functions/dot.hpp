
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
    /// Dot product of two arrays.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.dot.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> dot(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return inArray1.dot(inArray2);
    }

    //============================================================================
    // Method Description:
    /// Dot product of two arrays.
    ///
    /// For 2-D arrays it is equivalent to matrix multiplication,
    /// and for 1-D arrays to inner product of vectors.
    ///
    /// Numpy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.ndarray.dot.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> dot(const NdArray<dtype>& inArray1, const NdArray<std::complex<dtype>>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const auto shape1 = inArray1.shape();
        const auto shape2 = inArray2.shape();

        if (shape1 == shape2 && (shape1.rows == 1 || shape1.cols == 1))
        {
            const std::complex<dtype> dotProduct =
                std::inner_product(inArray1.cbegin(), inArray1.cend(), inArray2.cbegin(), std::complex<dtype>{ 0 });
            NdArray<std::complex<dtype>> returnArray = { dotProduct };
            return returnArray;
        }
        if (shape1.cols == shape2.rows)
        {
            // 2D array, use matrix multiplication
            NdArray<std::complex<dtype>> returnArray(shape1.rows, shape2.cols);
            auto                         array2T = inArray2.transpose();

            for (uint32 i = 0; i < shape1.rows; ++i)
            {
                for (uint32 j = 0; j < shape2.cols; ++j)
                {
                    returnArray(i, j) = std::inner_product(array2T.cbegin(j),
                                                           array2T.cend(j),
                                                           inArray1.cbegin(i),
                                                           std::complex<dtype>{ 0 });
                }
            }

            return returnArray;
        }

        std::string errStr = "shapes of [" + utils::num2str(shape1.rows) + ", " + utils::num2str(shape1.cols) + "]";
        errStr += " and [" + utils::num2str(shape2.rows) + ", " + utils::num2str(shape2.cols) + "]";
        errStr += " are not consistent.";
        THROW_INVALID_ARGUMENT_ERROR(errStr);

        return NdArray<std::complex<dtype>>(); // get rid of compiler warning
    }

    //============================================================================
    // Method Description:
    /// Dot product of two arrays.
    ///
    /// For 2-D arrays it is equivalent to matrix multiplication,
    /// and for 1-D arrays to inner product of vectors.
    ///
    /// Numpy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.ndarray.dot.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<dtype>> dot(const NdArray<std::complex<dtype>>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        const auto shape1 = inArray1.shape();
        const auto shape2 = inArray2.shape();

        if (shape1 == shape2 && (shape1.rows == 1 || shape1.cols == 1))
        {
            const std::complex<dtype> dotProduct =
                std::inner_product(inArray1.cbegin(), inArray1.cend(), inArray2.cbegin(), std::complex<dtype>{ 0 });
            NdArray<std::complex<dtype>> returnArray = { dotProduct };
            return returnArray;
        }
        if (shape1.cols == shape2.rows)
        {
            // 2D array, use matrix multiplication
            NdArray<std::complex<dtype>> returnArray(shape1.rows, shape2.cols);
            auto                         array2T = inArray2.transpose();

            for (uint32 i = 0; i < shape1.rows; ++i)
            {
                for (uint32 j = 0; j < shape2.cols; ++j)
                {
                    returnArray(i, j) = std::inner_product(array2T.cbegin(j),
                                                           array2T.cend(j),
                                                           inArray1.cbegin(i),
                                                           std::complex<dtype>{ 0 });
                }
            }

            return returnArray;
        }

        std::string errStr = "shapes of [" + utils::num2str(shape1.rows) + ", " + utils::num2str(shape1.cols) + "]";
        errStr += " and [" + utils::num2str(shape2.rows) + ", " + utils::num2str(shape2.cols) + "]";
        errStr += " are not consistent.";
        THROW_INVALID_ARGUMENT_ERROR(errStr);

        return NdArray<std::complex<dtype>>(); // get rid of compiler warning
    }
} // namespace nc
