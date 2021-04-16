// Copyright 2021 Kudryashov Nikita

#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "./shell_simple_merge_omp.h"


TEST(ShellMergeOMP, shellSortTestSize10) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(10);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort(shell, cmp_ascend);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeOMP, shellSortTestSize100) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(100);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort(shell, cmp_ascend);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeOMP, shellSortTestSize200) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(200);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort(shell);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeOMP, mergeTest1) {
    // Arrange

    std::vector<int> vec1 {1, 2, 3}, vec2 {4, 5, 6},
        merge_res, true_res {1, 2, 3, 4, 5, 6};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMergeOMP, mergeTest2) {
    // Arrange

    std::vector<int> vec1 {1}, vec2 {4, 5, 6}, merge_res, true_res {1, 4, 5, 6};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMergeOMP, mergeTest3) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201}, vec2 {4},
        merge_res, true_res {4, 100, 200, 201};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMergeOMP, mergeTestArraySize) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201}, vec2 {4},
        merge_res, true_res {4, 100, 200, 201};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res.size(), true_res.size());
}

TEST(ShellMergeOMP, shellSortSimpleMergeSmall) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201, 4}, res;
    std::vector<int> qsort(vec1);

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_omp(vec1, 1);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeOMP, shellSortSimpleMerge_1_part) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(12);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_omp(shell, 1);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeOMP, shellSortSimpleMerge_3_parts) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(10);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_omp(shell, 3);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeOMP, shellSortSimpleMerge_8_parts) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(1000);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_omp(shell, 8);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

// TEST(ShellMergeOMP_Time, shellSortSimpleMergeOMP_10kk_size) {
//     // Arrange

//     std::vector<int> seq, paral, res_seq, res_paral;
//     seq = getRandomVect(10000000);
//     paral = seq;

//     // Act

//     double start = omp_get_wtime();
//     res_paral = shell_sort_simple_merge_omp(paral, 8);
//     double end = omp_get_wtime();
//     double paral_time, seq_time;
//     paral_time = end - start;

//     std::cout << "Parallel sort took: " << end - start << " s." << std::endl;

//     start = omp_get_wtime();
//     res_seq = shell_sort_simple_merge(seq, 8);
//     end = omp_get_wtime();
//     seq_time = end - start;
//     double speedup = seq_time / paral_time;

//     std::cout << "Sequential sort took: " << seq_time << " s." << std::endl;
//     std::cout << "Speed up: " << speedup << std::endl;

//     // Assert

//     ASSERT_EQ(res_seq == res_paral, true);
// }

// TEST(ShellMergeOMP_Time, shellSortSimpleMergeOMP_50kk_size) {
//     // Arrange

//     std::vector<int> seq, paral, res_seq, res_paral;
//     seq = getRandomVect(50000000);
//     paral = seq;

//     // Act

//     double start = omp_get_wtime();
//     res_paral = shell_sort_simple_merge_omp(paral, 8);
//     double end = omp_get_wtime();
//     double paral_time, seq_time;
//     paral_time = end - start;

//     std::cout << "Parallel sort took: " << end - start << " s." << std::endl;

//     start = omp_get_wtime();
//     res_seq = shell_sort_simple_merge(seq, 8);
//     end = omp_get_wtime();
//     seq_time = end - start;
//     double speedup = seq_time / paral_time;

//     std::cout << "Sequential sort took: " << seq_time << " s." << std::endl;
//     std::cout << "Speed up: " << speedup << std::endl;

//     // Assert

//     ASSERT_EQ(res_seq == res_paral, true);
// }

// TEST(ShellMergeOMP_Time, shellSortSimpleMergeOMP_100kk_size) {
//     // Arrange

//     std::vector<int> seq, paral, res_seq, res_paral;
//     seq = getRandomVect(100000000);
//     paral = seq;

//     // Act

//     double start = omp_get_wtime();
//     res_paral = shell_sort_simple_merge_omp(paral, 8);
//     double end = omp_get_wtime();
//     double paral_time, seq_time;
//     paral_time = end - start;

//     std::cout << "Parallel sort took: " << end - start << " s." << std::endl;

//     start = omp_get_wtime();
//     res_seq = shell_sort_simple_merge(seq, 8);
//     end = omp_get_wtime();
//     seq_time = end - start;
//     double speedup = seq_time / paral_time;

//     std::cout << "Sequential sort took: " << seq_time << " s." << std::endl;
//     std::cout << "Speed up: " << speedup << std::endl;

//     // Assert

//     ASSERT_EQ(res_seq == res_paral, true);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
