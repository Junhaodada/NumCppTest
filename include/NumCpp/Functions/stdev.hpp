
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <cmath>
#include <complex>

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/mean.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/sqr.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the standard deviation along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.std.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> stdev(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        double meanValue = 0.;
        double sum       = 0.;

        const auto function = [&sum, &meanValue](dtype value) -> void
        { sum += utils::sqr(static_cast<double>(value) - meanValue); };

        switch (inAxis)
        {
            case Axis::NONE:
            {
                meanValue = mean(inArray, inAxis).item();
                std::for_each(inArray.cbegin(), inArray.cend(), function);

                NdArray<double> returnArray = { std::sqrt(sum / inArray.size()) };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<double> meanValueArray = mean(inArray, inAxis);
                NdArray<double> returnArray(1, inArray.numRows());
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    meanValue = meanValueArray[row];
                    sum       = 0.;
                    std::for_each(inArray.cbegin(row), inArray.cend(row), function);

                    returnArray(0, row) = std::sqrt(sum / inArray.numCols());
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                return stdev(inArray.transpose(), Axis::COL);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }

    //============================================================================
    // Method Description:
    /// Compute the standard deviation along the specified axis.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.std.html
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<std::complex<double>> stdev(const NdArray<std::complex<dtype>>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        std::complex<double> meanValue(0., 0.);
        std::complex<double> sum(0., 0.);

        const auto function = [&sum, &meanValue](std::complex<dtype> value) -> void
        { sum += utils::sqr(complex_cast<double>(value) - meanValue); };

        switch (inAxis)
        {
            case Axis::NONE:
            {
                meanValue = mean(inArray, inAxis).item();
                std::for_each(inArray.cbegin(), inArray.cend(), function);

                NdArray<std::complex<double>> returnArray = { std::sqrt(sum / static_cast<double>(inArray.size())) };
                return returnArray;
            }
            case Axis::COL:
            {
                NdArray<std::complex<double>> meanValueArray = mean(inArray, inAxis);
                NdArray<std::complex<double>> returnArray(1, inArray.numRows());
                for (uint32 row = 0; row < inArray.numRows(); ++row)
                {
                    meanValue = meanValueArray[row];
                    sum       = std::complex<double>(0., 0.);
                    std::for_each(inArray.cbegin(row), inArray.cend(row), function);

                    returnArray(0, row) = std::sqrt(sum / static_cast<double>(inArray.numCols()));
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                NdArray<std::complex<double>> meanValueArray  = mean(inArray, inAxis);
                NdArray<std::complex<dtype>>  transposedArray = inArray.transpose();
                NdArray<std::complex<double>> returnArray(1, transposedArray.numRows());
                for (uint32 row = 0; row < transposedArray.numRows(); ++row)
                {
                    meanValue = meanValueArray[row];
                    sum       = std::complex<double>(0., 0.);
                    std::for_each(transposedArray.cbegin(row), transposedArray.cend(row), function);

                    returnArray(0, row) = std::sqrt(sum / static_cast<double>(transposedArray.numCols()));
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
