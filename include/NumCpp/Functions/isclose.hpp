
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns a boolean array where two arrays are element-wise
    /// equal within a tolerance.
    ///
    /// For finite values, isclose uses the following equation to test whether two floating point values are equivalent.
    /// absolute(a - b) <= (atol + rtol * absolute(b))
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.isclose.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @param inRtol: relative tolerance (default 1e-5)
    /// @param inAtol: absolute tolerance (default 1e-9)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<bool> isclose(const NdArray<dtype>& inArray1,
                          const NdArray<dtype>& inArray2,
                          double                inRtol = 1e-05,
                          double                inAtol = 1e-08)
    {
        STATIC_ASSERT_FLOAT(dtype);

        if (inArray1.shape() != inArray2.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array shapes are not consistant.");
        }

        NdArray<bool> returnArray(inArray1.shape());
        stl_algorithms::transform(inArray1.cbegin(),
                                  inArray1.cend(),
                                  inArray2.cbegin(),
                                  returnArray.begin(),
                                  [inRtol, inAtol](dtype inValueA, dtype inValueB) noexcept -> bool
                                  { return std::abs(inValueA - inValueB) <= (inAtol + inRtol * std::abs(inValueB)); });

        return returnArray;
    }
} // namespace nc
