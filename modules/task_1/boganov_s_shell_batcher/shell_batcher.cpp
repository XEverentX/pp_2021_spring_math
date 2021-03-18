// Copyright 2021 Boganov Sergei

#include "../../../modules/task_1/boganov_s_shell_batcher/shell_batcher.h"

std::vector<int> getRandomVector(int size) {
    std::random_device dev;
    std::mt19937 gen(dev());
    std::vector<int> vec(size);
    for (int  i = 0; i < size; i++) {
        vec[i] = gen() % 100;
    }
    return vec;
}

std::vector<int> sortShell(const std::vector<int>& vec) {
    std::vector<int> res(vec);
    int size = static_cast<int>(res.size());
    for (int step = size / 2; step > 0; step /= 2) {
        for (int i = step; i < size; i++) {
            for (int j = i - step; j >= 0 && res[j] > res[j + step] ; j -= step) {
                std::swap(res[j], res[j + step]);
            }
        }
    }
    return res;
}

std::vector<int> evenOrOddMerge(const std::vector<int>& vec1, const std::vector<int>& vec2, const mergeType& type) {
    int size1 = static_cast<int>(vec1.size());
    int size2 = static_cast<int>(vec2.size());
    int res_size = 0, i1 = 0, i2 = 0;

    switch (type) {
        case mergeType::even:
            res_size = (size1 + 1) / 2 + (size2 + 1) / 2;
            i1 = 0;
            i2 = 0;
            break;
        case mergeType::odd:
            res_size = size1 / 2 + size2 / 2;
            i1 = 1;
            i2 = 1;
            break;
    }

    std::vector<int> res;
    res.reserve(res_size);

    while ((i1 < size1) && (i2 < size2)) {
        if (vec1[i1] <= vec2[i2]) {
            res.push_back(vec1[i1]);
            i1 += 2;
        } else {
            res.push_back(vec2[i2]);
            i2 += 2;
        }
    }

    if (i2 >= size2) {
        for (int i = i1; i < size1; i += 2) {
            res.push_back(vec1[i]);
        }
    } else {
        for (int i = i2; i < size2; i += 2) {
            res.push_back(vec2[i]);
        }
    }

    return res;
}

std::vector<int> mergeBatcher(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    int size1 = static_cast<int>(vec1.size());
    int size2 = static_cast<int>(vec2.size());
    int res_size = size1 + size2;

    std::vector<int> res;
    res.reserve(res_size);

    if (size1 == size2) {
        for (int i = 0; i < size1; i++) {
            res.push_back(vec1[i]);
            res.push_back(vec2[i]);
        }
    } else if (size1 == size2 + 2 || size2 == size1 + 2) {
        int i = 0;
        int min_size = std::min(size1, size2);
        for (; i < min_size; i++) {
            res.push_back(vec1[i]);
            res.push_back(vec2[i]);
        }
        if (size1 == size2 + 2) {
            res.push_back(vec1[i]);
            res.push_back(vec1[i + 1]);
        } else {
            res.push_back(vec2[i]);
            res.push_back(vec2[i + 1]);
        }
    } else {
        throw std::runtime_error("Vector sizes must be equal or different by 2");
    }

    for (int i = 1; i < res_size; i++) {
        if (res[i] < res[i - 1]) {
            std::swap(res[i], res[i - 1]);
        }
    }

    return res;
}

std::vector<int> sortShellWithMergeBatcher(const std::vector<int>& vec) {
    int size = static_cast<int>(vec.size());
    int half_size = (size + 1) / 2;

    std::vector<int> vec1, vec2;
    vec1.reserve(half_size);
    vec2.reserve(half_size);

    for (int i = 0; i < half_size; i++) {
        vec1.push_back(vec[i]);
    }
    for (int i = half_size; i < size; i++) {
        vec2.push_back(vec[i]);
    }

    vec1 = sortShell(vec1);
    vec2 = sortShell(vec2);

    std::vector<int> evenRes = evenOrOddMerge(vec1, vec2, mergeType::even);
    std::vector<int> oddRes = evenOrOddMerge(vec1, vec2, mergeType::odd);
    std::vector<int> res = mergeBatcher(evenRes, oddRes);

    return res;
}
