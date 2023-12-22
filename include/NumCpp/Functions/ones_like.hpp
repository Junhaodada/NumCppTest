
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return a new array of given shape and type, filled with ones.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.ones_like.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtypeOut, typename dtype>
    NdArray<dtypeOut> ones_like(const NdArray<dtype>& inArray)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        NdArray<dtypeOut> returnArray(inArray.shape());
        returnArray.ones();
        return returnArray;
    }
} // namespace nc
