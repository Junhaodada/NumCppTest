
/// Description
/// Generates a threshold
///

#pragma once

#include <cmath>
#include <string>

#include "NumCpp/Core/DtypeInfo.hpp"
#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/essentiallyEqual.hpp"

namespace nc::imageProcessing
{
    //============================================================================
    // Method Description:
    /// Calculates a threshold such that the input rate of pixels
    /// exceeds the threshold. Really should only be used for integer
    /// input array values. If using floating point data, user beware...
    ///
    /// @param inImageArray
    /// @param inRate
    /// @return dtype
    ///
    template<typename dtype>
    dtype generateThreshold(const NdArray<dtype>& inImageArray, double inRate)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inRate < 0. || inRate > 1.)
        {
            THROW_INVALID_ARGUMENT_ERROR("input rate must be of the range [0, 1]");
        }

        // first build a histogram
        auto minValue = static_cast<int32>(std::floor(inImageArray.min().item()));
        auto maxValue = static_cast<int32>(std::floor(inImageArray.max().item()));

        if (utils::essentiallyEqual(inRate, 0.))
        {
            return static_cast<dtype>(maxValue);
        }

        if (utils::essentiallyEqual(inRate, 1.))
        {
            if (DtypeInfo<dtype>::isSigned())
            {
                return static_cast<dtype>(minValue - 1);
            }

            return dtype{ 0 };
        }

        const auto histSize = static_cast<uint32>(maxValue - minValue + 1);

        NdArray<double> histogram(1, histSize);
        histogram.zeros();
        for (auto intensity : inImageArray)
        {
            const auto bin = static_cast<uint32>(static_cast<int32>(std::floor(intensity)) - minValue);
            ++histogram[bin];
        }

        // integrate the normalized histogram from right to left to make a survival function (1 - CDF)
        const auto      dNumPixels = static_cast<double>(inImageArray.size());
        NdArray<double> survivalFunction(1, histSize + 1);
        survivalFunction[-1] = 0.;
        for (int32 i = histSize - 1; i > -1; --i)
        {
            double histValue    = histogram[i] / dNumPixels;
            survivalFunction[i] = survivalFunction[i + 1] + histValue;
        }

        // binary search through the survival function to find the rate
        uint32 indexLow  = 0;
        uint32 indexHigh = histSize - 1;
        uint32 index     = indexHigh / 2; // integer division

        constexpr bool keepGoing = true;
        while (keepGoing)
        {
            const double value = survivalFunction[index];
            if (value < inRate)
            {
                indexHigh = index;
            }
            else if (value > inRate)
            {
                indexLow = index;
            }
            else
            {
                const int32 thresh = static_cast<int32>(index) + minValue - 1;
                if (DtypeInfo<dtype>::isSigned())
                {
                    return static_cast<dtype>(thresh);
                }

                return thresh < 0 ? 0 : static_cast<dtype>(thresh);
            }

            if (indexHigh - indexLow < 2)
            {
                return static_cast<dtype>(static_cast<int32>(indexHigh) + minValue - 1);
            }

            index = indexLow + (indexHigh - indexLow) / 2;
        }

        // shouldn't ever get here but stop the compiler from throwing a warning
        return static_cast<dtype>(histSize - 1);
    }

} // namespace nc::imageProcessing
