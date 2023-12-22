
/// Description
/// Clusters exceedance pixels from an image
///

#pragma once

#include <vector>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/ImageProcessing/Cluster.hpp"
#include "NumCpp/ImageProcessing/ClusterMaker.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::imageProcessing
{
    //============================================================================
    // Method Description:
    /// Clusters exceedance pixels from an image
    ///
    /// @param inImageArray
    /// @param inExceedances
    /// @param inBorderWidth: border to apply around exceedance pixels post clustering (default 0)
    /// @return std::vector<Cluster>
    ///
    template<typename dtype>
    std::vector<Cluster<dtype>>
        clusterPixels(const NdArray<dtype>& inImageArray, const NdArray<bool>& inExceedances, uint8 inBorderWidth = 0)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        ClusterMaker<dtype> clusterMaker(&inExceedances, &inImageArray, inBorderWidth);
        return std::vector<Cluster<dtype>>(clusterMaker.begin(), clusterMaker.end());
    }
} // namespace nc::imageProcessing
