
/// Description
/// Wrap boundary
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries1d/constant1d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries1d/mirror1d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries1d/nearest1d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries1d/reflect1d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries1d/wrap1d.hpp"
#include "NumCpp/Filter/Boundaries/Boundary.hpp"
#include "NumCpp/NdArray.hpp"

namespace nc::filter::boundary
{
    //============================================================================
    // Method Description:
    /// Wrap boundary
    ///
    /// @param inImage
    /// @param inBoundaryType
    /// @param inKernalSize
    /// @param inConstantValue (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> addBoundary1d(const NdArray<dtype>& inImage,
                                 Boundary              inBoundaryType,
                                 uint32                inKernalSize,
                                 dtype                 inConstantValue = 0)
    {
        STATIC_ASSERT_ARITHMETIC(dtype);

        if (inKernalSize % 2 == 0)
        {
            THROW_INVALID_ARGUMENT_ERROR("input kernal size must be an odd value.");
        }

        const uint32 boundarySize = inKernalSize / 2; // integer division

        switch (inBoundaryType)
        {
            case Boundary::REFLECT:
            {
                return reflect1d(inImage, boundarySize);
            }
            case Boundary::CONSTANT:
            {
                return constant1d(inImage, boundarySize, inConstantValue);
            }
            case Boundary::NEAREST:
            {
                return nearest1d(inImage, boundarySize);
            }
            case Boundary::MIRROR:
            {
                return mirror1d(inImage, boundarySize);
            }
            case Boundary::WRAP:
            {
                return wrap1d(inImage, boundarySize);
            }
            default:
            {
                // This can't actually happen but just adding to get rid of compiler warning
                THROW_INVALID_ARGUMENT_ERROR("ERROR!");
            }
        }

        return NdArray<dtype>(); // get rid of compiler warning
    }
} // namespace nc::filter::boundary
