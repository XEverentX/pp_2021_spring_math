// Copyright 2021 Devlikamov Vladislav

#include <gtest/gtest.h>
#include <cmath>
#include <tbb/tick_count.h>
#include "./integrate_rec_tbb.h"
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

TEST(Integrate_rec, Test_Integrate_rec_tbb_1) {
    double a = 1.0, b = 2.0;
    double c = 3.0, d = 4.0;
    double h = 0.001;
    double answer = -0.0813902;

    tbb::tick_count start = tbb::tick_count::now();
    double ans = integral(a, b, c, d, h, f);
    tbb::tick_count end = tbb::tick_count::now();

    if (SHOW) printf("Work took %f seconds\n",(end-start).seconds());

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_tbb_2) {
    double a = 0.0, b = 2.0;
    double c = 1.0, d = 2.0;
    double h = 0.0005;
    double answer = 250/3.0;

    tbb::tick_count start = tbb::tick_count::now();
    double ans = integral(a, b, c, d, h, f1);
    tbb::tick_count end = tbb::tick_count::now();

    if (SHOW) printf("Work took %f seconds\n",(end-start).seconds());

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_tbb_3) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 115/6.0;

    tbb::tick_count start = tbb::tick_count::now();
    double ans = integral(a, b, c, d, h, f1);
    tbb::tick_count end = tbb::tick_count::now();

    if (SHOW) printf("Work took %f seconds\n",(end-start).seconds());

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_tbb_4) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.632261;

    tbb::tick_count start = tbb::tick_count::now();
    double ans = integral(a, b, c, d, h, f);
    tbb::tick_count end = tbb::tick_count::now();

    if (SHOW) printf("Work took %f seconds\n",(end-start).seconds());

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_tbb_5) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.480587;

    tbb::tick_count start = tbb::tick_count::now();
    double ans = integral(a, b, c, d, h, f2);
    tbb::tick_count end = tbb::tick_count::now();

    if (SHOW) printf("Work took %f seconds\n",(end-start).seconds());

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_tbb_6) {
    double a = 2.0, b = 3.0;
    double c = 2.0, d = 3.0;
    double h = 0.001;
    double answer = -4.74391;

    tbb::tick_count start = tbb::tick_count::now();
    double ans = integral(a, b, c, d, h, f2);
    tbb::tick_count end = tbb::tick_count::now();

    if (SHOW) printf("Work took %f seconds\n",(end-start).seconds());

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_tbb_7) {
    double a = 0.0, b = 0.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.0;

    tbb::tick_count start = tbb::tick_count::now();
    double ans = integral(a, b, c, d, h, f2);
    tbb::tick_count end = tbb::tick_count::now();

    if (SHOW) printf("Work took %f seconds\n",(end-start).seconds());
    
    ASSERT_NEAR(answer, ans, 1e-5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
