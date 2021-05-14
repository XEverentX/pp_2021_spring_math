// Copyright 2021 Lebedev Alexander
#include <tbb/tbb.h>

#include "../../../modules/task_3/lebedev_a_simpson_tbb/simpson.h"

double calculate_simpson(std::function<double(double, double)> f,
                                double x,
                                double y,
                                double hx,
                                double hy) {
    double x0 = x;
    double x1 = x + hx;
    double x2 = x + 2. * hx;
    double y0 = y;
    double y1 = y + hy;
    double y2 = y + 2. * hy;

    return f(x0, y0) + 4. * f(x1, y0) + f(x2, y0) +
           4. * f(x0, y1) + 16. * f(x1, y1) + 4. * f(x2, y1) +
           f(x0, y2) + 4. * f(x1, y2) + f(x2, y2);
}

double integrate(std::function<double(double, double)> f,
                 double a,
                 double b,
                 double c,
                 double d,
                 int nx,
                 int ny) {
    double hx = (b - a) / nx;
    double hy = (d - c) / ny;

    double result = tbb::parallel_reduce(
        tbb::blocked_range2d<int>(0, nx, 0, ny),
        0.,
        [&] (const tbb::blocked_range2d<int> &r, double sum) {
            for (int i = r.rows().begin(); i < r.rows().end(); i++) {
                for (int j = r.cols().begin(); j < r.cols().end(); j++) {
                    double x = a + hx * i;
                    double y = c + hy * j;
                    sum += calculate_simpson(f, x, y, hx / 2., hy / 2.);
                }
            }
            return sum;
        }, std::plus<double>());

    return result * hx / 6. * hy / 6.;
}
