// Copyright 2021 Boganov Sergei

#include "../../../modules/task_3/boganov_s_shell_batcher_tbb/shell_batcher.h"

std::vector<int> getRandomVector(int size) {
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(0)));
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
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

std::vector<std::vector<int>> separatedVector(const std::vector<int>& vec, int number_of_parts) {
    int size = static_cast<int>(vec.size());
    std::vector<std::vector<int>> res;
    res.reserve(number_of_parts);

    int size_part = size / number_of_parts;
    int rem = size % number_of_parts;
    int start = 0, finish = size_part;

    for (int i = 0; i < number_of_parts; i++) {
        if (rem > 0) {
            finish += 1;
            rem--;
        }
        std::vector<int> temp(vec.begin() + start, vec.begin() + finish);
        res.push_back(temp);
        start = finish;
        finish += size_part;
    }

    return res;
}

std::vector<int> SortShellSeq(const std::vector<int>& vec, int number_of_parts) {
    std::vector<std::vector<int>> temp = separatedVector(vec, number_of_parts);

    for (int i = 0; i < number_of_parts; i++) {
        temp[i] = sortShell(temp[i]);
    }

    return evenOddhMergeBatcherSeq(temp, number_of_parts);
}

std::vector<int> SortShellTBB(const std::vector<int>& vec, int number_of_parts) {
    std::vector<std::vector<int>> temp = separatedVector(vec, number_of_parts);
    tbb::task_scheduler_init init;

    tbb::parallel_for(tbb::blocked_range<int>(0, number_of_parts, 1),
        [&temp](const tbb::blocked_range<int> &r) {
            int begin = r.begin();
            int end = r.end();
            for (int i = begin; i != end; i++) {
                temp[i] = sortShell(temp[i]);
            }
        }, tbb::simple_partitioner());

    return evenOddhMergeBatcherTBB(temp, number_of_parts);
}

std::vector<int> evenOddhMergeBatcherSeq(const std::vector<std::vector<int>>& vec, int number_of_parts) {
    std::vector<std::vector<int>> temp1(vec);
    std::vector<int> evenTemp, oddTemp;

    int k = number_of_parts;

    while (k != 1) {
        std::vector<std::vector<int>> temp2(k / 2 + k % 2);
        std::vector<std::pair<std::vector<int>, std::vector<int>>> temp_pair(k / 2);
        int p = 0;
        for (int i = 0; i < k - 1; i += 2, p++) {
            temp_pair[p].first = temp1[i];
            temp_pair[p].second = temp1[i + 1];
        }

        int size = static_cast<int>(temp_pair.size());

        for (p = 0; p < size; p++) {
            evenTemp = evenOrOddMerge(temp_pair[p].first, temp_pair[p].second, mergeType::even);
            oddTemp = evenOrOddMerge(temp_pair[p].first, temp_pair[p].second, mergeType::odd);
            temp2[p] = mergeBatcher(evenTemp, oddTemp);
        }

        if (k % 2 == 1) {
            temp2[size] = temp1[k - 1];
        }
        temp1 = temp2;
        k = (k + 1) / 2;
    }

    return temp1[0];
}

std::vector<int> evenOddhMergeBatcherTBB(const std::vector<std::vector<int>>& vec, int number_of_parts) {
    std::vector<std::vector<int>> temp1(vec);

    int k = number_of_parts;

    while (k != 1) {
        std::vector<std::vector<int>> temp2(k / 2 + k % 2);
        std::vector<std::pair<std::vector<int>, std::vector<int>>> temp_pair(k / 2);
        int p = 0;
        for (int i = 0; i < k - 1; i += 2, p++) {
            temp_pair[p].first = temp1[i];
            temp_pair[p].second = temp1[i + 1];
        }

        int size = static_cast<int>(temp_pair.size());

        tbb::parallel_for(tbb::blocked_range<int>(0, size, 1),
        [&temp2, &temp_pair](const tbb::blocked_range<int> &r) {
            std::vector<int> evenTemp, oddTemp;
            int begin = r.begin();
            int end = r.end();
            for (int i = begin; i != end; i++) {
                evenTemp = evenOrOddMerge(temp_pair[i].first, temp_pair[i].second, mergeType::even);
                oddTemp = evenOrOddMerge(temp_pair[i].first, temp_pair[i].second, mergeType::odd);
                temp2[i] = mergeBatcher(evenTemp, oddTemp);
            }
        }, tbb::simple_partitioner());

        if (k % 2 == 1) {
            temp2[size] = temp1[k - 1];
        }
        temp1 = temp2;
        k = (k + 1) / 2;
    }

    return temp1[0];
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
    int i, j, count;

    std::vector<int> res;
    res.reserve(res_size);

    for (i = 0, j = 0, count = 0; i < size1 && j < size2; i++, j++, count += 2) {
        res.push_back(vec1[i]);
        res.push_back(vec2[j]);
    }

    if (i < size1 && j >= size2) {
        for (int k = count; k < res_size; k++, i++) {
            res.push_back(vec1[i]);
        }
    }

    for (int i = 1; i < res_size; i++) {
        if (res[i] < res[i - 1]) {
            std::swap(res[i], res[i - 1]);
        }
    }

    return res;
}
