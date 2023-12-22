
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <vector>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the elements of an array that satisfy some condition.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.extract.html
    ///
    /// @param condition: An array whose nonzero or True entries indicate the elements of arr to extract.
    /// @param arr: Input array of the same size as condition
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> extract(const NdArray<bool>& condition, const NdArray<dtype>& arr)
    {
        if (condition.size() != arr.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("Input arguments 'condition' and 'arr' must have the same size.");
        }

        std::vector<dtype> values;
        for (decltype(arr.size()) i = 0; i < arr.size(); ++i)
        {
            if (condition[i])
            {
                values.push_back(arr[i]);
            }
        }

        return NdArray<dtype>(values.begin(), values.end());
    }
} // namespace nc
