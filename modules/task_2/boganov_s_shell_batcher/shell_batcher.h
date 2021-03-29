// Copyright 2021 Boganov Sergei
#ifndef MODULES_TASK_2_BOGANOV_S_SHELL_BATCHER_SHELL_BATCHER_H_
#define MODULES_TASK_2_BOGANOV_S_SHELL_BATCHER_SHELL_BATCHER_H_

#include <omp.h>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <iostream>

enum class mergeType { even, odd };

std::vector<int> getRandomVector(int size);
std::vector<int> sortShell(const std::vector<int>& vec);
std::vector<std::vector<int>> separatedVector(const std::vector<int>& vec, int number_of_parts);
std::vector<int> SortShellSeq(const std::vector<int>& vec, int number_of_parts);
std::vector<int> SortShellOMP(const std::vector<int>& vec, int number_of_parts);
std::vector<int> evenOddhMergeBatcherSeq(const std::vector<std::vector<int>>& vec, int number_of_parts);
std::vector<int> evenOddhMergeBatcherOMP(const std::vector<std::vector<int>>& vec, int number_of_parts);
std::vector<int> evenOrOddMerge(const std::vector<int>& vec1, const std::vector<int>& vec2, const mergeType& type);
std::vector<int> mergeBatcher(const std::vector<int>& vec1, const std::vector<int>& vec2);

#endif  // MODULES_TASK_2_BOGANOV_S_SHELL_BATCHER_SHELL_BATCHER_H_
