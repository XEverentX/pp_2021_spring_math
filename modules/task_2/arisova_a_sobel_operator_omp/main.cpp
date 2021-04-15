// Copyright 2021 Arisova Anastasia

#include <gtest/gtest.h>
#include <omp.h>

#include "./sobel_operator_omp.h"

TEST(SobelOperatorOmp, EmptyMatrix) {
    MyImage image(0, 0);

    ASSERT_EQ(image.rows, 0);
    ASSERT_EQ(image.columns, 0);
}

TEST(SobelOperatorOmp, Create) {
    MyImage image(5, 5);

    ASSERT_EQ(image.rows, 5);
    ASSERT_EQ(image.columns, 5);
}

TEST(SobelOperatorOmp, Equal) {
    MyImage image1(3, 3);

    ASSERT_EQ(image1, image1);
}

TEST(SobelOperatorOmp, CompareSameImage) {
    MyImage image1(3, 3);
    MyImage image2(3, 3);

    ASSERT_EQ(image1, image2);
}

TEST(SobelOperatorOmp, ApplyingFilterImage3x3) {
    std::vector<int> input = {10, 11, 70, 1, 3, 40, 17, 6, 2};
    std::vector<int> output = {57, 255, 255, 16, 145, 252, 63, 64, 121};

    MyImage image1(input, 3, 3);
    MyImage image2(3, 3);

    const MyImage &ref_img = image1;
    image2 = SobelOperatorOmp(ref_img);

    ASSERT_EQ(image2.data, output);
}

TEST(SobelOperatorOmp, ApplyingFilterImage7x7) {
    std::vector<int> input = {1, 4, 5, 2, 1, 6, 1, 1, 3, 7,
                                8, 9, 4, 10, 4, 2, 5, 1, 3, 10,
                                1, 8, 50, 42, 61, 7, 2, 4, 60, 5,
                                8, 30, 1, 4, 9, 6, 5, 3, 5, 34,
                                6, 5, 8, 7, 6, 1, 9, 7, 4};
    std::vector<int> output = {15, 22, 17, 24, 25, 13, 29, 11, 21, 19,
                                26, 37, 37, 14, 88, 147, 171, 140, 62, 13,
                                36, 180, 81, 248, 106, 110, 28, 19, 178, 212,
                                196, 124, 10, 37, 27, 157, 61, 49, 87, 10,
                                81, 26, 29, 24, 10, 70, 57, 25, 18};
    MyImage image1(input, 7, 7);
    MyImage image2(7, 7);

    const MyImage &ref_img = image1;
    image2 = SobelOperatorOmp(ref_img);

    ASSERT_EQ(image2.data, output);
}

TEST(SobelOperatorOmp, ApplyingFilterImage10x10) {
    std::vector<int> input = {1, 4, 5, 2, 1, 6, 1, 1, 3, 7,
                                8, 9, 4, 10, 4, 2, 5, 1, 3, 10,
                                1, 8, 50, 42, 61, 7, 2, 4, 60, 5,
                                8, 30, 1, 4, 9, 6, 5, 3, 5, 34,
                                6, 5, 8, 7, 6, 1, 9, 7, 4, 64,
                                94, 8, 5, 1, 71, 62, 54, 32, 50, 8,
                                90, 54, 50, 10, 60, 103, 87, 5, 7, 10,
                                8, 4, 65, 80, 41, 50, 32, 65, 45, 16, 4,
                                50, 16, 14, 21, 37, 84, 60, 42, 97, 71,
                                40, 54, 1, 5, 7, 9, 4, 6, 10, 18};
    std::vector<int> output = {29, 20, 15, 19, 15, 5, 8, 8, 31, 32,
                                44, 93, 151, 186, 161, 75, 6, 99, 118, 56,
                                46, 99, 75, 230, 92, 123, 18, 122, 65, 181,
                                82, 81, 160, 169, 152, 66, 23, 84, 141, 146,
                                239, 82, 19, 118, 193, 223, 183, 153, 175, 127,
                                255, 255, 138, 189, 255, 255, 255, 145, 150, 239,
                                255, 250, 255, 255, 255, 255, 202, 200, 53, 41,
                                255, 174, 111, 236, 255, 255, 155, 145, 255, 255,
                                236, 147, 177, 205, 209, 251, 254, 255, 255, 255,
                                255, 255, 53, 74, 87, 178, 239, 223, 226, 255};

    MyImage image1(input, 10, 10);
    MyImage image2(10, 10);

    const MyImage &ref_img = image1;
    image2 = SobelOperatorOmp(ref_img);

    ASSERT_EQ(image2.data, output);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
