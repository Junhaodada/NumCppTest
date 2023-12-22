
/// Description
/// A Shape Class for NdArrays
///
#pragma once

#include <iostream>
#include <string>

#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Utils/num2str.hpp"

namespace nc
{
    //================================================================================
    /// A Shape Class for NdArrays
    class Shape
    {
    public:
        //====================================Attributes==============================
        uint32 rows{ 0 };
        uint32 cols{ 0 };

        //============================================================================
        /// Constructor
        ///
        constexpr Shape() = default;

        //============================================================================
        /// Constructor
        ///
        /// @param inSquareSize
        ///
        constexpr explicit Shape(uint32 inSquareSize) noexcept :
            rows(inSquareSize),
            cols(inSquareSize)
        {
        }

        //============================================================================
        /// Constructor
        ///
        /// @param inRows
        /// @param inCols
        ///
        constexpr Shape(uint32 inRows, uint32 inCols) noexcept :
            rows(inRows),
            cols(inCols)
        {
        }

        //============================================================================
        /// Equality operator
        ///
        /// @param inOtherShape
        ///
        /// @return bool
        ///
        bool operator==(const Shape& inOtherShape) const noexcept
        {
            return rows == inOtherShape.rows && cols == inOtherShape.cols;
        }

        //============================================================================
        /// Not equality operator
        ///
        /// @param inOtherShape
        ///
        /// @return bool
        ///
        bool operator!=(const Shape& inOtherShape) const noexcept
        {
            return !(*this == inOtherShape);
        }

        //============================================================================
        /// Returns the size of the shape
        ///
        /// @return size
        ///
        [[nodiscard]] uint32 size() const noexcept
        {
            return rows * cols;
        }

        //============================================================================
        /// Returns whether the shape is null (constructed with the
        /// default constructor).
        ///
        /// @return bool
        ///
        [[nodiscard]] bool isnull() const noexcept
        {
            return rows == 0 && cols == 0;
        }

        //============================================================================
        /// Returns whether the shape is square or not.
        ///
        /// @return bool
        ///
        [[nodiscard]] bool issquare() const noexcept
        {
            return rows == cols;
        }

        //============================================================================
        /// Returns the shape as a string representation
        ///
        /// @return std::string
        ///
        [[nodiscard]] std::string str() const
        {
            std::string out = "[" + utils::num2str(rows) + ", " + utils::num2str(cols) + "]\n";
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
        /// IO operator for the Shape class
        ///
        /// @param inOStream
        /// @param inShape
        ///
        /// @return std::ostream
        ///
        friend std::ostream& operator<<(std::ostream& inOStream, const Shape& inShape)
        {
            inOStream << inShape.str();
            return inOStream;
        }
    };
} // namespace nc
