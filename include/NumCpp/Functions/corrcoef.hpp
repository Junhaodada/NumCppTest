
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/cov.hpp"
#include "NumCpp/Functions/empty_like.hpp"
#include "NumCpp/Functions/sqrt.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Return Pearson product-moment correlation coefficients.
    ///
    /// NumPy Reference: https://numpy.org/doc/stable/reference/generated/numpy.corrcoef.html
    ///
    /// @param x: A 1-D or 2-D array containing multiple variables and observations.
    /// Each row of x represents a variable, and each column a single observation
    /// of all those variables.
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> corrcoef(const NdArray<dtype>& x)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        const auto covariance           = cov(x);
        auto       normalizedCovariance = empty_like(covariance);
        for (decltype(covariance.numRows()) i = 0; i < covariance.numRows(); ++i)
        {
            for (decltype(covariance.numCols()) j = 0; j < covariance.numCols(); ++j)
            {
                normalizedCovariance(i, j) = covariance(i, j) / sqrt(covariance(i, i) * covariance(j, j));
            }
        }

        return normalizedCovariance;
    }
} // namespace nc
