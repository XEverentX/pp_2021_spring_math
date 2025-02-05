// Copyright 2021 Kudryashov Nikita

#include "../../../modules/task_3/kudryashov_n_shell_simple_merge_tbb/shell_simple_merge_tbb.h"
#include <tbb/task_scheduler_init.h>
#include <tbb/parallel_for.h>
#include <random>
#include <ctime>
#include <iostream>
#include <utility>

bool cmp_ascend(int a, int b) {
    return a < b;
}

std::vector<int> shell_sort(const std::vector<int>& in_vect,
    bool(*compare)(int, int)) {
    std::vector<int> in(in_vect);

    int size = static_cast<int>(in.size());
    for (int s = size / 2; s > 0; s /= 2) {
        for (int i = s; i < size; i++) {
            for (int j = i - s; j >= 0 && !compare(in[j], in[j+s]); j -= s) {
                std::swap(in[j], in[j + s]);
            }
        }
    }

    return in;
}


std::vector<int> getRandomVect(unsigned int size) {
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));

    std::vector<int> res;
    res.resize(size);

    for (unsigned int i = 0; i < size; i++) {
        res[i] = gen();
    }

    return res;
}

std::vector<int> merge(std::vector<int> a, std::vector<int> b,
    bool(*compare)(int, int)) {
    int i = 0, j = 0;
    std::vector<int> res;
    int a_size = static_cast<int>(a.size());
    int b_size = static_cast<int>(b.size());
    int full_size = a_size + b_size;
    for (int k = 0; k < full_size; k++) {
        if (i == a_size) {
            while (j < b_size) {
                res.push_back(b[j]);
                j++;
            }
            break;
        }

        if (j == b_size) {
            while (i < a_size) {
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
    int in_size = static_cast<int>(in.size());
    int partial_size = in_size / parts;
    int partial_size_remain = in_size % parts;

    if (partial_size_remain == 0) {
        temp.resize(parts);
    } else {
        temp.resize(parts + 1);
    }

    int i, j;
    int temp_size = static_cast<int>(temp.size());
    // Splitting into parts to sort.


    for (i = 0; i < temp_size - 1; i++) {
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

    for (int k = 0; k < temp_size; k++) {
        temp[k] = shell_sort(temp[k], compare);
    }

    // Merging like tree.

    int k = static_cast<int>(temp.size());
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

std::vector<int> shell_sort_simple_merge_tbb(const std::vector<int>& in_vect,
    int parts, bool(*compare)(int, int)) {
    std::vector<std::vector<int>> temp;
    std::vector<int> in(in_vect);
    int in_size = static_cast<int>(in.size());
    int partial_size = in_size / parts;
    int partial_size_remain = in_size % parts;

    if (partial_size_remain == 0) {
        temp.resize(parts);
    } else {
        temp.resize(parts + 1);
    }

    int i, j;
    int temp_size = static_cast<int>(temp.size());
    // Splitting into parts to sort.


    for (i = 0; i < temp_size - 1; i++) {
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

    tbb::task_scheduler_init init;

    tbb::parallel_for(tbb::blocked_range<int>(0, temp_size),
                       [&temp, compare](tbb::blocked_range<int> r) {
        for (int k = r.begin(); k < r.end(); k++) {
            temp[k] = shell_sort(temp[k], compare);
        }
    });

    // Merging like tree.

    int k = static_cast<int>(temp.size());
    std::vector<std::vector<int>> temp2;

    while (k != 1) {
        if (k % 2 == 0) {
            temp2.resize(k / 2);

            tbb::parallel_for(tbb::blocked_range<int>(0, k, 2),
                       [&temp2, &temp](tbb::blocked_range<int> r) {
                for (int h = r.begin(); h < r.end(); h += 2) {
                    temp2[h/2] = merge(temp[h], temp[h + 1]);
                }
            });

            k /= 2;
        } else {
            temp2.resize(k / 2 + 1);

            tbb::parallel_for(tbb::blocked_range<int>(0, k, 2),
                       [&temp2, &temp](tbb::blocked_range<int> r) {
                for (int h = r.begin(); h < r.end() - 1; h += 2) {
                    temp2[h/2] = merge(temp[h], temp[h + 1]);
                }
            });

            temp2[temp2.size() - 1] = temp[temp.size() - 1];

            k = k / 2 + 1;
        }

        temp = temp2;
    }

    in = temp[0];

    return in;
}
