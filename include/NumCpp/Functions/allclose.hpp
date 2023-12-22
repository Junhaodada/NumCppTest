
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/abs.hpp"
#include "NumCpp/Functions/all.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns True if two arrays are element-wise equal within a tolerance.
    /// inTolerance must be a positive number
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.allclose.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @param inTolerance: (Optional, default 1e-5)
    /// @return bool
    ///
    template<typename dtype>
    bool allclose(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2, double inTolerance = 1e-5)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inArray1.shape() != inArray2.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array dimensions are not consistant.");
        }

        for (uint32 i = 0; i < inArray1.size(); ++i)
        {
            if (std::abs(inArray1[i] - inArray2[i]) > inTolerance)
            {
                return false;
            }
        }

        return true;
    }
} // namespace nc
