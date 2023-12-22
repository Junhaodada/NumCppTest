
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/powerf.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the nth-root of an value.
    ///
    /// @param inValue
    /// @param inRoot
    /// @return value
    ///
    template<typename dtype1, typename dtype2>
    double nth_root(dtype1 inValue, dtype2 inRoot) noexcept
    {
        STATIC_ASSERT_ARITHMETIC(dtype1);
        STATIC_ASSERT_ARITHMETIC(dtype2);

        return utils::powerf(static_cast<double>(inValue), 1. / static_cast<double>(inRoot));
    }

    //============================================================================
    // Method Description:
    /// Return the nth-root of an array.
    ///
    /// @param inArray
    /// @param inRoot
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    NdArray<double> nth_root(const NdArray<dtype1>& inArray, dtype2 inRoot)
    {
        NdArray<double> returnArray(inArray.shape());
        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [inRoot](dtype1 inValue) noexcept -> double { return nth_root(inValue, inRoot); });

        return returnArray;
    }
} // namespace nc
