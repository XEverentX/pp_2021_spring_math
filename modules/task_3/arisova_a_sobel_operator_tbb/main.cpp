// Copyright 2021 Arisova Anastasia

#include <gtest/gtest.h>
#include <tbb/tick_count.h>

#include "./sobel_operator_tbb.h"
#define time false

TEST(SobelOperatorTBB, EmptyMatrix) {
    MyImage image(0, 0);

    ASSERT_EQ(image.rows, 0);
    ASSERT_EQ(image.columns, 0);
}

TEST(SobelOperatorTBB, Create) {
    MyImage image(5, 5);

    ASSERT_EQ(image.rows, 5);
    ASSERT_EQ(image.columns, 5);
}

TEST(SobelOperatorTBB, Equal) {
    MyImage image1(3, 3);

    ASSERT_EQ(image1, image1);
}

TEST(SobelOperatorTBB, CompareSameImage) {
    MyImage image1(3, 3);
    MyImage image2(3, 3);

    ASSERT_EQ(image1, image2);
}

TEST(SobelOperatorTBB, ApplyingFilterImage3x3) {
    std::vector<int> input = {10, 11, 70, 1, 3, 40, 17, 6, 2};
    std::vector<int> output = {40, 44, 255, 36, 34, 206, 93, 44, 121};

    MyImage image1(input, 3, 3);
    MyImage image2(3, 3);

    const MyImage &ref_img = image1;

    tbb::tick_count t1 = tbb::tick_count::now();
    image2 = SobelOperatorTBB(ref_img);
    tbb::tick_count t2 = tbb::tick_count::now();

    if (time) {
        printf("Work took %f seconds\n", (t2 - t1).seconds());
    }

    ASSERT_EQ(image2.data, output);
}

TEST(SobelOperatorTBB, ApplyingFilterImage7x7) {
    std::vector<int> input = {1, 4, 5, 2, 1, 6, 1, 1, 3, 7,
                                8, 9, 4, 10, 4, 2, 5, 1, 3, 10,
                                1, 8, 50, 42, 61, 7, 2, 4, 60, 5,
                                8, 30, 1, 4, 9, 6, 5, 3, 5, 34,
                                6, 5, 8, 7, 6, 1, 9, 7, 4};
    std::vector<int> output = {4, 16, 20, 8, 4, 24, 4, 4, 13, 25,
                                34, 45, 26, 38, 20, 12, 22, 24, 27, 30,
                                28, 35, 215, 239, 255, 110, 28, 5, 255, 143,
                                148, 172, 53, 8, 37, 217, 63, 22, 89, 107,
                                67, 27, 32, 29, 25, 14, 97, 22, 18};
    MyImage image1(input, 7, 7);
    MyImage image2(7, 7);

    const MyImage &ref_img = image1;

    tbb::tick_count t1 = tbb::tick_count::now();
    image2 = SobelOperatorTBB(ref_img);
    tbb::tick_count t2 = tbb::tick_count::now();

    if (time) {
        printf("Work took %f seconds\n", (t2 - t1).seconds());
    }

    ASSERT_EQ(image2.data, output);
}

TEST(SobelOperatorTBB, ApplyingFilterImage1000x1000) {
    MyImage image1(1000, 1000);
    MyImage image2(1000, 1000);

    const MyImage &ref_img = image1;

    tbb::tick_count t1 = tbb::tick_count::now();
    image2 = SobelOperatorTBB(ref_img);
    tbb::tick_count t2 = tbb::tick_count::now();

    if (time) {
        printf("Work took %f seconds\n", (t2 - t1).seconds());
    }

    ASSERT_EQ(image1, image2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
