// Copyright 2021 Arisova Anastasia

#include "./sobel_operator.h"
#include <gtest/gtest.h>

TEST(SobelOperatorSeq, EmptyMatrix) {
    MyImage image(0, 0);

    ASSERT_EQ(image.rows, 0);
    ASSERT_EQ(image.columns, 0);
}

TEST(SobelOperatorSeq, Create) {
    MyImage image(5, 5);

    ASSERT_EQ(image.rows, 5);
    ASSERT_EQ(image.columns, 5);
}

TEST(SobelOperatorSeq, CompareSameImage) {
    MyImage image1(3, 3);
    MyImage image2(3, 3);

    ASSERT_EQ(image1, image2);
}

TEST(SobelOperatorSeq, Equal) {
    MyImage image1(3, 3);

    ASSERT_EQ(image1, image1);
}

TEST(SobelOperatorSeq, CompareSameImage2) {
    MyImage image1(3, 3);
    MyImage image2(3, 3);

    ASSERT_EQ(image1, image2);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
