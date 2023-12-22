
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>

#include "NumCpp/Functions/unique.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return the indices of the bins to which each value in input array belongs.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.digitize.html
    ///
    /// @param x: Input array to be binned.
    /// @param bins: Array of bins.
    ///
    /// @return NdArray
    ///
    template<typename dtype1, typename dtype2>
    NdArray<uint32> digitize(const NdArray<dtype1>& x, const NdArray<dtype2>& bins)
    {
        const auto uniqueBins = unique(bins);
        auto       result     = NdArray<uint32>(1, x.size());
        result.fill(0);

        typename decltype(result)::size_type idx{ 0 };
        std::for_each(x.begin(),
                      x.end(),
                      [&uniqueBins, &result, &idx](const auto value)
                      {
                          const auto upperBin = std::upper_bound(uniqueBins.begin(), uniqueBins.end(), value);
                          result[idx++]       = static_cast<uint32>(std::distance(uniqueBins.begin(), upperBin));
                      });

        return result;
    }
} // namespace nc
