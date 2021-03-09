// Copyright 2021 Devlikamov Vladislav

#include <gtest/gtest.h>
#include "./integrate_rec.h"

double f(double x, double y) {
    return sin(x + y)*cos(x);
}

double f1(double x, double y) {
    return 10*x*x*x + 5*x*x + 15;
}

double f2(double x, double y) {
    return sin(x + y)*x*x + cos(x + y)*x;
}

TEST(Integrate_rec, Test_Integrate_rec_1) {
    double a = 1.0, b = 2.0;
    double c = 3.0, d = 4.0;
    double h = 0.001;
    double answer = -0.0813902;

    double ans = integral(a, b, c, d, h, f);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_2) {
    double a = 0.0, b = 2.0;
    double c = 1.0, d = 2.0;
    double h = 0.0005;
    double answer = 250/3.0;

    double ans = integral(a, b, c, d, h, f1);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_3) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 115/6.0;

    double ans = integral(a, b, c, d, h, f1);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_4) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.632261;

    double ans = integral(a, b, c, d, h, f);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_5) {
    double a = 0.0, b = 1.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.480587;

    double ans = integral(a, b, c, d, h, f2);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_6) {
    double a = 2.0, b = 3.0;
    double c = 2.0, d = 3.0;
    double h = 0.001;
    double answer = -4.74391;

    double ans = integral(a, b, c, d, h, f2);

    ASSERT_NEAR(answer, ans, 1e-5);
}

TEST(Integrate_rec, Test_Integrate_rec_7) {
    double a = 0.0, b = 0.0;
    double c = 0.0, d = 1.0;
    double h = 0.001;
    double answer = 0.0;

    double ans = integral(a, b, c, d, h, f2);

    ASSERT_NEAR(answer, ans, 1e-5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
