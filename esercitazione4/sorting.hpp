#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <algorithm>

template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    if (vec.empty()) return true;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i + 1] < vec[i]) return false;
    }
    return true;
}

template<typename T>
void bubble_sort(std::vector<T>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = n - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }
}

template<typename T>
void insertion_sort(std::vector<T>& A) {
    for (size_t j = 1; j < A.size(); ++j) {
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

template<typename T>
void selection_sort(std::vector<T>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[min_idx]) min_idx = j;
        }
        std::swap(A[i], A[min_idx]);
    }
}
#endif
