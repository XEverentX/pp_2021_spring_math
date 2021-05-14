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
                 int nx,
                 int ny);

#endif  // MODULES_TASK_2_LEBEDEV_A_SIMPSON_SIMPSON_H_
