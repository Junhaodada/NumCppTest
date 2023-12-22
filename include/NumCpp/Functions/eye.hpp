
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a 2-D array with ones on the diagonal and zeros elsewhere.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.eye.html
    ///
    /// @param inN: number of rows (N)
    /// @param inM: number of columns (M)
    /// @param inK: Index of the diagonal: 0 (the default) refers to the main diagonal,
    /// a positive value refers to an upper diagonal, and a negative value to a lower diagonal.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> eye(uint32 inN, uint32 inM, int32 inK = 0)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        NdArray<dtype> returnArray(inN, inM);
        returnArray.zeros();

        if (inK < 0)
        {
            uint32 col = 0;
            for (uint32 row = inK; row < inN; ++row)
            {
                if (col >= inM)
                {
                    break;
                }

                returnArray(row, col++) = dtype{ 1 };
            }
        }
        else
        {
            uint32 row = 0;
            for (uint32 col = inK; col < inM; ++col)
            {
                if (row >= inN)
                {
                    break;
                }

                returnArray(row++, col) = dtype{ 1 };
            }
        }

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// Return a 2-D array with ones on the diagonal and zeros elsewhere.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.eye.html
    ///
    /// @param inN: number of rows and columns (N)
    /// @param inK: Index of the diagonal: 0 (the default) refers to the main diagonal,
    /// a positive value refers to an upper diagonal, and a negative value to a lower diagonal.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> eye(uint32 inN, int32 inK = 0)
    {
        return eye<dtype>(inN, inN, inK);
    }

    //============================================================================
    // Method Description:
    /// Return a 2-D array with ones on the diagonal and zeros elsewhere.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.eye.html
    ///
    /// @param inShape
    /// @param inK: Index of the diagonal: 0 (the default) refers to the main diagonal,
    /// a positive value refers to an upper diagonal, and a negative value to a lower diagonal.
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> eye(const Shape& inShape, int32 inK = 0)
    {
        return eye<dtype>(inShape.rows, inShape.cols, inK);
    }
} // namespace nc
