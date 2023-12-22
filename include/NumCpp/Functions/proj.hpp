
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns the projection of the complex number z onto the Riemann sphere.
    ///
    /// @param inValue
    /// @return value
    ///
    template<typename dtype>
    auto proj(const std::complex<dtype>& inValue)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return std::proj(inValue);
    }

    //============================================================================
    // Method Description:
    /// Returns the projection of the complex number z onto the Riemann sphere.
    ///
    /// @param inArray
    /// @return NdArray
    ///
    template<typename dtype>
    auto proj(const NdArray<std::complex<dtype>>& inArray)
    {
        NdArray<decltype(nc::proj(std::complex<dtype>{ 0 }))> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](auto& inValue) -> auto { return nc::proj(inValue); });

        return returnArray;
    }
} // namespace nc
