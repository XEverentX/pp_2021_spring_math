// Copyright 2021 Lebedev Alexander
#include "../../../modules/task_2/lebedev_a_simpson/simpson.h"

static double calculate_simpson(std::function<double(double, double)> f,
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
                 uint32_t nx,
                 uint32_t ny) {
    double hx = (b - a) / nx;
    double hy = (d - c) / ny;

    double result = 0.;
    #pragma omp parallel for reduction(+ : result)
    for (uint32_t i = 0; i < nx; i++) {
        for (uint32_t j = 0; j < ny; j++) {
            double x = a + hx * i;
            double y = c + hy * j;
            result += calculate_simpson(f, x, y, hx / 2., hy / 2.);
        }
    }

    return result * hx / 6. * hy / 6.;
}
