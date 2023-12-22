
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return elements, either from x or y, depending on the input mask.
    /// The output array contains elements of x where mask is True, and
    /// elements from y elsewhere.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.where.html
    ///
    /// @param inMask
    /// @param inA
    /// @param inB
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> where(const NdArray<bool>& inMask, const NdArray<dtype>& inA, const NdArray<dtype>& inB)
    {
        const auto shapeMask = inMask.shape();
        const auto shapeA    = inA.shape();
        if (shapeA != inB.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input inA and inB must be the same shapes.");
        }

        if (shapeMask != shapeA)
        {
            THROW_INVALID_ARGUMENT_ERROR("input inMask must be the same shape as the input arrays.");
        }

        auto outArray = NdArray<dtype>(shapeMask);

        uint32 idx = 0;
        for (auto maskValue : inMask)
        {
            if (maskValue)
            {
                outArray[idx] = inA[idx];
            }
            else
            {
                outArray[idx] = inB[idx];
            }
            ++idx;
        }

        return outArray;
    }

    //============================================================================
    // Method Description:
    /// Return elements, either from x or y, depending on the input mask.
    /// The output array contains elements of x where mask is True, and
    /// elements from y elsewhere.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.where.html
    ///
    /// @param inMask
    /// @param inA
    /// @param inB
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> where(const NdArray<bool>& inMask, const NdArray<dtype>& inA, dtype inB)
    {
        const auto shapeMask = inMask.shape();
        const auto shapeA    = inA.shape();
        if (shapeMask != shapeA)
        {
            THROW_INVALID_ARGUMENT_ERROR("input inMask must be the same shape as the input arrays.");
        }

        auto outArray = NdArray<dtype>(shapeMask);

        uint32 idx = 0;
        for (auto maskValue : inMask)
        {
            if (maskValue)
            {
                outArray[idx] = inA[idx];
            }
            else
            {
                outArray[idx] = inB;
            }
            ++idx;
        }

        return outArray;
    }

    //============================================================================
    // Method Description:
    /// Return elements, either from x or y, depending on the input mask.
    /// The output array contains elements of x where mask is True, and
    /// elements from y elsewhere.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.where.html
    ///
    /// @param inMask
    /// @param inA
    /// @param inB
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> where(const NdArray<bool>& inMask, dtype inA, const NdArray<dtype>& inB)
    {
        const auto shapeMask = inMask.shape();
        const auto shapeB    = inB.shape();
        if (shapeMask != shapeB)
        {
            THROW_INVALID_ARGUMENT_ERROR("input inMask must be the same shape as the input arrays.");
        }

        auto outArray = NdArray<dtype>(shapeMask);

        uint32 idx = 0;
        for (auto maskValue : inMask)
        {
            if (maskValue)
            {
                outArray[idx] = inA;
            }
            else
            {
                outArray[idx] = inB[idx];
            }
            ++idx;
        }

        return outArray;
    }

    //============================================================================
    // Method Description:
    /// Return elements, either from x or y, depending on the input mask.
    /// The output array contains elements of x where mask is True, and
    /// elements from y elsewhere.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.where.html
    ///
    /// @param inMask
    /// @param inA
    /// @param inB
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> where(const NdArray<bool>& inMask, dtype inA, dtype inB)
    {
        auto outArray = NdArray<dtype>(inMask.shape());

        uint32 idx = 0;
        for (auto maskValue : inMask)
        {
            if (maskValue)
            {
                outArray[idx] = inA;
            }
            else
            {
                outArray[idx] = inB;
            }
            ++idx;
        }

        return outArray;
    }
} // namespace nc
