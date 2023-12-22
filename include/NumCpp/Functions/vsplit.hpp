
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <vector>

#include "NumCpp/Functions/split.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Split an array into multiple sub-arrays vertically (row-wise).
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.vsplit.html
    ///
    /// @param inArray
    /// @param indices: the indices to split
    ///
    /// @return NdArray
    ///
    template<typename dtype, typename Indices, type_traits::ndarray_int_concept<Indices> = 0>
    std::vector<NdArray<dtype>> vsplit(const NdArray<dtype>& inArray, const Indices& indices)
    {
        const auto     numRows = static_cast<int32>(inArray.numRows());
        NdArray<int32> uniqueIndices(1, indices.size());
        stl_algorithms::transform(indices.begin(),
                                  indices.end(),
                                  uniqueIndices.begin(),
                                  [numRows](auto index) noexcept -> int32
                                  {
                                      if constexpr (type_traits::is_ndarray_signed_int_v<Indices>)
                                      {
                                          if (index < 0)
                                          {
                                              index = std::max(index + numRows, int32{ 0 });
                                          }
                                      }
                                      if (index > numRows - 1)
                                      {
                                          index = numRows - 1;
                                      }

                                      return static_cast<int32>(index);
                                  });
        uniqueIndices = unique(uniqueIndices);

        std::vector<NdArray<dtype>> splits{};
        splits.reserve(uniqueIndices.size() + 1);

        const auto cSlice   = inArray.cSlice();
        int32      lowerIdx = 0;
        for (const auto index : uniqueIndices)
        {
            if (index == 0)
            {
                splits.push_back(NdArray<dtype>(Shape(0, inArray.numCols())));
                continue;
            }
            else
            {
                splits.push_back(inArray(Slice(lowerIdx, index), cSlice));
            }

            lowerIdx = index;
        }

        if (lowerIdx < numRows - 1)
        {
            splits.push_back(inArray(Slice(lowerIdx, numRows), cSlice));
        }
        else
        {
            splits.push_back(inArray(-1, cSlice));
        }

        return splits;
    }
} // namespace nc
