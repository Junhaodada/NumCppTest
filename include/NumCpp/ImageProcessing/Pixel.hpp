
/// Description
/// Holds the information for a single pixel
///

#pragma once

#include <iostream>
#include <string>

#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Utils/essentiallyEqual.hpp"
#include "NumCpp/Utils/num2str.hpp"

namespace nc::imageProcessing
{
    //================================================================================
    // Class Description:
    /// Holds the information for a single pixel
    template<typename dtype>
    class Pixel
    {
    private:
        STATIC_ASSERT_ARITHMETIC(dtype);

    public:
        //==================================Attributes================================
        mutable int32 clusterId{ -1 };
        uint32        row{ 0 };
        uint32        col{ 0 };
        dtype         intensity{ 0 };

        //=============================================================================
        // Description:
        /// defualt constructor needed by containers
        ///
        constexpr Pixel() = default;

        //=============================================================================
        // Description:
        /// constructor
        ///
        /// @param inRow: pixel row
        /// @param inCol: pixel column
        /// @param inIntensity: pixel intensity
        ///
        constexpr Pixel(uint32 inRow, uint32 inCol, dtype inIntensity) noexcept :
            row(inRow),
            col(inCol),
            intensity(inIntensity)
        {
        }

        //=============================================================================
        // Description:
        /// equality operator
        ///
        /// @param rhs
        ///
        /// @return bool
        ///
        constexpr bool operator==(const Pixel<dtype>& rhs) const noexcept
        {
            return utils::essentiallyEqual(row, rhs.row) && utils::essentiallyEqual(col, rhs.col) &&
                   utils::essentiallyEqual(intensity, rhs.intensity);
        }

        //=============================================================================
        // Description:
        /// not equality operator
        ///
        /// @param rhs
        ///
        /// @return bool
        ///
        constexpr bool operator!=(const Pixel<dtype>& rhs) const noexcept
        {
            return !(*this == rhs);
        }

        //=============================================================================
        // Description:
        /// less than operator for std::sort algorithm and std::set<>;
        /// NOTE: std::sort sorts in ascending order. Since I want to sort
        /// the centroids in descensing order, I am purposefully defining
        /// this operator backwards!
        ///
        /// @param rhs
        ///
        /// @return bool
        ///
        bool operator<(const Pixel<dtype>& rhs) const noexcept
        {
            if (row < rhs.row)
            {
                return true;
            }
            if (row == rhs.row)
            {
                return static_cast<bool>(col < rhs.col);
            }

            return false;
        }

        //=============================================================================
        // Description:
        /// returns the pixel information as a string
        ///
        /// @return std::string
        ///
        [[nodiscard]] std::string str() const
        {
            std::string out = "row = " + utils::num2str(row) + " col = " + utils::num2str(col);
            out += " intensity = " + utils::num2str(intensity) + '\n';
            return out;
        }

        //============================================================================
        /// Method Description:
        /// prints the Pixel object to the console
        ///
        void print() const
        {
            std::cout << *this;
        }

        //=============================================================================
        // Description:
        /// osstream operator
        ///
        /// @param inStream
        /// @param inPixel
        /// @return std::ostream
        ///
        friend std::ostream& operator<<(std::ostream& inStream, const Pixel<dtype>& inPixel)
        {
            inStream << inPixel.str();
            return inStream;
        }
    };
} // namespace nc::imageProcessing
