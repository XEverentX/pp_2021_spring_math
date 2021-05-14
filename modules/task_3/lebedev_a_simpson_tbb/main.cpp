// Copyright 2021 DLebedev Alexander

#include<tbb/tbb.h>

#include <gtest/gtest.h>
#include <cmath>

#include "./simpson.h"

constexpr double eps = 1e-6;

const auto f1 = [] (double x, double y) -> double {
    return sin(x * x) + y * y * x;
};

const auto f2 = [] (double x, double y) -> double {
    return x * x * (x + y) - 3 * y * y;
};

const auto f3 = [] (double x, double y) -> double {
    return x + y * cos(sin(x));
};

TEST(simpson_f1, test_simson_1) {
    double a = 0.;
    double b = 1.;
    double c = 0.;
    double d = 1.;
    int nx = 1000;
    int ny = 1000;

    double expected = 0.476934968390048;

    ASSERT_NEAR(expected, integrate(f1, a, b, c, d, nx, ny), eps);
}

TEST(simpson_f1, test_simson_2) {
    double a = 10.;
    double b = 15.1;
    double c = 100.;
    double d = 112.5;
    int nx = 1000;
    int ny = 1000;

    double expected = 9042373.68352822;

    ASSERT_NEAR(expected, integrate(f1, a, b, c, d, nx, ny), eps);
}

TEST(simpson_f2, test_simson_1) {
    double a = 0.;
    double b = 1.;
    double c = 0.;
    double d = 1.;
    int nx = 1000;
    int ny = 1000;

    double expected = -0.583333333333333;

    ASSERT_NEAR(expected, integrate(f2, a, b, c, d, nx, ny), eps);
}

TEST(simpson_f2, test_simson_2) {
    double a = 10.;
    double b = 15.1;
    double c = 100.;
    double d = 112.5;
    int nx = 1000;
    int ny = 1000;

    double expected = -948794.4215625;

    ASSERT_NEAR(expected, integrate(f2, a, b, c, d, nx, ny), eps);
}

TEST(simpson_f3, test_simson_1) {
    double a = 0.;
    double b = 1.;
    double c = 0.;
    double d = 1.;
    int nx = 1000;
    int ny = 1000;

    double expected = 0.934370019788488;

    ASSERT_NEAR(expected, integrate(f3, a, b, c, d, nx, ny), eps);
}

TEST(simpson_f3, test_simson_2) {
    double a = 10.;
    double b = 15.1;
    double c = 100.;
    double d = 112.5;
    int nx = 1000;
    int ny = 1000;

    double expected = 5698.37277067144;

    ASSERT_NEAR(expected, integrate(f3, a, b, c, d, nx, ny), eps);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    tbb::task_scheduler_init init(4);

    return RUN_ALL_TESTS();
}
