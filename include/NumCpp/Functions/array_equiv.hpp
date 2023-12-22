
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Returns True if input arrays are shape consistent and all elements equal.
    ///
    /// Shape consistent means they are either the same shape, or one input array
    /// can be broadcasted to create the same shape as the other one.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.array_equiv.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return bool
    ///
    template<typename dtype>
    bool array_equiv(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2) noexcept
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        if (inArray1.size() != inArray2.size())
        {
            return false;
        }

        if (DtypeInfo<dtype>::isInteger())
        {
            return stl_algorithms::equal(inArray1.cbegin(), inArray1.cend(), inArray2.cbegin());
        }

        const auto comparitor = [](dtype value1, dtype value2) noexcept -> bool
        { return utils::essentiallyEqual(value1, value2); };

        return stl_algorithms::equal(inArray1.cbegin(), inArray1.cend(), inArray2.cbegin(), comparitor);
    }
} // namespace nc
