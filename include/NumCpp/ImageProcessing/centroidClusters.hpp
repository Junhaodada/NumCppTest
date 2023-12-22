
/// Description
/// Center of Mass centroids clusters
///

#pragma once

#include <utility>
#include <vector>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/ImageProcessing/Centroid.hpp"
#include "NumCpp/ImageProcessing/Cluster.hpp"

namespace nc::imageProcessing
{
    //============================================================================
    // Method Description:
    /// Center of Mass centroids clusters
    ///
    /// @param inClusters
    /// @return std::vector<Centroid>
    ///
    template<typename dtype>
    std::vector<Centroid<dtype>> centroidClusters(const std::vector<Cluster<dtype>>& inClusters)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        std::vector<Centroid<dtype>> centroids(inClusters.size());
        stl_algorithms::transform(inClusters.begin(),
                                  inClusters.end(),
                                  centroids.begin(),
                                  [](const auto& cluster) -> Centroid<dtype> { return Centroid<dtype>(cluster); });
        return centroids;
    }
} // namespace nc::imageProcessing
