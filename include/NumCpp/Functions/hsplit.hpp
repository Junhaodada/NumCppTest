
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <vector>

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Functions/unique.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Split an array into multiple sub-arrays horizontal (column-wise).
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.hsplit.html
    ///
    /// @param inArray
    /// @param indices: the indices to split
    ///
    /// @return NdArray
    ///
    template<typename dtype, typename Indices, type_traits::ndarray_int_concept<Indices> = 0>
    std::vector<NdArray<dtype>> hsplit(const NdArray<dtype>& inArray, const Indices& indices)
    {
        const auto     numCols = static_cast<int32>(inArray.numCols());
        NdArray<int32> uniqueIndices(1, indices.size());
        stl_algorithms::transform(indices.begin(),
                                  indices.end(),
                                  uniqueIndices.begin(),
                                  [numCols](auto index) noexcept -> int32
                                  {
                                      if constexpr (type_traits::is_ndarray_signed_int_v<Indices>)
                                      {
                                          if (index < 0)
                                          {
                                              index = std::max(index + numCols, int32{ 0 });
                                          }
                                      }
                                      if (static_cast<int32>(index) > numCols - 1)
                                      {
                                          index = numCols - 1;
                                      }

                                      return static_cast<int32>(index);
                                  });
        uniqueIndices = unique(uniqueIndices);

        std::vector<NdArray<dtype>> splits{};
        splits.reserve(uniqueIndices.size() + 1);

        const auto rSlice   = inArray.rSlice();
        int32      lowerIdx = 0;
        for (const auto index : uniqueIndices)
        {
            if (index == 0)

            {
                splits.push_back(NdArray<dtype>(Shape(inArray.numRows(), 0)));
                continue;
            }
            else
            {
                splits.push_back(inArray(rSlice, Slice(lowerIdx, index)));
            }

            lowerIdx = index;
        }

        if (lowerIdx < numCols - 1)
        {
            splits.push_back(inArray(rSlice, Slice(lowerIdx, numCols)));
        }
        else
        {
            splits.push_back(inArray(rSlice, -1));
        }

        return splits;
    }
} // namespace nc
