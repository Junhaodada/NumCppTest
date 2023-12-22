
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
#include "NumCpp/Utils/sqr.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Given the "legs" of a right triangle, return its hypotenuse.
    ///
    /// Equivalent to sqrt(x1**2 + x2**2), element - wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.hypot.html
    ///
    ///
    /// @param inValue1
    /// @param inValue2
    ///
    /// @return value
    ///
    template<typename dtype>
    double hypot(dtype inValue1, dtype inValue2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::hypot(static_cast<double>(inValue1), static_cast<double>(inValue2));
    }

    //============================================================================
    // Method Description:
    /// Given the "legs" of a right triangle, return its hypotenuse.
    ///
    /// Equivalent to sqrt(x1**2 + x2**2 + x3**2), element - wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.hypot.html
    ///
    ///
    /// @param inValue1
    /// @param inValue2
    /// @param inValue3
    ///
    /// @return value
    ///
    template<typename dtype>
    double hypot(dtype inValue1, dtype inValue2, dtype inValue3) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

#ifdef __cpp_lib_hypot
        return std::hypot(static_cast<double>(inValue1), static_cast<double>(inValue2), static_cast<double>(inValue3));
#else
        return std::sqrt(utils::sqr(static_cast<double>(inValue1)) + utils::sqr(static_cast<double>(inValue2)) +
                         utils::sqr(static_cast<double>(inValue3)));
#endif
    }

    //============================================================================
    // Method Description:
    /// Given the "legs" of a right triangle, return its hypotenuse.
    ///
    /// Equivalent to sqrt(x1**2 + x2**2), element - wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.hypot.html
    ///
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> hypot(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        return broadcast::broadcaster<double>(inArray1,
                                              inArray2,
                                              [](dtype inValue1, dtype inValue2) noexcept -> double
                                              { return hypot(inValue1, inValue2); });
    }

    //============================================================================
    // Method Description:
    /// Given the "legs" of a right triangle, return its hypotenuse.
    ///
    /// Equivalent to sqrt(x1**2 + x2**2), element - wise.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.hypot.html
    ///
    ///
    /// @param inArray1
    /// @param inArray2
    /// @param inArray3
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double>
        hypot(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2, const NdArray<dtype>& inArray3)
    {
        if (inArray1.size() != inArray2.size() || inArray1.size() != inArray3.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array sizes are not consistant.");
        }

        NdArray<double> returnArray(inArray1.shape());
        for (typename NdArray<dtype>::size_type i = 0; i < inArray1.size(); ++i)
        {
            returnArray[i] = hypot(inArray1[i], inArray2[i], inArray3[i]);
        }

        return returnArray;
    }
} // namespace nc
