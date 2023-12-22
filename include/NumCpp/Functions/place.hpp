
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Change elements of an array based on conditional and input values.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.place.html
    ///
    /// @param arr: Array to put data into.
    /// @param mask: Boolean mask array. Must have the same size as arr
    /// @param vals: Values to put into a. Only the first N elements are used, where N is the
    ///              number of True values in mask. If vals is smaller than N, it will be repeated.
    ///
    template<typename dtype>
    void place(NdArray<dtype>& arr, const NdArray<bool>& mask, const NdArray<dtype>& vals)
    {
        if (mask.size() != arr.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("Input arguments 'arr' and 'mask' must have the same size.");
        }

        if (vals.isempty())
        {
            return;
        }

        auto valIdx = 0;
        for (decltype(arr.size()) i = 0; i < arr.size(); ++i)
        {
            if (mask[i])
            {
                arr[i] = vals[valIdx++ % vals.size()];
            }
        }
    }
} // namespace nc
