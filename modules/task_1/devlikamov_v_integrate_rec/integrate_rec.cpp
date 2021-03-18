// Copyright 2021 Devlikamov Vladislav
#include "../../../modules/task_1/devlikamov_v_integrate_rec/integrate_rec.h"

double integral(double a1, double b1, double a2, double b2, double h, double (*f)(double, double)) {
    int n1 = static_cast<int>((b1 - a1) / h);
    int n2 = static_cast<int>((b2 - a2) / h);

    double res = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            double x = a1 + i * h + h / 2;
            double y = a2 + j * h + h / 2;
            res += f(x, y)*h*h;
        }
    }
    return res;
}
