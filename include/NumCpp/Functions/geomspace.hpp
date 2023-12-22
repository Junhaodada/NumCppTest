
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/logb.hpp"
#include "NumCpp/Functions/logspace.hpp"
#include "NumCpp/Functions/nth_root.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return numbers spaced evenly on a log scale (a geometric progression).
    ///
    /// This is similar to logspace, but with endpoints specified directly.
    /// Each output sample is a constant multiple of the previous.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.geomspace.html
    ///
    /// @param start: the starting value of a sequence
    /// @param stop: The final value of the sequence, unless endpoint is False.
    /// In that case, num + 1 values are spaced over the interval
    /// in log-space, of which all but the last (a sequence of length num) are returned.
    /// @param num: Number of samples to generate. Default 50.
    /// @param endPoint: If true, stop is the last sample. Otherwide,it is not included. Default is true.
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> geomspace(dtype start, dtype stop, uint32 num = 50, EndPoint endPoint = EndPoint::YES)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        if (utils::essentiallyEqual(start, dtype{ 0 }))
        {
            THROW_INVALID_ARGUMENT_ERROR("Geometric sequence cannot include zero");
        }

        if (num == 1)
        {
            return { static_cast<double>(start) };
        }
        else if (num == 2 && endPoint == EndPoint::YES)
        {
            return { static_cast<double>(start), static_cast<double>(stop) };
        }

        const auto base     = nth_root(stop / start, num - 1);
        const auto logStart = logb(start, base);
        const auto logStop  = logb(stop, base);
        return logspace(logStart, logStop, num, endPoint, base);
    }
} // namespace nc
