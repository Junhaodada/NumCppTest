
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <set>
#include <vector>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Find the intersection of two arrays.
    ///
    /// Return the sorted, unique values that are in both of the input arrays.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.intersect1d.html
    ///
    /// @param inArray1
    /// @param inArray2
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> intersect1d(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        std::vector<dtype>    res(inArray1.size() + inArray2.size());
        const std::set<dtype> in1(inArray1.cbegin(), inArray1.cend());
        const std::set<dtype> in2(inArray2.cbegin(), inArray2.cend());

        const auto iter = stl_algorithms::set_intersection(in1.begin(), in1.end(), in2.begin(), in2.end(), res.begin());
        res.resize(iter - res.begin());
        return NdArray<dtype>(res);
    }
} // namespace nc
