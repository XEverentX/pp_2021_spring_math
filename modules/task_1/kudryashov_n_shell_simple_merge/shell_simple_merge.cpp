// Copyright 2021 Kudryashov Nikita

#include <random>
#include <ctime>
#include <iostream>
#include "../../../modules/task_1/kudryashov_n_shell_simple_merge/shell_simple_merge.h"

bool cmp_ascend(int a, int b) {
    return a < b;
}

std::vector<int> shell_sort(const std::vector<int>& in_vect,
    bool(*compare)(int, int)) {
    std::vector<int> in(in_vect);

    for (int s = in.size() / 2; s > 0; s /= 2) {
        for (int i = s; i < in.size(); i++) {
            for (int j = i - s; j >= 0 && !compare(in[j], in[j+s]); j -= s) {
                std::swap(in[j], in[j + s]);
            }
        }
    }

    return in;
}


std::vector<int> getRandomVect(unsigned int size) {
    std::mt19937 gen;
    gen.seed(time(0));

    std::vector<int> res;
    res.resize(size);

    for (int i = 0; i < size; i++) {
        res[i] = gen();
    }

    return res;
}

std::vector<int> merge(std::vector<int> a, std::vector<int> b,
    bool(*compare)(int, int)) {
    int i = 0, j = 0;
    std::vector<int> res;
    int full_size = a.size() + b.size();
    for (int k = 0; k < full_size; k++) {
        if (i == a.size()) {
            while (j < b.size()) {
                res.push_back(b[j]);
                j++;
            }
            break;
        }

        if (j == b.size()) {
            while (i < a.size()) {
                res.push_back(a[i]);
                i++;
            }
            break;
        }

        if (compare(a[i], b[j])) {
            res.push_back(a[i]);
            i++;
        } else {
            res.push_back(b[j]);
            j++;
        }
    }

    return res;
}

std::vector<int> shell_sort_simple_merge(const std::vector<int>& in_vect,
    int parts, bool(*compare)(int, int)) {
    std::vector<std::vector<int>> temp;
    std::vector<int> in(in_vect);
    int partial_size = in.size() / parts;
    int partial_size_remain = in.size() % parts;

    if (partial_size_remain == 0) {
        temp.resize(parts);
    } else {
        temp.resize(parts + 1);
    }

    int i, j;

    // Splitting into parts to sort.

    for (i = 0; i < temp.size() - 1; i++) {
        for (j = 0; j < partial_size; j++) {
            temp[i].push_back(in[i * partial_size + j]);
        }
    }

        // Filling the last one manually.

    if (partial_size_remain == 0) {
        for (int j = 0; j < partial_size; j++) {
            temp[i].push_back(in[i * partial_size + j]);
        }
    } else {
        for (int j = 0; j < partial_size_remain; j++) {
            temp[i].push_back(in[i * partial_size + j]);
        }
    }

    // Sorting with Shell.

    for (int k = 0; k < temp.size(); k++) {
        temp[k] = shell_sort(temp[k], compare);
    }

    // Merging like tree.

    int k = temp.size();
    std::vector<std::vector<int>> temp2;

    while (k != 1) {
        if (k % 2 == 0) {
            temp2.resize(k / 2);

            for (int h = 0; h < k; h += 2) {
                temp2[h/2] = merge(temp[h], temp[h + 1]);
            }

            k /= 2;
        } else {
            temp2.resize(k / 2 + 1);

            for (int h = 0; h < k - 1; h += 2) {
                temp2[h/2] = merge(temp[h], temp[h + 1]);
            }

            temp2[temp2.size() - 1] = temp[temp.size() - 1];

            k = k / 2 + 1;
        }

        temp = temp2;
    }

    in = temp[0];

    return in;
}
