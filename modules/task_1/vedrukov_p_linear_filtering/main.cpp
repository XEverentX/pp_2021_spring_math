// Copyright 2021 Vedrukov Pavel
#include <../gtest/googletest/include/gtest/gtest.h>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>
#include "../../../modules/task_1/vedrukov_p_linear_filtering/linear_filtering.h"

TEST(linear_filtering, test_1) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(10, 10);
    ASSERT_NO_THROW(gauss_filtering(a, 3, 0.5));
}

TEST(linear_filtering, test_2) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(1, 1);
    ASSERT_NO_THROW(gauss_filtering(a, 7, 1));
}

TEST(linear_filtering, test_3) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(33, 4);
    ASSERT_NO_THROW(gauss_filtering(a, 5, 0.8));
}

TEST(linear_filtering, test_4) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(74, 25);
    ASSERT_NO_THROW(gauss_filtering(a, 9, 1.5));
}

TEST(linear_filtering, test_5) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(900, 900);
    ASSERT_NO_THROW(gauss_filtering(a, 10, 1.6));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
