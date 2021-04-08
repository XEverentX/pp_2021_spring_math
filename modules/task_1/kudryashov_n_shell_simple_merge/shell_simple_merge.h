// Copyright 2021 Kudryashov Nikita

#ifndef MODULES_TASK_1_KUDRYASHOV_N_SHELL_SIMPLE_MERGE_SHELL_SIMPLE_MERGE_H_
#define MODULES_TASK_1_KUDRYASHOV_N_SHELL_SIMPLE_MERGE_SHELL_SIMPLE_MERGE_H_

#include <vector>

bool cmp_ascend(int a, int b);
std::vector<int> shell_sort(const std::vector<int>& in_vect,
    bool(*compare)(int, int) = cmp_ascend);
std::vector<int> getRandomVect(unsigned int size);
std::vector<int> merge(std::vector<int> a, std::vector<int> b,
    bool(*compare)(int, int) = cmp_ascend);
std::vector<int> shell_sort_simple_merge(const std::vector<int>& in_vect,
    int parts, bool(*compare)(int, int) = cmp_ascend);

#endif  // MODULES_TASK_1_KUDRYASHOV_N_SHELL_SIMPLE_MERGE_SHELL_SIMPLE_MERGE_H_
