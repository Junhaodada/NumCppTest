
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>
#include <utility>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/linspace.hpp"
#include "NumCpp/Functions/sort.hpp"
#include "NumCpp/Functions/zeros.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Compute the histogram of a set of data.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.histogram.html
    ///
    ///
    /// @param inArray
    /// @param inBinEdges: monotonically increasing array of bin edges, including the
    /// rightmost edge, allowing for non-uniform bin widths.
    ///
    /// @return array of histogram counts
    ///
    template<typename dtype>
    NdArray<uint32> histogram(const NdArray<dtype>& inArray, const NdArray<double>& inBinEdges)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inBinEdges.size() < 2)
        {
            THROW_INVALID_ARGUMENT_ERROR("number of bin edges must be >= 2.");
        }

        // sort just in case the user hasn't already
        const auto binEdges = sort(inBinEdges);

        NdArray<uint32> histo = zeros<uint32>(1, binEdges.size() - 1);
        for (const auto value : inArray)
        {
            if (value < binEdges.front() || value > binEdges.back())
            {
                continue;
            }

            // binary search to find the bin idx
            constexpr bool keepSearching = true;
            uint32         lowIdx        = 0;
            uint32         highIdx       = binEdges.size() - 1;
            while (keepSearching)
            {
                const uint32 idx = (lowIdx + highIdx) / 2; // integer division
                if (lowIdx == highIdx || lowIdx == highIdx - 1)
                {
                    // we found the bin
                    ++histo[lowIdx];
                    break;
                }

                if (value > binEdges[idx])
                {
                    lowIdx = idx;
                }
                else if (value < binEdges[idx])
                {
                    highIdx = idx;
                }
                else
                {
                    // we found the bin
                    ++histo[idx];
                    break;
                }
            }
        }

        return histo;
    }

    //============================================================================
    // Method Description:
    /// Compute the histogram of a set of data.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.histogram.html
    ///
    ///
    /// @param inArray
    /// @param inNumBins( default 10)
    ///
    /// @return std::pair of NdArrays; first is histogram counts, seconds is the bin edges
    ///
    template<typename dtype>
    std::pair<NdArray<uint32>, NdArray<double>> histogram(const NdArray<dtype>& inArray, uint32 inNumBins = 10)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inNumBins == 0)
        {
            THROW_INVALID_ARGUMENT_ERROR("number of bins must be positive.");
        }

        const NdArray<double> binEdges = linspace(static_cast<double>(inArray.min().item()),
                                                  static_cast<double>(inArray.max().item()),
                                                  inNumBins + 1,
                                                  EndPoint::YES);

        const auto histo = histogram(inArray, binEdges);
        return std::make_pair(histo, binEdges);
    }
} // namespace nc
