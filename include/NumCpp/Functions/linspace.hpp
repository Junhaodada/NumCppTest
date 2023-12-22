
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return evenly spaced numbers over a specified interval.
    ///
    /// Returns num evenly spaced samples, calculated over the
    /// interval[start, stop].
    ///
    /// The endpoint of the interval can optionally be excluded.
    ///
    /// Mostly only usefull if called with a floating point type
    /// for the template argument.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.linspace.html
    ///
    /// @param inStart
    /// @param inStop
    /// @param inNum: number of points (default = 50)
    /// @param endPoint: include endPoint (default = true)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> linspace(dtype inStart, dtype inStop, uint32 inNum = 50, EndPoint endPoint = EndPoint::YES)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inNum == 0)
        {
            return NdArray<dtype>(0);
        }

        if (inNum == 1)
        {
            NdArray<dtype> returnArray = { inStart };
            return returnArray;
        }

        if (inStop <= inStart)
        {
            THROW_INVALID_ARGUMENT_ERROR("stop value must be greater than the start value.");
        }

        if (endPoint == EndPoint::YES)
        {
            if (inNum == 2)
            {
                NdArray<dtype> returnArray = { inStart, inStop };
                return returnArray;
            }

            NdArray<dtype> returnArray(1, inNum);
            returnArray.front() = inStart;
            returnArray.back()  = inStop;

            dtype step = (inStop - inStart) / static_cast<dtype>(inNum - 1);

            for (uint32 i = 1; i < inNum - 1; ++i)
            {
                returnArray[i] = inStart + static_cast<dtype>(i) * step;
            }

            return returnArray;
        }

        if (inNum == 2)
        {
            dtype          step        = (inStop - inStart) / (inNum);
            NdArray<dtype> returnArray = { inStart, inStart + step };
            return returnArray;
        }

        NdArray<dtype> returnArray(1, inNum);
        returnArray.front() = inStart;

        dtype step = (inStop - inStart) / static_cast<dtype>(inNum);

        for (uint32 i = 1; i < inNum; ++i)
        {
            returnArray[i] = inStart + static_cast<dtype>(i) * step;
        }

        return returnArray;
    }
} // namespace nc
