
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <cmath>
#include <complex>
#include <string>

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Shape.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/argmin.hpp"
#include "NumCpp/Functions/clip.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the qth percentile of the data along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.percentile.html
    ///
    /// @param inArray
    /// @param inPercentile: percentile must be in the range [0, 100]
    /// @param inAxis (Optional, default NONE)
    /// @param inInterpMethod (Optional) interpolation method
    /// linear: i + (j - i) * fraction, where fraction is the fractional part of the index surrounded by i and j.
    /// lower : i.
    /// higher : j.
    /// nearest : i or j, whichever is nearest.
    /// midpoint : (i + j) / 2.
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> percentile(const NdArray<dtype>& inArray,
                               double                inPercentile,
                               Axis                  inAxis         = Axis::NONE,
                               InterpolationMethod   inInterpMethod = InterpolationMethod::LINEAR)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inPercentile < 0. || inPercentile > 100.)
        {
            THROW_INVALID_ARGUMENT_ERROR("input percentile value must be of the range [0, 100].");
        }

        if (inArray.isempty())
        {
            return {};
        }
        else if (inArray.isscalar())
        {
            NdArray<double> returnArray = { static_cast<double>(inArray.front()) };
            return returnArray;
        }

        switch (inAxis)
        {
            case Axis::NONE:
            {
                NdArray<double> arrayCopy = inArray.template astype<double>();
                stl_algorithms::sort(arrayCopy.begin(), arrayCopy.end());

                if (utils::essentiallyEqual(inPercentile, 0.))
                {
                    NdArray<double> returnArray = { arrayCopy.front() };
                    return returnArray;
                }
                if (utils::essentiallyEqual(inPercentile, 100.))
                {
                    NdArray<double> returnArray = { arrayCopy.back() };
                    return returnArray;
                }

                const auto i =
                    static_cast<uint32>(std::floor(static_cast<double>(inArray.size() - 1) * inPercentile / 100.));
                const auto indexLower = clip<uint32>(i, 0, inArray.size() - 2);

                switch (inInterpMethod)
                {
                    case InterpolationMethod::LINEAR:
                    {
                        const double percentI =
                            static_cast<double>(indexLower) / static_cast<double>(inArray.size() - 1);
                        const double fraction =
                            (inPercentile / 100. - percentI) /
                            (static_cast<double>(indexLower + 1) / static_cast<double>(inArray.size() - 1) - percentI);

                        NdArray<double> returnArray = {
                            arrayCopy[indexLower] + (arrayCopy[indexLower + 1] - arrayCopy[indexLower]) * fraction
                        };
                        return returnArray;
                    }
                    case InterpolationMethod::LOWER:
                    {
                        NdArray<double> returnArray = { arrayCopy[indexLower] };
                        return returnArray;
                    }
                    case InterpolationMethod::HIGHER:
                    {
                        NdArray<double> returnArray = { arrayCopy[indexLower + 1] };
                        return returnArray;
                    }
                    case InterpolationMethod::NEAREST:
                    {
                        const double percent = inPercentile / 100.;
                        const double percent1 =
                            static_cast<double>(indexLower) / static_cast<double>(inArray.size() - 1);
                        const double percent2 =
                            static_cast<double>(indexLower + 1) / static_cast<double>(inArray.size() - 1);
                        const double diff1 = percent - percent1;
                        const double diff2 = percent2 - percent;

                        switch (argmin<double>({ diff1, diff2 }).item())
                        {
                            case 0:
                            {
                                NdArray<double> returnArray = { arrayCopy[indexLower] };
                                return returnArray;
                            }
                            case 1:
                            {
                                NdArray<double> returnArray = { arrayCopy[indexLower + 1] };
                                return returnArray;
                            }
                        }

                        return {}; // get rid of compiler warning
                    }
                    case InterpolationMethod::MIDPOINT:
                    {
                        NdArray<double> returnArray = { (arrayCopy[indexLower] + arrayCopy[indexLower + 1]) / 2. };
                        return returnArray;
                    }
                    default:
                    {
                        THROW_INVALID_ARGUMENT_ERROR("Unimplemented Interpolation method.");
                        return {}; // get rid of compiler warning
                    }
                }
            }
            case Axis::COL:
            {
                const Shape inShape = inArray.shape();

                NdArray<double> returnArray(1, inShape.rows);
                for (uint32 row = 0; row < inShape.rows; ++row)
                {
                    returnArray[row] =
                        percentile(NdArray<dtype>(const_cast<typename NdArray<dtype>::pointer>(&inArray.front(row)),
                                                  inShape.cols,
                                                  PointerPolicy::SHELL),
                                   inPercentile,
                                   Axis::NONE,
                                   inInterpMethod)
                            .item();
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return percentile(inArray.transpose(), inPercentile, Axis::COL, inInterpMethod);
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
