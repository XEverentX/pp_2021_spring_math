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

TEST(SobelOperatorTBB, ApplyingFilterImage10x10) {
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
    std::vector<int> output = {4, 16, 20, 8, 4, 24, 4, 4, 12, 28,
                                42, 43, 22, 38, 27, 17, 14, 8, 12, 38,
                                28, 27, 205, 230, 255, 107, 16, 11, 254, 92,
                                42, 127, 145, 163, 200, 61, 17, 16, 181, 61,
                                25, 88, 4, 35, 30, 18, 27, 32, 21, 241,
                                255, 151, 26, 22, 255, 255, 255, 190, 242, 181,
                                255, 213, 255, 104, 255, 255, 255, 93, 162, 37,
                                255, 232, 195, 255, 253, 255, 253, 191, 255, 111,
                                22, 201, 188, 255, 131, 152, 255, 255, 166, 255,
                                255, 239, 197, 55, 65, 114, 255, 243, 164, 255};

    MyImage image1(input, 10, 10);
    MyImage image2(10, 10);

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

TEST(SobelOperatorTBB, ApplyingFilterImage10000x10000) {
    MyImage image1(10000, 10000);
    MyImage image2(10000, 10000);

    const MyImage &ref_img = image1;

    tbb::tick_count t1 = tbb::tick_count::now();
    image2 = SobelOperatorTBB(ref_img);
    tbb::tick_count t2 = tbb::tick_count::now();

    if (time) {
        printf("Work took %f seconds\n", (t2 - t1).seconds());
    }

    ASSERT_EQ(image1, image2);
}

TEST(SobelOperatorTBB, ApplyingFilterImage15000x15000) {
    MyImage image1(15000, 15000);
    MyImage image2(15000, 15000);

    const MyImage &ref_img = image1;

    tbb::tick_count t1 = tbb::tick_count::now();
    image2 = SobelOperatorTBB(ref_img);
    tbb::tick_count t2 = tbb::tick_count::now();

    if (time) {
        printf("Work took %f seconds\n", (t2 - t1).seconds());
    }

    ASSERT_EQ(image1, image2);
}

TEST(SobelOperatorTBB, ApplyingFilterImage20000x20000) {
    MyImage image1(20000, 20000);
    MyImage image2(20000, 20000);

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
