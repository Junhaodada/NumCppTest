
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return remainder of division.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.remainder.html
    ///
    /// @param inValue1
    /// @param inValue2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    double remainder(dtype inValue1, dtype inValue2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return static_cast<double>(std::remainder(inValue1, inValue2));
    }

    //============================================================================
    // Method Description:
    /// Return element-wise remainder of division.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.remainder.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> remainder(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return broadcast::broadcaster<double>(inArray1,
                                              inArray2,
                                              [](dtype inValue1, dtype inValue2) noexcept -> double
                                              { return remainder(inValue1, inValue2); });
    }
} // namespace nc
