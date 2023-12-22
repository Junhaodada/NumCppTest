
/// Description
/// A Class for slicing into NdArrays
///

#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Utils/num2str.hpp"

namespace nc
{
    //================================================================================
    /// A Class for slicing into NdArrays
    class Slice
    {
    public:
        //====================================Attributes==============================
        int32 start{ 0 };
        int32 stop{ 1 };
        int32 step{ 1 };

        //============================================================================
        /// Constructor
        ///
        constexpr Slice() = default;

        //============================================================================
        /// Constructor
        ///
        /// @param inStop (index not included)
        ///
        constexpr explicit Slice(int32 inStop) noexcept :
            stop(inStop)
        {
        }

        //============================================================================
        /// Constructor
        ///
        /// @param inStart
        /// @param inStop (index not included)
        ///
        constexpr Slice(int32 inStart, int32 inStop) noexcept :
            start(inStart),
            stop(inStop)
        {
        }

        //============================================================================
        /// Constructor
        ///
        /// @param inStart
        /// @param inStop (not included)
        /// @param inStep
        ///
        constexpr Slice(int32 inStart, int32 inStop, int32 inStep) noexcept :
            start(inStart),
            stop(inStop),
            step(inStep)
        {
        }

        //============================================================================
        /// Equality operator
        ///
        /// @param inOtherSlice
        ///
        /// @return bool
        ///
        bool operator==(const Slice& inOtherSlice) const noexcept
        {
            return start == inOtherSlice.start && stop == inOtherSlice.stop && step == inOtherSlice.step;
        }

        //============================================================================
        /// Not equality operator
        ///
        /// @param inOtherSlice
        ///
        /// @return bool
        ///
        bool operator!=(const Slice& inOtherSlice) const noexcept
        {
            return !(*this == inOtherSlice);
        }

        //============================================================================
        /// Prints the shape to the console
        ///
        /// @return std::string
        ///
        [[nodiscard]] std::string str() const
        {
            std::string out =
                "[" + utils::num2str(start) + ":" + utils::num2str(stop) + ":" + utils::num2str(step) + "]\n";
            return out;
        }

        //============================================================================
        /// Prints the shape to the console
        ///
        void print() const
        {
            std::cout << *this;
        }

        //============================================================================
        /// Make the slice all positive and does some error checking
        ///
        /// @param inArraySize
        ///
        void makePositiveAndValidate(uint32 inArraySize)
        {
            /// convert the start value
            if (start < 0)
            {
                start += static_cast<int32>(inArraySize);
            }
            if (start > static_cast<int32>(inArraySize - 1))
            {
                THROW_INVALID_ARGUMENT_ERROR("Invalid start value for array of size " + utils::num2str(inArraySize));
            }

            /// convert the stop value
            if (stop < 0)
            {
                stop += static_cast<int32>(inArraySize);
            }
            if (stop > static_cast<int32>(inArraySize))
            {
                THROW_INVALID_ARGUMENT_ERROR("Invalid stop value for array of size " + utils::num2str(inArraySize));
            }

            /// do some error checking
            if (start < stop)
            {
                if (step < 0)
                {
                    THROW_INVALID_ARGUMENT_ERROR("Invalid slice values [" + utils::num2str(start) + ", " +
                                                 utils::num2str(stop) + ", " + utils::num2str(step) + ']');
                }
            }

            if (stop < start)
            {
                if (step > 0)
                {
                    THROW_INVALID_ARGUMENT_ERROR("Invalid slice values [" + utils::num2str(start) + ", " +
                                                 utils::num2str(stop) + ", " + utils::num2str(step) + ']');
                }

                /// otherwise flip things around for my own sanity
                std::swap(start, stop);
                step *= -1;
            }
        }

        //============================================================================
        /// Returns the number of elements that the slice contains.
        /// be aware that this method will also make the slice all
        /// positive!
        ///
        /// @param inArraySize
        ///
        uint32 numElements(uint32 inArraySize)
        {
            makePositiveAndValidate(inArraySize);

            uint32 num = 0;
            for (int32 i = start; i < stop; i += step)
            {
                ++num;
            }
            return num;
        }

        //============================================================================
        /// Returns the indices that coorespond to the slice
        /// be aware that this method will also make the slice all
        /// positive!
        ///
        /// @param inArrayDimSize: the size of the dimension that is being sliced
        ///
        std::vector<uint32> toIndices(uint32 inArrayDimSize)
        {
            std::vector<uint32> indices;
            indices.reserve(numElements(inArrayDimSize));
            for (int32 i = start; i < stop; i += step)
            {
                indices.push_back(static_cast<uint32>(i));
            }
            return indices;
        }

        //============================================================================
        /// IO operator for the Slice class
        ///
        /// @param inOStream
        /// @param inSlice
        ///
        /// @return std::ostream
        ///
        friend std::ostream& operator<<(std::ostream& inOStream, const Slice& inSlice)
        {
            inOStream << inSlice.str();
            return inOStream;
        }
    };
} // namespace nc
