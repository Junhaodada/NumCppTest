
/// Description
/// Calculates a multidimensional gaussian filter.
///
#pragma once

#include <cmath>
#include <string>
#include <utility>

#include "NumCpp/Core/Internal/Error.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Filter/Filters/Filters2d/convolve.hpp"
#include "NumCpp/NdArray.hpp"
#include "NumCpp/Utils/gaussian.hpp"

namespace nc::filter
{
    //============================================================================
    // Method Description:
    /// Calculates a multidimensional gaussian filter.
    ///
    /// SciPy Reference:
    /// https://docs.scipy.org/doc/scipy/reference/generated/scipy.ndimage.gaussian_filter.html#scipy.ndimage.gaussian_filter
    ///
    /// @param inImageArray
    /// @param inSigma: Standard deviation for Gaussian kernel
    /// @param inBoundaryType: boundary mode (default Reflect) options (reflect, constant, nearest, mirror, wrap)
    /// @param inConstantValue: contant value if boundary = 'constant' (default 0)
    /// @return NdArray
    ///
    template<typename dtype>
    NdArray<dtype> gaussianFilter(const NdArray<dtype>& inImageArray,
                                  double                inSigma,
                                  Boundary              inBoundaryType  = Boundary::REFLECT,
                                  dtype                 inConstantValue = 0)
    {
        if (inSigma <= 0)
        {
            THROW_INVALID_ARGUMENT_ERROR("input sigma value must be greater than zero.");
        }

        // calculate the kernel size based off of the input sigma value
        constexpr uint32 MIN_KERNEL_SIZE = 5;
        uint32           kernelSize =
            std::max(static_cast<uint32>(std::ceil(inSigma * 2. * 4.)), MIN_KERNEL_SIZE); // 4 standard deviations
        if (kernelSize % 2 == 0)
        {
            ++kernelSize; // make sure the kernel is an odd size
        }

        const auto kernalHalfSize = static_cast<double>(kernelSize / 2); // integer division

        // calculate the gaussian kernel
        NdArray<double> kernel(kernelSize);
        for (double row = 0; row < kernelSize; ++row)
        {
            for (double col = 0; col < kernelSize; ++col)
            {
                kernel(static_cast<uint32>(row), static_cast<uint32>(col)) =
                    utils::gaussian(row - kernalHalfSize, col - kernalHalfSize, inSigma);
            }
        }

        // normalize the kernel
        kernel /= kernel.sum().item();

        // perform the convolution
        NdArray<dtype> output =
            convolve(inImageArray.template astype<double>(), kernelSize, kernel, inBoundaryType, inConstantValue)
                .template astype<dtype>();

        return output;
    }
} // namespace nc::filter
