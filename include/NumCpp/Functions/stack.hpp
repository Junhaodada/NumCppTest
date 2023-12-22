
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <initializer_list>
#include <string>
#include <vector>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/column_stack.hpp"
#include "NumCpp/Functions/row_stack.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Compute the variance along the specified axis.
        ///
        /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.stack.html
        ///
        /// @param begin: iterator to the beginning of the span
        /// @param end: iterator to one past the end of the span
        /// @param inAxis: the axis to stack
        /// @return NdArray
        ///
        template<typename dtype, typename Iterator>
        NdArray<dtype> stack(Iterator begin, Iterator end, Axis inAxis)
        {
            switch (inAxis)
            {
                case Axis::ROW:
                {
                    return row_stack<dtype>(begin, end);
                }
                case Axis::COL:
                {
                    return column_stack<dtype>(begin, end);
                }
                default:
                {
                    THROW_INVALID_ARGUMENT_ERROR("inAxis must be either ROW or COL.");
                    return {}; // getting rid of compiler warning
                }
            }
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Compute the variance along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.stack.html
    ///
    /// @param inArrayList: {list} of arrays to stack
    /// @param inAxis: axis to stack the input NdArrays
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> stack(std::initializer_list<NdArray<dtype>> inArrayList, Axis inAxis = Axis::NONE)
    {
        return detail::stack<dtype>(inArrayList.begin(), inArrayList.end(), inAxis);
    }

    //============================================================================
    // Method Description:
    /// Compute the variance along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.stack.html
    ///
    /// @param inArrayList: {list} of arrays to stack
    /// @param inAxis: axis to stack the input NdArrays
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> stack(std::vector<NdArray<dtype>> inArrayList, Axis inAxis = Axis::NONE)
    {
        return detail::stack<dtype>(inArrayList.begin(), inArrayList.end(), inAxis);
    }
} // namespace nc
