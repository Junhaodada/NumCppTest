
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Append values to the end of an array.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.append.html
    ///
    /// @param inArray
    /// @param inAppendValues
    /// @param inAxis (Optional, default NONE): The axis along which values are appended.
    /// If axis is not given, both inArray and inAppendValues
    /// are flattened before use.
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> append(const NdArray<dtype>& inArray, const NdArray<dtype>& inAppendValues, Axis inAxis = Axis::NONE)
    {
        if (inArray.shape().isnull())
        {
            return inAppendValues;
        }
        else if (inAppendValues.shape().isnull())
        {
            return inArray;
        }

        switch (inAxis)
        {
            case Axis::NONE:
            {
                NdArray<dtype> returnArray(1, inArray.size() + inAppendValues.size());
                stl_algorithms::copy(inArray.cbegin(), inArray.cend(), returnArray.begin());
                stl_algorithms::copy(inAppendValues.cbegin(),
                                     inAppendValues.cend(),
                                     returnArray.begin() + inArray.size());

                return returnArray;
            }
            case Axis::ROW:
            {
                const Shape inShape     = inArray.shape();
                const Shape appendShape = inAppendValues.shape();
                if (inShape.cols != appendShape.cols)
                {
                    THROW_INVALID_ARGUMENT_ERROR(
                        "all the input array dimensions except for the concatenation axis must match exactly");
                }

                NdArray<dtype> returnArray(inShape.rows + appendShape.rows, inShape.cols);
                stl_algorithms::copy(inArray.cbegin(), inArray.cend(), returnArray.begin());
                stl_algorithms::copy(inAppendValues.cbegin(),
                                     inAppendValues.cend(),
                                     returnArray.begin() + inArray.size());

                return returnArray;
            }
            case Axis::COL:
            {
                const Shape inShape     = inArray.shape();
                const Shape appendShape = inAppendValues.shape();
                if (inShape.rows != appendShape.rows)
                {
                    THROW_INVALID_ARGUMENT_ERROR(
                        "all the input array dimensions except for the concatenation axis must match exactly");
                }

                NdArray<dtype> returnArray(inShape.rows, inShape.cols + appendShape.cols);
                for (uint32 row = 0; row < returnArray.shape().rows; ++row)
                {
                    stl_algorithms::copy(inArray.cbegin(row), inArray.cend(row), returnArray.begin(row));
                    stl_algorithms::copy(inAppendValues.cbegin(row),
                                         inAppendValues.cend(row),
                                         returnArray.begin(row) + inShape.cols);
                }

                return returnArray;
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc
