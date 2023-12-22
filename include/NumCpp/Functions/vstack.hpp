
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <initializer_list>
#include <vector>

#include "NumCpp/Functions/row_stack.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the variance along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.vstack.html
    ///
    /// @param inArrayList: {list} of arrays to stack
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> vstack(std::initializer_list<NdArray<dtype>> inArrayList)
    {
        return detail::row_stack<dtype>(inArrayList.begin(), inArrayList.end());
    }

    //============================================================================
    // Method Description:
    /// Compute the variance along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.vstack.html
    ///
    /// @param inArrayList: {list} of arrays to stack
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> vstack(std::vector<NdArray<dtype>> inArrayList)
    {
        return detail::row_stack<dtype>(inArrayList.begin(), inArrayList.end());
    }
} // namespace nc
