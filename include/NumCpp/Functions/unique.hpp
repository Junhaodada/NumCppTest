
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>
#include <vector>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Functions/sort.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Find the unique elements of an array.
    ///
    /// Returns the sorted unique elements of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.unique.html
    ///
    /// @param inArray
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> unique(const NdArray<dtype>& inArray)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const auto comp = [](const dtype lhs, const dtype rhs) noexcept -> bool
        { return utils::essentiallyEqual(lhs, rhs); };

        const auto sorted = sort(inArray);

        std::vector<dtype> res(sorted.size());
        const auto         last = stl_algorithms::unique_copy(sorted.begin(), sorted.end(), res.begin(), comp);

        return NdArray<dtype>(res.begin(), last);
    }
} // namespace nc
