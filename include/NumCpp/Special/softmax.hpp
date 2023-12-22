
/// Description
/// Special Functions
///
#pragma once

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/exp.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// The softmax function transforms each element of a collection by computing
    /// the exponential of each element divided by the sum of the exponentials of all
    /// the elements. That is, if x is a one-dimensional numpy array:
    /// softmax(x) = np.exp(x)/sum(np.exp(x))
    ///
    /// @param inArray
    /// @param inAxis (Optional, default NONE)
    /// @return NdArray<double>
    ///
    template<typename dtype>
    NdArray<double> softmax(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        switch (inAxis)
        {
            case Axis::NONE:
            {
                auto returnArray = exp(inArray).template astype<double>();
                returnArray /= static_cast<double>(returnArray.sum().item());
                return returnArray;
            }
            case Axis::COL:
            {
                auto returnArray = exp(inArray).template astype<double>();
                auto expSums     = returnArray.sum(inAxis);

                for (uint32 row = 0; row < returnArray.shape().rows; ++row)
                {
                    const auto rowExpSum = static_cast<double>(expSums[row]);
                    stl_algorithms::for_each(returnArray.begin(row),
                                             returnArray.end(row),
                                             [rowExpSum](double& value) { value /= rowExpSum; });
                }

                return returnArray;
            }
            case Axis::ROW:
            {
                auto returnArray = exp(inArray.transpose()).template astype<double>();
                auto expSums     = returnArray.sum(Axis::COL);

                for (uint32 row = 0; row < returnArray.shape().rows; ++row)
                {
                    const auto rowExpSum = static_cast<double>(expSums[row]);
                    stl_algorithms::for_each(returnArray.begin(row),
                                             returnArray.end(row),
                                             [rowExpSum](double& value) { value /= rowExpSum; });
                }

                return returnArray.transpose();
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc::special
