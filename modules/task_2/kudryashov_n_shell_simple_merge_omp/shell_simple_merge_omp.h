// Copyright 2021 Kudryashov Nikita

#ifndef MODULES_TASK_2_KUDRYASHOV_N_SHELL_SIMPLE_MERGE_OMP_SHELL_SIMPLE_MERGE_OMP_H_
#define MODULES_TASK_2_KUDRYASHOV_N_SHELL_SIMPLE_MERGE_OMP_SHELL_SIMPLE_MERGE_OMP_H_

#include <omp.h>
#include <vector>

bool cmp_ascend(int a, int b);
std::vector<int> shell_sort(const std::vector<int>& in_vect,
    bool(*compare)(int, int) = cmp_ascend);
std::vector<int> getRandomVect(unsigned int size);
std::vector<int> merge(std::vector<int> a, std::vector<int> b,
    bool(*compare)(int, int) = cmp_ascend);
std::vector<int> shell_sort_simple_merge(const std::vector<int>& in_vect,
    int parts, bool(*compare)(int, int) = cmp_ascend);
std::vector<int> shell_sort_simple_merge_omp(const std::vector<int>& in_vect,
    int parts, bool(*compare)(int, int) = cmp_ascend);

#endif  // MODULES_TASK_2_KUDRYASHOV_N_SHELL_SIMPLE_MERGE_OMP_SHELL_SIMPLE_MERGE_OMP_H_
