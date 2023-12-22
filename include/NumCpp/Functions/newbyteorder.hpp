
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the array with the same data viewed with a
    /// different byte order. only works for integer types,
    /// floating point types will not compile and you will
    /// be confused as to why...
    ///
    ///
    /// @param inValue
    /// @param inEndianess
    ///
    /// @return inValue
    ///
    template<typename dtype>
    dtype newbyteorder(dtype inValue, Endian inEndianess)
    {
        NdArray<dtype> valueArray = { inValue };
        return valueArray.newbyteorder(inEndianess).item();
    }

    //============================================================================
    // Method Description:
    /// Return the array with the same data viewed with a
    /// different byte order. only works for integer types,
    /// floating point types will not compile and you will
    /// be confused as to why...
    ///
    ///
    /// @param inArray
    /// @param inEndianess
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> newbyteorder(const NdArray<dtype>& inArray, Endian inEndianess)
    {
        return inArray.newbyteorder(inEndianess);
    }
} // namespace nc
