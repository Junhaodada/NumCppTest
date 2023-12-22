
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/full.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with zeros.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.zeros.html
    ///
    /// @param inSquareSize
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> zeros(uint32 inSquareSize)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return full(inSquareSize, dtype{ 0 });
    }

    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with zeros.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.zeros.html
    ///
    /// @param inNumRows
    /// @param inNumCols
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> zeros(uint32 inNumRows, uint32 inNumCols)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return full(inNumRows, inNumCols, dtype{ 0 });
    }

    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with zeros.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.zeros.html
    ///
    /// @param inShape
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> zeros(const Shape& inShape)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return full(inShape, dtype{ 0 });
    }
} // namespace nc
