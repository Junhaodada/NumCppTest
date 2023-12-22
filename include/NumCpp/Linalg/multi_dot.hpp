
/// Description
/// Compute the dot product of two or more arrays in a single function call.
///
#pragma once

#include <initializer_list>
#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Functions/dot.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::linalg
{
    //============================================================================
    // Method Description:
    /// Compute the dot product of two or more arrays in a single
    /// function call.
    ///
    /// NumPy Reference:
    /// https://docs.scipy.org/doc/numpy/reference/generated/numpy.linalg.multi_dot.html#numpy.linalg.multi_dot
    ///
    /// @param inList: list of arrays
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> multi_dot(const std::initializer_list<NdArray<dtype>>& inList)
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        typename std::initializer_list<NdArray<dtype>>::iterator iter = inList.begin();

        if (inList.size() == 0)
        {
            THROW_INVALID_ARGUMENT_ERROR("input empty list of arrays.");
        }
        else if (inList.size() == 1)
        {
            return iter->copy();
        }

        NdArray<dtype> returnArray = dot<dtype>(*iter, *(iter + 1));
        iter += 2;
        for (; iter < inList.end(); ++iter)
        {
            returnArray = dot(returnArray, *iter);
        }

        return returnArray;
    }
} // namespace nc::linalg
