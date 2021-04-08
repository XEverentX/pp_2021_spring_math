// Copyright 2021 Kudryashov Nikita

#include <vector>

bool cmp_ascend(int a, int b);
void shell_sort(std::vector<int>& in, bool(*compare)(int, int) = cmp_ascend);
std::vector<int> getRandomVect(unsigned int size);
std::vector<int> merge(std::vector<int> a, std::vector<int> b, bool(*compare)(int, int) = cmp_ascend);
void shell_sort_simple_merge(std::vector<int>& in, int parts, bool(*compare)(int, int) = cmp_ascend);