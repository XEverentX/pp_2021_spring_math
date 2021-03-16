// Copyright 2021 Boganov Sergei
#ifndef MODULES_TASK_1_BOGANOV_S_SHELL_BATCHER_SHELL_BATCHER_H_
#define MODULES_TASK_1_BOGANOV_S_SHELL_BATCHER_SHELL_BATCHER_H_

#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

enum class mergeType { even, odd };

std::vector<int> getRandomVector(int size);
std::vector<int> sortShell(const std::vector<int>& vec);
std::vector<int> evenOrOddMerge(const std::vector<int>& vec1, const std::vector<int>& vec2, const mergeType& type);
std::vector<int> mergeBatcher(const std::vector<int>& vec1, const std::vector<int>& vec2);
std::vector<int> sortShellWithMergeBatcher(const std::vector<int>& vec);

#endif  // MODULES_TASK_1_BOGANOV_S_SHELL_BATCHER_SHELL_BATCHER_H_
