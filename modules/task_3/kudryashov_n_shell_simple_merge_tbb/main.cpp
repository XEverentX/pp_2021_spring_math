// Copyright 2021 Kudryashov Nikita

#include <gtest/gtest.h>
#include <tbb/tick_count.h>
#include <iostream>
#include <vector>
#include "./shell_simple_merge_tbb.h"


TEST(ShellMergeTBB, shellSortTestSize10) {
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

TEST(ShellMergeTBB, shellSortTestSize100) {
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

TEST(ShellMergeTBB, shellSortTestSize200) {
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

TEST(ShellMergeTBB, mergeTest1) {
    // Arrange

    std::vector<int> vec1 {1, 2, 3}, vec2 {4, 5, 6},
        merge_res, true_res {1, 2, 3, 4, 5, 6};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMergeTBB, mergeTest2) {
    // Arrange

    std::vector<int> vec1 {1}, vec2 {4, 5, 6}, merge_res, true_res {1, 4, 5, 6};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMergeTBB, mergeTest3) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201}, vec2 {4},
        merge_res, true_res {4, 100, 200, 201};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMergeTBB, mergeTestArraySize) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201}, vec2 {4},
        merge_res, true_res {4, 100, 200, 201};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res.size(), true_res.size());
}

TEST(ShellMergeTBB, shellSortSimpleMergeSmall) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201, 4}, res;
    std::vector<int> qsort(vec1);

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_tbb(vec1, 1);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeTBB, shellSortSimpleMerge_1_part) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(12);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_tbb(shell, 1);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeTBB, shellSortSimpleMerge_3_parts) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(10);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_tbb(shell, 3);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMergeTBB, shellSortSimpleMerge_8_parts) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(1000);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge_tbb(shell, 8);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

// TEST(ShellMergeTBB_Time, shellSortSimpleMergeTBB_10kk_size) {
//     // Arrange

//     std::vector<int> seq, paral, res_seq, res_paral;
//     seq = getRandomVect(10000000);
//     paral = seq;

//     // Act

//     tbb::tick_count start = tbb::tick_count::now();
//     res_paral = shell_sort_simple_merge_tbb(paral, 8);
//     tbb::tick_count end = tbb::tick_count::now();
//     double paral_time, seq_time;
//     paral_time = (end - start).seconds();

//     std::cout << "Parallel sort took: " << paral_time << " s." << std::endl;

//     start = tbb::tick_count::now();
//     res_seq = shell_sort_simple_merge(seq, 8);
//     end = tbb::tick_count::now();
//     seq_time = (end - start).seconds();
//     double speedup = seq_time / paral_time;

//     std::cout << "Sequential sort took: " << seq_time << " s." << std::endl;
//     std::cout << "Speed up: " << speedup << std::endl;

//     // Assert

//     ASSERT_EQ(res_seq == res_paral, true);
// }

// TEST(ShellMergeTBB_Time, shellSortSimpleMergeTBB_50kk_size) {
//     // Arrange

//     std::vector<int> seq, paral, res_seq, res_paral;
//     seq = getRandomVect(50000000);
//     paral = seq;

//     // Act

//     tbb::tick_count start = tbb::tick_count::now();
//     res_paral = shell_sort_simple_merge_tbb(paral, 8);
//     tbb::tick_count end = tbb::tick_count::now();
//     double paral_time, seq_time;
//     paral_time = (end - start).seconds();

//     std::cout << "Parallel sort took: " << paral_time << " s." << std::endl;

//     start = tbb::tick_count::now();
//     res_seq = shell_sort_simple_merge(seq, 8);
//     end = tbb::tick_count::now();
//     seq_time = (end - start).seconds();
//     double speedup = seq_time / paral_time;

//     std::cout << "Sequential sort took: " << seq_time << " s." << std::endl;
//     std::cout << "Speed up: " << speedup << std::endl;

//     // Assert

//     ASSERT_EQ(res_seq == res_paral, true);
// }

// TEST(ShellMergeTBB_Time, shellSortSimpleMergeTBB_100kk_size) {
//     // Arrange

//     std::vector<int> seq, paral, res_seq, res_paral;
//     seq = getRandomVect(100000000);
//     paral = seq;

//     // Act

//     tbb::tick_count start = tbb::tick_count::now();
//     res_paral = shell_sort_simple_merge_tbb(paral, 8);
//     tbb::tick_count end = tbb::tick_count::now();
//     double paral_time, seq_time;
//     paral_time = (end - start).seconds();

//     std::cout << "Parallel sort took: " << paral_time << " s." << std::endl;

//     start = tbb::tick_count::now();
//     res_seq = shell_sort_simple_merge(seq, 8);
//     end = tbb::tick_count::now();
//     seq_time = (end - start).seconds();
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
