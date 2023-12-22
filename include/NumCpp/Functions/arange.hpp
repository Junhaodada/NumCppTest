
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>
#include <vector>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return evenly spaced values within a given interval.
    ///
    /// Values are generated within the half - open interval[start, stop)
    /// (in other words, the interval including start but excluding stop).
    /// For integer arguments the function is equivalent to the Python built - in
    /// range function, but returns an ndarray rather than a list.
    ///
    /// When using a non - integer step, such as 0.1, the results will often
    /// not be consistent.It is better to use linspace for these cases.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arange.html
    ///
    /// @param inStart
    /// @param inStop
    /// @param inStep: (Optional, defaults to 1)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> arange(dtype inStart, dtype inStop, dtype inStep = 1)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inStep > 0 && inStop < inStart)
        {
            THROW_INVALID_ARGUMENT_ERROR("stop value must be larger than the start value for positive step.");
        }

        if (inStep < 0 && inStop > inStart)
        {
            THROW_INVALID_ARGUMENT_ERROR("start value must be larger than the stop value for negative step.");
        }

        std::vector<dtype> values;

        dtype theValue = inStart;
        auto  counter  = dtype{ 1 };

        if (inStep > 0)
        {
            while (theValue < inStop)
            {
                values.push_back(theValue);
                theValue = inStart + inStep * counter++;
            }
        }
        else
        {
            while (theValue > inStop)
            {
                values.push_back(theValue);
                theValue = inStart + inStep * counter++;
            }
        }

        return NdArray<dtype>(values);
    }

    //============================================================================
    // Method Description:
    /// Return evenly spaced values within a given interval.
    ///
    /// Values are generated within the half - open interval[start, stop)
    /// (in other words, the interval including start but excluding stop).
    /// For integer arguments the function is equivalent to the Python built - in
    /// range function, but returns an ndarray rather than a list.
    ///
    /// When using a non - integer step, such as 0.1, the results will often
    /// not be consistent.It is better to use linspace for these cases.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arange.html
    ///
    /// @param inStop: start is 0 and step is 1
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> arange(dtype inStop)
    {
        if (inStop <= 0)
        {
            THROW_INVALID_ARGUMENT_ERROR("stop value must ge greater than 0.");
        }

        return arange<dtype>(0, inStop, 1);
    }

    //============================================================================
    // Method Description:
    /// Return evenly spaced values within a given interval.
    ///
    /// Values are generated within the half - open interval[start, stop)
    /// (in other words, the interval including start but excluding stop).
    /// For integer arguments the function is equivalent to the Python built - in
    /// range function, but returns an ndarray rather than a list.
    ///
    /// When using a non - integer step, such as 0.1, the results will often
    /// not be consistent.It is better to use linspace for these cases.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.arange.html
    ///
    /// @param inSlice
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> arange(const Slice& inSlice)
    {
        return arange<dtype>(inSlice.start, inSlice.stop, inSlice.step);
    }
} // namespace nc
