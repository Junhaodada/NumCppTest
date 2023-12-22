
/// Description
/// Raise a square matrix to the (integer) power n.
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/dot.hpp"
#include "NumCpp/Functions/identity.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::linalg
{
    //============================================================================
    // Method Description:
    /// Raise a square matrix to the (integer) power n.
    ///
    /// For positive integers n, the power is computed by repeated
    /// matrix squarings and matrix multiplications.  If n == 0,
    /// the identity matrix of the same shape as M is returned.
    /// If n < 0, the inverse is computed and then raised to the abs(n).
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.linalg.matrix_power.html#numpy.linalg.matrix_power
    ///
    /// @param inArray
    /// @param inPower
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> matrix_power(const NdArray<dtype>& inArray, int16 inPower)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const Shape inShape = inArray.shape();
        if (inShape.rows != inShape.cols)
        {
            THROW_INVALID_ARGUMENT_ERROR("input matrix must be square.");
        }

        if (inPower == 0)
        {
            return identity<double>(inShape.rows);
        }

        if (inPower == 1)
        {
            return inArray.template astype<double>();
        }

        if (inPower == -1)
        {
            return inv(inArray);
        }

        if (inPower > 1)
        {
            NdArray<double> inArrayDouble = inArray.template astype<double>();
            NdArray<double> returnArray   = dot(inArrayDouble, inArrayDouble);
            for (int16 i = 2; i < inPower; ++i)
            {
                returnArray = dot(returnArray, inArrayDouble);
            }
            return returnArray;
        }

        NdArray<double> inverse     = inv(inArray);
        NdArray<double> returnArray = dot(inverse, inverse);
        inPower *= -1;
        for (int16 i = 2; i < inPower; ++i)
        {
            returnArray = dot(returnArray, inverse);
        }
        return returnArray;
    }
} // namespace nc::linalg
