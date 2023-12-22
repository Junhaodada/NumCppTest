
/// Description
/// Wrap boundary
///
#pragma once

#include <string>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Internal/StaticAsserts.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/constant2d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/mirror2d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/nearest2d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/reflect2d.hpp"
#include "NumCpp/Filter/Boundaries/Boundaries2d/wrap2d.hpp"
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
    NdArray<dtype> addBoundary2d(const NdArray<dtype>& inImage,
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
                return reflect2d(inImage, boundarySize);
            }
            case Boundary::CONSTANT:
            {
                return constant2d(inImage, boundarySize, inConstantValue);
            }
            case Boundary::NEAREST:
            {
                return nearest2d(inImage, boundarySize);
            }
            case Boundary::MIRROR:
            {
                return mirror2d(inImage, boundarySize);
            }
            case Boundary::WRAP:
            {
                return wrap2d(inImage, boundarySize);
            }
            default:
            {
                THROW_INVALID_ARGUMENT_ERROR("Unimplemented axis type.");
                return {}; // get rid of compiler warning
            }
        }
    }
} // namespace nc::filter::boundary
