// Copyright 2021 Devlikamov Vladislav
#include <gtest/gtest.h>
#include <omp.h>
#include <cmath>
#include "./integrate_rec_omp.h"
#define SHOW 0

double f(double x, double y) {
    return sin(x + y)*cos(x);
}

double f1(double x, double y) {
    return 10*x*x*x + 5*x*x + 15;
}

double f2(double x, double y) {
    return sin(x + y)*x*x + cos(x + y)*x;
}

TEST(Integrate_rec_omp, Test_Integrate_rec_omp_1) {
    double a = 1.0, b = 2.0;
    double c = 3.0, d = 4.0;
    double h = 0.001;
    double answer = -0.0813902;

    double start = omp_get_wtime();
    double ans = integral(a, b, c, d, h, f);
    double end = omp_get_wtime();

    if (SHOW) printf("Work took %f seconds\n", end - start);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec_omp, Test_Integrate_rec_omp_2) {
    double a = 0.0, b = 2.0;
    double c = 1.0, d = 2.0;
    double h = 0.0005;
    double answer = 250/3.0;

    double start = omp_get_wtime();
    double ans = integral(a, b, c, d, h, f1);
    double end = omp_get_wtime();

    if (SHOW) printf("Work took %f seconds\n", end - start);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec_omp, Test_Integrate_rec_omp_3) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 115/6.0;

    double start = omp_get_wtime();
    double ans = integral(a, b, c, d, h, f1);
    double end = omp_get_wtime();

    if (SHOW) printf("Work took %f seconds\n", end - start);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec_omp, Test_Integrate_rec_omp_4) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.632261;

    double start = omp_get_wtime();
    double ans = integral(a, b, c, d, h, f);
    double end = omp_get_wtime();

    if (SHOW) printf("Work took %f seconds\n", end - start);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec_omp, Test_Integrate_rec_omp_5) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.480587;

    double start = omp_get_wtime();
    double ans = integral(a, b, c, d, h, f2);
    double end = omp_get_wtime();

    if (SHOW) printf("Work took %f seconds\n", end - start);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec_omp, Test_Integrate_rec_omp_6) {
    double a = 2.0, b = 3.0;
    double c = 2.0, d = 3.0;
    double h = 0.001;
    double answer = -4.74391;

    double start = omp_get_wtime();
    double ans = integral(a, b, c, d, h, f2);
    double end = omp_get_wtime();

    if (SHOW) printf("Work took %f seconds\n", end - start);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec_omp, Test_Integrate_rec_omp_7) {
    double a = 0.0, b = 0.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.0;

    double start = omp_get_wtime();
    double ans = integral(a, b, c, d, h, f2);
    double end = omp_get_wtime();

    if (SHOW) printf("Work took %f seconds\n", end - start);

    ASSERT_NEAR(answer, ans, 1e-5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
