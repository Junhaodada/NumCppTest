
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <initializer_list>
#include <vector>

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/column_stack.hpp"
#include "NumCpp/Functions/row_stack.hpp"

namespace nc
{
    namespace detail
    {
        //============================================================================
        // Method Description:
        /// Join a sequence of arrays along an existing axis.
        ///
        /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.concatenate.html
        ///
        /// @param begin: the begin iterator
        /// @param end: the end iterator
        /// @param inAxis (Optional, default NONE)
        /// @return NdArray
        ///
        template<typename dtype, typename Iterator>
        NdArray<dtype> concatenate(Iterator begin, Iterator end, Axis inAxis = Axis::NONE)
        {
            switch (inAxis)
            {
                case Axis::NONE:
                {
                    uint32 finalSize = 0;
                    auto   iter      = begin;
                    while (iter != end)
                    {
                        const auto& ndarray = *iter++;
                        finalSize += ndarray.size();
                    }

                    NdArray<dtype> returnArray(1, finalSize);
                    uint32         offset = 0;
                    iter                  = begin;
                    while (iter != end)
                    {
                        const auto& ndarray = *iter++;
                        stl_algorithms::copy(ndarray.cbegin(), ndarray.cend(), returnArray.begin() + offset);
                        offset += ndarray.size();
                    }

                    return returnArray;
                }
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
                    THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                    return {}; // get rid of compiler warning
                }
            }
        }
    } // namespace detail

    //============================================================================
    // Method Description:
    /// Join a sequence of arrays along an existing axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.concatenate.html
    ///
    /// @param inArrayList
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> concatenate(const std::initializer_list<NdArray<dtype>>& inArrayList, Axis inAxis = Axis::NONE)
    {
        return detail::concatenate<dtype>(inArrayList.begin(), inArrayList.end(), inAxis);
    }

    //============================================================================
    // Method Description:
    /// Join a sequence of arrays along an existing axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.concatenate.html
    ///
    /// @param inArrayList
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> concatenate(const std::vector<NdArray<dtype>>& inArrayList, Axis inAxis = Axis::NONE)
    {
        return detail::concatenate<dtype>(inArrayList.begin(), inArrayList.end(), inAxis);
    }
} // namespace nc
