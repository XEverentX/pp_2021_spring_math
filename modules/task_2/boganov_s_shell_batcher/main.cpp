// Copyright 2021 Boganov Sergei

#include <gtest/gtest.h>
#include "./shell_batcher.h"

#define TIME

TEST(SortShellSeq, sequential_shell_sorting_test_for_10_thousands) {
  int number_of_parts = 4;
  std::vector<int> vec = getRandomVector(10000);
  std::vector<int> res = SortShellOMP(vec, number_of_parts);

  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(SortShellOMP, OMP_shell_sorting_test_for_10_thousands) {
  int number_of_parts = 4;
  std::vector<int> vec = getRandomVector(10000);
  std::vector<int> res = SortShellOMP(vec, number_of_parts);

  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(SortShellOMP, OMP_shell_sorting_test_for_100_thousands) {
  int number_of_parts = 4;
  std::vector<int> vec = getRandomVector(100000);
  std::vector<int> res = SortShellOMP(vec, number_of_parts);

  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(SortShellSeq, sequential_shell_sorting_test_for_100_thousands) {
  int number_of_parts = 4;
  std::vector<int> vec = getRandomVector(100000);
  std::vector<int> res = SortShellOMP(vec, number_of_parts);

  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(SortShellOMP, OMP_shell_sorting_test_for_1_million) {
  int number_of_parts = 4;
  std::vector<int> vec = getRandomVector(1000000);
  std::vector<int> res = SortShellOMP(vec, number_of_parts);

  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

TEST(SortShellSeq, sequential_shell_sorting_test_for_1_million) {
  int number_of_parts = 4;
  std::vector<int> vec = getRandomVector(1000000);
  std::vector<int> res = SortShellOMP(vec, number_of_parts);

  std::sort(vec.begin(), vec.end());
  ASSERT_EQ(vec, res);
}

// TEST(SortShellSeq, sequential_shell_sorting_time_test) {
//   int number_of_parts = 8;
//   std::vector<int> vec = getRandomVector(50000000);

//   double begin = omp_get_wtime();
//   std::vector<int> res = SortShellSeq(vec, number_of_parts);
//   double end = omp_get_wtime();

//   #ifdef TIME
//     printf("Time: %lf seconds\n", end - begin);
//   #endif

//   std::sort(vec.begin(), vec.end());
//   ASSERT_EQ(vec, res);
// }

// TEST(SortShellOMP, OMP_shell_sorting_time_test) {
//   int number_of_parts = 8;
//   std::vector<int> vec = getRandomVector(50000000);

//   double begin = omp_get_wtime();
//   std::vector<int> res = SortShellOMP(vec, number_of_parts);
//   double end = omp_get_wtime();

//   #ifdef TIME
//     printf("Time: %lf seconds\n", end - begin);
//   #endif

//   std::sort(vec.begin(), vec.end());
//   ASSERT_EQ(vec, res);
// }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
