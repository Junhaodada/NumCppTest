
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Evenly round to the given number of decimals.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.take.html
    ///
    /// @param inArray
    /// @param inIndices
    /// @param inAxis
    /// @return NdArray
    ///
    template<typename dtype, typename Indices, type_traits::ndarray_int_concept<Indices> = 0>
    NdArray<dtype> take(const NdArray<dtype>& inArray, const Indices& inIndices, Axis inAxis = Axis::NONE)
    {
        switch (inAxis)
        {
            case Axis::NONE:
            {
                return inArray[inIndices];
            }
            case Axis::ROW:
            {
                return inArray(inIndices, inArray.cSlice());
            }
            case Axis::COL:
            {
                return inArray(inArray.rSlice(), inIndices);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }

} // namespace nc
