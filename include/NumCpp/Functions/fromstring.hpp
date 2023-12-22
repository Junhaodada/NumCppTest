
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <sstream>
#include <string_view>

#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Construct an array from data in a string
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.fromstring.html
    ///
    /// @param inStr
    /// @param inSep: Delimiter separator between values in the string
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> fromstring(const std::string& inStr, const char inSep = ' ')
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        std::istringstream inputStream(inStr);
        auto               values = std::vector<dtype>{};
        dtype              value{};
        for (std::string segment; std::getline(inputStream, segment, inSep);)
        {
            if (!inputStream.fail())
            {
                std::istringstream segmentStream(segment);
                while (segmentStream >> value)
                {
                    if (!inputStream.fail())
                    {
                        values.push_back(value);
                    }
                }
            }
        }

        return NdArray<dtype>(values);
    }
} // namespace nc
