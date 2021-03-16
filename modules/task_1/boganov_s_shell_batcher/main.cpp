// Copyright 2021 Boganov Sergei

#include <gtest/gtest.h>
#include "./shell_batcher.h"

TEST(sortShell, shell_sorting_test_for_100_elements) {
  std::vector<int> vec = getRandomVector(100);
  std::vector<int> res = sortShell(vec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(evenOrOddMerge, evenMerge) {
  std::vector<int> vec1 = {5, 1, 7, 3, 2};
  std::vector<int> vec2 = {2, 8, 6, 0, 9};

  std::vector<int> evenMerge = evenOrOddMerge(vec1, vec2, mergeType::even);
  std::vector<int> res = {2, 5, 6, 7, 2, 9};

  ASSERT_EQ(evenMerge, res);
}

TEST(evenOrOddMerge, oddMerge) {
  std::vector<int> vec1 = {1, 7, 3, 9, 2};
  std::vector<int> vec2 = {4, 0, 6, 8, 5};

  std::vector<int> evenMerge = evenOrOddMerge(vec1, vec2, mergeType::odd);
  std::vector<int> res = {0, 7, 8, 9};

  ASSERT_EQ(evenMerge, res);
}

TEST(sortShellWithMergeBatcher, shell_sorting_with_merge_batcher_test_for_100_elements) {
  std::vector<int> vec = getRandomVector(100);
  std::vector<int> res = sortShellWithMergeBatcher(vec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(sortShellWithMergeBatcher, shell_sorting_with_merge_batcher_test_for_1000_elements) {
  std::vector<int> vec = getRandomVector(1000);
  std::vector<int> res = sortShellWithMergeBatcher(vec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(sortShellWithMergeBatcher, shell_sorting_with_merge_batcher_test_for_10000_elements) {
  std::vector<int> vec = getRandomVector(10000);
  std::vector<int> res = sortShellWithMergeBatcher(vec);
  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
