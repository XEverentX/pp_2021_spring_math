// Copyright 2021 Vedrukov Pavel
#ifndef MODULES_TASK_2_VEDRUKOV_P_LINEAR_FILTERING_OMP_LINEAR_FILTERING_H_
#define MODULES_TASK_2_VEDRUKOV_P_LINEAR_FILTERING_OMP_LINEAR_FILTERING_H_

#include <omp.h>

#include <vector>
#include <cmath>
#include <random>
#include <ctime>

std::vector<std::vector<unsigned int>> get_random_matrix(unsigned int w,
unsigned int h);

std::vector<std::vector<unsigned int>> gauss_filtering(
std::vector<std::vector<unsigned int>> Image, int radius, double sigma);

#endif  // MODULES_TASK_2_VEDRUKOV_P_LINEAR_FILTERING_OMP_LINEAR_FILTERING_H_
