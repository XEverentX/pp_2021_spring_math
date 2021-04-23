// Copyright 2021 Arisova Anastasia

#include <tbb/tbb.h>
#include "../../modules/task_3/arisova_a_sobel_operator_tbb/sobel_operator_tbb.h"

MyImage SobelOperatorTBB(const MyImage& sourceImage) {
    static const std::vector<int> xKernel = { -1, 2, -1, 0, 0, 0, 1, 2, 1 };
    static const std::vector<int> yKernel = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
    static const int kernelSize = 3;
    static const int kernelRadius = 1;

    MyImage filterImage(sourceImage.rows, sourceImage.columns);

    tbb::parallel_for(
        tbb::blocked_range2d<int> (0, sourceImage.rows, 0, sourceImage.columns),
        [&filterImage, &sourceImage] (tbb::blocked_range2d<int> r) {
            for (int ii = r.rows().begin(); ii < r.rows().end(); ii++)
                for (int jj = r.cols().begin(); jj < r.cols().end(); jj++) {
                    int xResult = 0, yResult = 0;

                    for (int i = -kernelRadius; i <= kernelRadius; i++)
                        for (int j = -kernelRadius; j <= kernelRadius; j++) {
                            int indexKernel = (i + kernelRadius) * kernelSize + j + kernelRadius;
                            int indexX = clamp(ii + j, 0, r.rows().end() - 1);
                            int indexY = clamp(jj + i, 0, r.cols().end() - 1);

                            xResult += sourceImage(indexX, indexY) * xKernel[indexKernel];
                            yResult += sourceImage(indexX, indexY) * yKernel[indexKernel];
                        }
                    filterImage(ii, jj) = clamp(static_cast<int>(std::sqrt(xResult * xResult + yResult * yResult)),
                                                    0, 255);
                }
        });
    return filterImage;
}

int clamp(int value, int min, int max) {
    if (value > max) {
        return max;
    } else {
        if (value < min) {
            return min;
        } else {
            return value;
        }
    }
}
