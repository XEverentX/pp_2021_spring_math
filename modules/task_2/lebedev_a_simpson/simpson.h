// Copyright 2021 Lebedev Alexander
#ifndef MODULES_TASK_2_LEBEDEV_A_SIMPSON_SIMPSON_H_
#define MODULES_TASK_2_LEBEDEV_A_SIMPSON_SIMPSON_H_

#include <functional>
#include <cstdint>

double integrate(std::function<double(double, double)> f,
                 double a,
                 double b,
                 double c,
                 double d,
                 uint32_t nx,
                 uint32_t ny);

#endif  // MODULES_TASK_2_LEBEDEV_A_SIMPSON_SIMPSON_H_
