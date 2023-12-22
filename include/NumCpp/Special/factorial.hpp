
/// Description
/// Special Functions
///
#pragma once

#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

#ifndef NUMCPP_NO_USE_BOOST
#include "boost/math/special_functions/factorials.hpp"
#endif

#include <limits>

namespace nc::special
{
    //============================================================================
    // Method Description:
    /// Returns the factorial of the input value
    ///
    /// @param inValue
    /// @return double
    ///
    inline double factorial(uint32 inValue)
    {
#ifndef NUMCPP_NO_USE_BOOST
        if (inValue <= boost::math::max_factorial<double>::value)
        {
            return boost::math::factorial<double>(inValue);
        }

        return std::numeric_limits<double>::infinity();
#else
        double result = 1.;
        for (uint32 i = 2; i <= inValue; ++i)
        {
            result *= static_cast<double>(i);
        }

        return result;
#endif
    }

    //============================================================================
    // Method Description:
    /// Returns the factorial of the input value
    ///
    /// @param inArray
    /// @return NdArray<double>
    ///
    inline NdArray<double> factorial(const NdArray<uint32>& inArray)
    {
        NdArray<double> returnArray(inArray.shape());

        stl_algorithms::transform(inArray.cbegin(),
                                  inArray.cend(),
                                  returnArray.begin(),
                                  [](uint32 inValue) -> double { return factorial(inValue); });

        return returnArray;
    }
} // namespace nc::special
