
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <initializer_list>
#include <vector>

#include "NumCpp/Functions/column_stack.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Stack arrays in sequence horizontally (column wise).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.hstack.html
    ///
    ///
    /// @param inArrayList: {list} of arrays to stack
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> hstack(std::initializer_list<NdArray<dtype>> inArrayList)
    {
        return detail::column_stack<dtype>(inArrayList.begin(), inArrayList.end());
    }

    //============================================================================
    // Method Description:
    /// Stack arrays in sequence horizontally (column wise).
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.hstack.html
    ///
    ///
    /// @param inArrayList: {list} of arrays to stack
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> hstack(std::vector<NdArray<dtype>> inArrayList)
    {
        return detail::column_stack<dtype>(inArrayList.begin(), inArrayList.end());
    }
} // namespace nc
