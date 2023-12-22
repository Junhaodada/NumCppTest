
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/argmin.hpp"
#include "NumCpp/Functions/clip.hpp"
#include "NumCpp/Functions/isnan.hpp"
#include "NumCpp/Functions/percentile.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the qth percentile of the data along the specified axis, while ignoring nan values.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.nanpercentile.html
    ///
    /// @param inArray
    /// @param inPercentile
    /// @param inAxis (Optional, default NONE)
    /// @param inInterpMethod (default linear) choices = ['linear','lower','higher','nearest','midpoint']
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> nanpercentile(const NdArray<dtype>& inArray,
                                  double                inPercentile,
                                  Axis                  inAxis         = Axis::NONE,
                                  InterpolationMethod   inInterpMethod = InterpolationMethod::LINEAR)
    {
        STATIC_ASSERT_FLOAT(dtype);

        switch (inAxis)
        {
            case Axis::NONE:
            {
                std::vector<double> arrayCopy;
                arrayCopy.reserve(inArray.size());
                for (auto value : inArray)
                {
                    if (!isnan(value))
                    {
                        arrayCopy.push_back(static_cast<double>(value));
                    }
                }

                if (arrayCopy.empty())
                {
                    NdArray<double> returnArray = { constants::nan };
                    return returnArray;
                }

                return percentile(NdArray<double>(arrayCopy.data(),
                                                  static_cast<typename NdArray<dtype>::size_type>(arrayCopy.size()),
                                                  PointerPolicy::SHELL),
                                  inPercentile,
                                  Axis::NONE,
                                  inInterpMethod);
            }
            case Axis::COL:
            {
                const Shape inShape = inArray.shape();

                NdArray<double> returnArray(1, inShape.rows);
                for (uint32 row = 0; row < inShape.rows; ++row)
                {
                    NdArray<double> outValue = nanpercentile(NdArray<dtype>(&inArray.front(row), inShape.cols),
                                                             inPercentile,
                                                             Axis::NONE,
                                                             inInterpMethod);

                    if (outValue.isscalar())
                    {
                        returnArray[row] = outValue.item();
                    }
                    else
                    {
                        returnArray[row] = constants::nan;
                    }
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return nanpercentile(inArray.transpose(), inPercentile, Axis::COL, inInterpMethod);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }

        return {}; // get rid of compiler warning
    }
} // namespace nc
