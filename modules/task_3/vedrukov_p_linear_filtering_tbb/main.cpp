// Copyright 2021 Vedrukov Pavel
#include <../gtest/googletest/include/gtest/gtest.h>
#include <tbb/tick_count.h>
#include <vector>
#include <cmath>
#include <fstream>
#include <random>
#include <ctime>
#include "../../../modules/task_2/vedrukov_p_linear_filtering_omp/linear_filtering.h"

TEST(linear_filtering, test_1) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(20, 20);
    ASSERT_NO_THROW(gauss_filtering(a, 1, 0.3));
}

TEST(linear_filtering, test_2) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(40, 40);
    ASSERT_NO_THROW(gauss_filtering(a, 1, 0.3));
}

TEST(linear_filtering, test_3) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(60, 60);
    ASSERT_NO_THROW(gauss_filtering(a, 1, 0.3));
}

TEST(linear_filtering, test_4) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(80, 80);
    ASSERT_NO_THROW(gauss_filtering(a, 1, 0.3));
}

TEST(linear_filtering, test_5) {
    std::vector<std::vector<unsigned int>> a = get_random_matrix(100, 100);
    ASSERT_NO_THROW(gauss_filtering(a, 1, 0.3));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
