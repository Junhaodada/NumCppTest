
/// Description
/// Functions for working with NdArrays
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Internal/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc
{
    //============================================================================
    // Method Description:
    /// Trim the leading and/or trailing zeros from a 1-D array or sequence.
    ///
    /// NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.trim_zeros.html
    ///
    /// @param inArray
    /// @param inTrim: ("f" = front, "b" = back, "fb" = front and back)
    ///
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> trim_zeros(const NdArray<dtype>& inArray, const std::string& inTrim = "fb")
    {
        STATIC_ASSERT_ARITHMETIC_OR_COMPLEX(dtype);

        if (inTrim == "f")
        {
            uint32 place = 0;
            for (auto value : inArray)
            {
                if (!utils::essentiallyEqual(value, dtype{ 0 }))
                {
                    break;
                }

                ++place;
            }

            if (place == inArray.size())
            {
                return NdArray<dtype>(0);
            }

            NdArray<dtype> returnArray(1, inArray.size() - place);
            stl_algorithms::copy(inArray.cbegin() + place, inArray.cend(), returnArray.begin());

            return returnArray;
        }

        if (inTrim == "b")
        {
            uint32 place = inArray.size();
            for (uint32 i = inArray.size() - 1; i > 0; --i)
            {
                if (!utils::essentiallyEqual(inArray[i], dtype{ 0 }))
                {
                    break;
                }

                --place;
            }

            if (place == 0 || (place == 1 && utils::essentiallyEqual(inArray[0], dtype{ 0 })))
            {
                return NdArray<dtype>(0);
            }

            NdArray<dtype> returnArray(1, place);
            stl_algorithms::copy(inArray.cbegin(), inArray.cbegin() + place, returnArray.begin());

            return returnArray;
        }

        if (inTrim == "fb")
        {
            uint32 placeBegin = 0;
            for (auto value : inArray)
            {
                if (!utils::essentiallyEqual(value, dtype{ 0 }))
                {
                    break;
                }

                ++placeBegin;
            }

            if (placeBegin == inArray.size())
            {
                return NdArray<dtype>(0);
            }

            uint32 placeEnd = inArray.size();
            for (uint32 i = inArray.size() - 1; i > 0; --i)
            {
                if (!utils::essentiallyEqual(inArray[i], dtype{ 0 }))
                {
                    break;
                }

                --placeEnd;
            }

            if (placeEnd == 0 || (placeEnd == 1 && utils::essentiallyEqual(inArray[0], dtype{ 0 })))
            {
                return NdArray<dtype>(0);
            }

            NdArray<dtype> returnArray(1, placeEnd - placeBegin);
            stl_algorithms::copy(inArray.cbegin() + placeBegin, inArray.cbegin() + placeEnd, returnArray.begin());

            return returnArray;
        }

        THROW_INVALID_ARGUMENT_ERROR("trim options are 'f' = front, 'b' = back, 'fb' = front and back.");
        return {};
    }
} // namespace nc
