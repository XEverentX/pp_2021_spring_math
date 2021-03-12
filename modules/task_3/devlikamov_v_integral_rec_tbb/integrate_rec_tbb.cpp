// Copyright 2021 Devlikamov Vladislav
#include <tbb/tbb.h>
#include "../../../modules/task_3/devlikamov_v_integral_rec_tbb/integrate_rec_tbb.h"

double integral(double a1, double b1, double a2, double b2, double h, double (*f)(double, double)) {
    int n1 = static_cast<int>((b1 - a1) / h);
    int n2 = static_cast<int>((b2 - a2) / h);

    auto result = tbb::parallel_reduce(
        tbb::blocked_range2d<int>(0, n1, 0, n2),
        0.0,
        [&](tbb::blocked_range2d<int> r, double res) {
                for (int i = r.rows().begin(); i < r.rows().end(); i++) {
                    for (int j = r.cols().begin(); j < r.cols().end(); j++) {
                        double x = a1 + i * h + h / 2;
                        double y = a2 + j * h + h / 2;
                        res += f(x, y)*h*h;
                    }
                }
                return res;
        }, std::plus<double>()
    );
    return result;
}
