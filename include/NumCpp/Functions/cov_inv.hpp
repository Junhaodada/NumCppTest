
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/Enums.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/cov.hpp"
#include "NumCpp/Linalg/inv.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Estimate an inverse covariance matrix, aka the concentration matrix
    ///
    /// @param x: A 1-D or 2-D array containing multiple variables and observations.
    /// Each row of x represents a variable, and each column a single observation
    /// of all those variables.
    /// @param bias: Default normalization (false) is by (N - 1), where N is the number of observations
    /// given (unbiased estimate). If bias is True, then normalization is by N.
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<double> cov_inv(const NdArray<dtype>& x, Bias bias = Bias::NO)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        return linalg::inv(cov(x, bias));
    }
} // namespace nc
