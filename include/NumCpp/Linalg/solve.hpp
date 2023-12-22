
/// Description
/// matrix svd
///
#pragma once

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/dot.hpp"
#include "NumCpp/Linalg/inv.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::linalg
{
    //============================================================================
    // Method Description:
    /// Solve a linear matrix equation, or system of linear scalar equations.
    /// Computes the “exact” solution, x, of the well-determined, i.e., full rank,
    /// linear matrix equation ax = b.
    ///
    /// https://numpy.org/doc/stable/reference/generated/numpy.linalg.solve.html
    ///
    /// @param inA
    /// @param inB
    /// @return NdArray<double> Solution to the system a x = b. Returned shape is identical to b
    ///
    template<typename dtype>
    NdArray<double> solve(const NdArray<dtype>& inA, const NdArray<dtype>& inB)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (!inA.issquare())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array a must be square.");
        }

        if (!inB.isflat())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array b must be flat.");
        }

        if (inA.numCols() != inB.size())
        {
            THROW_INVALID_ARGUMENT_ERROR("input array b size must be the same as the square size of a.");
        }

        return dot(inv(inA), inB.template astype<double>().reshape(inB.size(), 1)).reshape(inB.shape());
    }
} // namespace nc::linalg
