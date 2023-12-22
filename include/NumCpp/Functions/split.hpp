
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <vector>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Functions/hsplit.hpp"
#include "NumCpp/Functions/vsplit.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Split an array into multiple sub-arrays as views into array.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.split.html
    ///
    /// @param inArray
    /// @param indices: the indices to split
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype, typename Indices, type_traits::ndarray_int_concept<Indices> = 0>
    std::vector<NdArray<dtype>> split(const NdArray<dtype>& inArray, const Indices& indices, Axis inAxis = Axis::ROW)
    {
        switch (inAxis)
        {
            case Axis::ROW:
            {
                return vsplit(inArray, indices);
            }
            case Axis::COL:
            {
                return hsplit(inArray, indices);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("input inAxis must be either Axis::ROW or Axis::COL");
            }
        }

        return {}; // get rid of compiler warning
    }
} // namespace nc
