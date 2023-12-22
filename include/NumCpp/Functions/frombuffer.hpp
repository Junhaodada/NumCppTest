
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Interpret a buffer as a 1-dimensional array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.frombuffer.html
    ///
    /// @param inBufferPtr
    /// @param inNumBytes
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> frombuffer(const char* inBufferPtr, uint32 inNumBytes)
    {
        if (inNumBytes % sizeof(dtype) != 0)
        {
            THROW_INVALID_ARGUMENT_ERROR("inNumBytes % sizeof(dtype) != 0");
        }

        const auto numElements = static_cast<uint32>(inNumBytes / sizeof(dtype));
        return NdArray<dtype>(reinterpret_cast<const dtype*>(inBufferPtr), numElements);
    }
} // namespace nc
