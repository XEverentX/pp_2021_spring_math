// Copyright 2021 Kudryashov Nikita

#include <gtest/gtest.h>
#include "./shell_simple_merge.h"


TEST(ShellMerge, shellSortTestSize10) {
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

TEST(ShellMerge, shellSortTestSize100) {
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

TEST(ShellMerge, shellSortTestSize200) {
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

TEST(ShellMerge, mergeTest1) {
    // Arrange

    std::vector<int> vec1 {1, 2, 3}, vec2 {4, 5, 6},
        merge_res, true_res {1, 2, 3, 4, 5, 6};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMerge, mergeTest2) {
    // Arrange

    std::vector<int> vec1 {1}, vec2 {4, 5, 6}, merge_res, true_res {1, 4, 5, 6};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMerge, mergeTest3) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201}, vec2 {4},
        merge_res, true_res {4, 100, 200, 201};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res == true_res, true);
}

TEST(ShellMerge, mergeTestArraySize) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201}, vec2 {4},
        merge_res, true_res {4, 100, 200, 201};

    // Act

    merge_res = merge(vec1, vec2);

    // Assert

    ASSERT_EQ(merge_res.size(), true_res.size());
}

TEST(ShellMerge, shellSortSimpleMergeSmall) {
    // Arrange

    std::vector<int> vec1 {100, 200, 201, 4}, res;
    std::vector<int> qsort(vec1);

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge(vec1, 1);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMerge, shellSortSimpleMerge_1_part) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(12);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge(shell, 1);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMerge, shellSortSimpleMerge_3_parts) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(10);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge(shell, 3);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

TEST(ShellMerge, shellSortSimpleMerge_8_parts) {
    // Arrange

    std::vector<int> qsort, shell, res;
    qsort = getRandomVect(1000);
    shell = qsort;

    // Act

    std::sort(qsort.begin(), qsort.end(), cmp_ascend);
    res = shell_sort_simple_merge(shell, 8);

    // Assert

    ASSERT_EQ(qsort == res, true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
