#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <algorithm>

template<typename T>
bool is_sorted(const std::vector<T>& vec) {
    if (vec.size() <= 1) return true;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        if (vec[i + 1] < vec[i]) return false;
    }
    return true;
}

template<typename T>
void insertion_sort_range(std::vector<T>& A, int left, int right) {
    for (int j = left + 1; j <= right; ++j) {
        T key = A[j];
        int i = j - 1;
        while (i >= left && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}
template<typename T> void insertion_sort(std::vector<T>& A) { if(!A.empty()) insertion_sort_range(A, 0, A.size() - 1); }

template<typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = A[p + i];
    for (int j = 0; j < n2; ++j) R[j] = A[q + 1 + j];
    
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { A[k] = L[i]; i++; } 
        else { A[k] = R[j]; j++; }
        k++;
    }
    while (i < n1) { A[k] = L[i]; i++; k++; }
    while (j < n2) { A[k] = R[j]; j++; k++; }
}

template<typename T>
void merge_sort_recursive(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        merge_sort_recursive(A, p, q);
        merge_sort_recursive(A, q + 1, r);
        merge(A, p, q, r);
    }
}
template<typename T> void merge_sort(std::vector<T>& A) { if(!A.empty()) merge_sort_recursive(A, 0, A.size() - 1); }

template<typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

template<typename T>
void quicksort_recursive(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort_recursive(A, p, q - 1);
        quicksort_recursive(A, q + 1, r);
    }
}
template<typename T> void quicksort(std::vector<T>& A) { if(!A.empty()) quicksort_recursive(A, 0, A.size() - 1); }

template<typename T>
void hybrid_quicksort_recursive(std::vector<T>& A, int p, int r) {
    if (p < r) {
        if (r - p < 32) { 
            insertion_sort_range(A, p, r);
        } else {
            int q = partition(A, p, r);
            hybrid_quicksort_recursive(A, p, q - 1);
            hybrid_quicksort_recursive(A, q + 1, r);
        }
    }
}
template<typename T> void hybrid_quicksort(std::vector<T>& A) { if(!A.empty()) hybrid_quicksort_recursive(A, 0, A.size() - 1); }

#endif
