
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the cross product of two (arrays of) vectors.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.cross.html
    ///
    /// @param inArray1
    /// @param inArray2
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> cross(const NdArray<dtype>& inArray1, const NdArray<dtype>& inArray2, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        if (inArray1.shape() != inArray2.shape())
        {
            THROW_INVALID_ARGUMENT_ERROR("the input array dimensions are not consistant.");
        }

        switch (inAxis)
        {
            case Axis::NONE:
            {
                const uint32 arraySize = inArray1.size();
                if (arraySize != inArray2.size() || arraySize < 2 || arraySize > 3)
                {
                    THROW_INVALID_ARGUMENT_ERROR(
                        "incompatible dimensions for cross product (dimension must be 2 or 3)");
                }

                NdArray<dtype> in1 = inArray1.flatten();
                NdArray<dtype> in2 = inArray2.flatten();

                switch (arraySize)
                {
                    case 2:
                    {
                        NdArray<dtype> returnArray = { in1[0] * in2[1] - in1[1] * in2[0] };
                        return returnArray;
                    }
                    case 3:
                    {
                        dtype i = in1[1] * in2[2] - in1[2] * in2[1];
                        dtype j = -(in1[0] * in2[2] - in1[2] * in2[0]);
                        dtype k = in1[0] * in2[1] - in1[1] * in2[0];

                        NdArray<dtype> returnArray = { i, j, k };
                        return returnArray;
                    }
                    default:
                    {
                        THROW_INVALID_ARGUMENT_ERROR("Unimplemented array size.");
                        return {}; // get rid of compiler warning
                    }
                }
            }
            case Axis::ROW:
            {
                const Shape arrayShape = inArray1.shape();
                if (arrayShape != inArray2.shape() || arrayShape.rows < 2 || arrayShape.rows > 3)
                {
                    THROW_INVALID_ARGUMENT_ERROR(
                        "incompatible dimensions for cross product (dimension must be 2 or 3)");
                }

                Shape returnArrayShape;
                returnArrayShape.cols = arrayShape.cols;
                if (arrayShape.rows == 2)
                {
                    returnArrayShape.rows = 1;
                }
                else
                {
                    returnArrayShape.rows = 3;
                }

                NdArray<dtype> returnArray(returnArrayShape);
                for (uint32 col = 0; col < arrayShape.cols; ++col)
                {
                    const auto     theCol   = static_cast<int32>(col);
                    NdArray<dtype> vec1     = inArray1(inArray1.rSlice(), { theCol, theCol + 1 });
                    NdArray<dtype> vec2     = inArray2(inArray2.rSlice(), { theCol, theCol + 1 });
                    NdArray<dtype> vecCross = cross(vec1, vec2, Axis::NONE);

                    returnArray.put({ 0, static_cast<int32>(returnArrayShape.rows) }, { theCol, theCol + 1 }, vecCross);
                }

                return returnArray;
            }
            case Axis::COL:
            {
                const Shape arrayShape = inArray1.shape();
                if (arrayShape != inArray2.shape() || arrayShape.cols < 2 || arrayShape.cols > 3)
                {
                    THROW_INVALID_ARGUMENT_ERROR(
                        "incompatible dimensions for cross product (dimension must be 2 or 3)");
                }

                Shape returnArrayShape;
                returnArrayShape.rows = arrayShape.rows;
                if (arrayShape.cols == 2)
                {
                    returnArrayShape.cols = 1;
                }
                else
                {
                    returnArrayShape.cols = 3;
                }

                NdArray<dtype> returnArray(returnArrayShape);
                for (uint32 row = 0; row < arrayShape.rows; ++row)
                {
                    const auto     theRow   = static_cast<int32>(row);
                    NdArray<dtype> vec1     = inArray1({ theRow, theRow + 1 }, inArray1.cSlice());
                    NdArray<dtype> vec2     = inArray2({ theRow, theRow + 1 }, inArray2.cSlice());
                    NdArray<dtype> vecCross = cross(vec1, vec2, Axis::NONE);

                    returnArray.put({ theRow, theRow + 1 }, { 0, static_cast<int32>(returnArrayShape.cols) }, vecCross);
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
