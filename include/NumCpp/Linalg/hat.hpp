
/// Description
/// vector hat operator
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Vector/Vec3.hpp"

namespace nc::linalg
{
    //============================================================================
    // Method Description:
    /// vector hat operator
    ///
    /// @param inX
    /// @param inY
    /// @param inZ
    /// @return 3x3 NdArray
    ///
    template<typename dtype>
    NdArray<dtype> hat(dtype inX, dtype inY, dtype inZ)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        NdArray<dtype> returnArray(3);
        returnArray(0, 0) = 0.;
        returnArray(0, 1) = -inZ;
        returnArray(0, 2) = inY;
        returnArray(1, 0) = inZ;
        returnArray(1, 1) = 0.;
        returnArray(1, 2) = -inX;
        returnArray(2, 0) = -inY;
        returnArray(2, 1) = inX;
        returnArray(2, 2) = 0.;

        return returnArray;
    }

    //============================================================================
    // Method Description:
    /// vector hat operator
    ///
    /// @param inVec (3x1, or 1x3 cartesian vector)
    /// @return 3x3 NdArray
    ///
    template<typename dtype>
    NdArray<dtype> hat(const NdArray<dtype>& inVec)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inVec.size() != 3)
        {
            THROW_INVALID_ARGUMENT_ERROR("input vector must be a length 3 cartesian vector.");
        }

        return hat(inVec[0], inVec[1], inVec[2]);
    }

    //============================================================================
    // Method Description:
    /// vector hat operator
    ///
    /// @param inVec
    /// @return 3x3 NdArray
    ///
    inline NdArray<double> hat(const Vec3& inVec)
    {
        return hat(inVec.x, inVec.y, inVec.z);
    }
} // namespace nc::linalg
