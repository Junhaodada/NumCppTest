
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <complex>
#include <vector>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StdComplexOperators.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Functions/unique.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Find the set difference of two arrays.
    ///
    /// Return the sorted, unique values in ar1 that are not in ar2.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.setdiff1d.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> setdiff1d(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const auto comp = [](const dtype lhs, const dtype rhs) noexcept -> bool { return lhs < rhs; };

        const auto set1 = unique(inArray1);
        const auto set2 = unique(inArray2);

        std::vector<dtype> res(set1.size());
        const auto         last =
            stl_algorithms::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), res.begin(), comp);

        return NdArray<dtype>(res.begin(), last);
    }
} // namespace nc
