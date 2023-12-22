
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <cmath>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the sinc function.
    ///
    /// The sinc function is sin(pi*x) / (pi*x).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sinc.html
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto sinc(dtype inValue) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        return std::sin(constants::pi * inValue) / (constants::pi * inValue);
    }

    //============================================================================
    // Method Description:
    /// Return the sinc function.
    ///
    /// The sinc function is sin(pi*x) / (pi*x).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.sinc.html
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto sinc(const NdArray<dtype>& inArray)
    {
        NdArray<decltype(sinc(dtype{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](dtype inValue) noexcept -> auto { return sinc(inValue); });

        return returnArray;
    }
} // namespace nc
