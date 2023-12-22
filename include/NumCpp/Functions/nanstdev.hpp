
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <cmath>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/nanmean.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the standard deviation along the specified axis, while ignoring NaNs.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.nanstd.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> nanstdev(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_FLOAT(dtype);

        switch (inAxis)
        {
            case Axis::NONE:
            {
                double meanValue = nanmean(inArray, inAxis).item();
                double sum       = 0;
                double counter   = 0;
                for (auto value : inArray)
                {
                    if (std::isnan(value))
                    {
                        continue;
                    }

                    sum += utils::sqr(static_cast<double>(value) - meanValue);
                    ++counter;
                }
                NdArray<double> returnArray = { std::sqrt(sum / counter) };
                return returnArray;
            }
            case Axis::COL:
            {
                const Shape     inShape   = inArray.shape();
                NdArray<double> meanValue = nanmean(inArray, inAxis);
                NdArray<double> returnArray(1, inShape.rows);
                for (uint32 row = 0; row < inShape.rows; ++row)
                {
                    double sum     = 0;
                    double counter = 0;
                    for (uint32 col = 0; col < inShape.cols; ++col)
                    {
                        if (std::isnan(inArray(row, col)))
                        {
                            continue;
                        }

                        sum += utils::sqr(static_cast<double>(inArray(row, col)) - meanValue[row]);
                        ++counter;
                    }
                    returnArray(0, row) = std::sqrt(sum / counter);
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return nanstdev(inArray.transpose(), Axis::COL);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }

} // namespace nc
