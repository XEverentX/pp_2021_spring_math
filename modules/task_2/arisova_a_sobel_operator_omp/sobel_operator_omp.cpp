// Copyright 2021 Arisova Anastasia

#include <omp.h>
#include "../../modules/task_2/arisova_a_sobel_operator_omp/sobel_operator_omp.h"

MyImage SobelOperatorOmp(const MyImage& sourceImage) {
    static const std::vector<int> xKernel = { -1, 2, -1, 0, 0, 0, 1, 2, 1 };
    static const std::vector<int> yKernel = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
    static const int kernelSize = 3;
    static const int kernelRadius = 1;

    MyImage filterImage(sourceImage.rows, sourceImage.columns);

    #pragma omp parallel for
    for (int x = 0; x < sourceImage.rows; x++)
        for (int y = 0; y < sourceImage.columns; y++) {
            int xResult = 0, yResult = 0;

            for (int i = -kernelRadius; i <= kernelRadius; i++)
                for (int j = -kernelRadius; j <= kernelRadius; j++) {
                    int indexKernel = (i + kernelRadius) * kernelSize + j + kernelRadius;
                    int indexX = clamp(x + j, 0, sourceImage.rows - 1);
                    int indexY = clamp(y + i, 0, sourceImage.columns - 1);

                    xResult += sourceImage(indexX, indexY) * xKernel[indexKernel];
                    yResult += sourceImage(indexX, indexY) * yKernel[indexKernel];
                }
            filterImage(x, y) = clamp(static_cast<int>(std::sqrt(xResult * xResult + yResult * yResult)), 0, 255);
        }
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
