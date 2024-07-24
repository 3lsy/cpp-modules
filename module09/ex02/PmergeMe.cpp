/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:54:05 by echavez-          #+#    #+#             */
/*   Updated: 2024/07/24 16:46:12 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::insertionSort(std::vector<int>& arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > left && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

void PmergeMe::merge(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (size_t i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (size_t j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::mergeInsertSort(std::vector<int>& arr, size_t left, size_t right) {
    if (right - left + 1 <= INSERTION_SORT_THRESHOLD) {
        // If the segment is small, use insertion sort
        insertionSort(arr, left, right);
    } else {
        if (left < right) {
            size_t mid = left + (right - left) / 2;

            // Recursively sort first and second halves
            mergeInsertSort(arr, left, mid);
            mergeInsertSort(arr, mid + 1, right);

            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }
}

void PmergeMe::insertionSort(std::list<int>& arr) {
    for (auto it = std::next(arr.begin()); it != arr.end(); ++it) {
        int key = *it;
        auto j = it;
        while (j != arr.begin() && *std::prev(j) > key) {
            *j = *std::prev(j);
            --j;
        }
        *j = key;
    }
}

void PmergeMe::merge(std::list<int>& leftList, std::list<int>& rightList, std::list<int>& mergedList) {
    auto itL = leftList.begin();
    auto itR = rightList.begin();

    while (itL != leftList.end() && itR != rightList.end()) {
        if (*itL <= *itR) {
            mergedList.push_back(*itL);
            ++itL;
        } else {
            mergedList.push_back(*itR);
            ++itR;
        }
    }

    while (itL != leftList.end()) {
        mergedList.push_back(*itL);
        ++itL;
    }

    while (itR != rightList.end()) {
        mergedList.push_back(*itR);
        ++itR;
    }
}

void PmergeMe::mergeInsertSort(std::list<int>& arr) {
    if (arr.size() <= INSERTION_SORT_THRESHOLD) {
        // If the segment is small, use insertion sort
        insertionSort(arr);
    } else {
        std::list<int> leftList, rightList;
        auto it = arr.begin();
        std::advance(it, arr.size() / 2);

        leftList.splice(leftList.begin(), arr, arr.begin(), it);
        rightList.splice(rightList.begin(), arr, it, arr.end());

        mergeInsertSort(leftList);
        mergeInsertSort(rightList);

        arr.clear();
        merge(leftList, rightList, arr);
    }
}

void PmergeMe::sort(const std::vector<int>& input) {
    std::vector<int> vectorData(input.begin(), input.end());

    // Time the merge-insertion sort for vector
    clock_t startVector = clock();
    mergeInsertSort(vectorData, 0, vectorData.size() - 1);
    clock_t endVector = clock();

    std::list<int> listData(input.begin(), input.end());

    // Time the merge-insertion sort for list
    clock_t startList = clock();
    mergeInsertSort(listData);
    clock_t endList = clock();

    // Print the unsorted input
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Print the sorted vector
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = vectorData.begin(); it != vectorData.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Calculate and print the duration for vector sort
    double vectorDuration = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1e6; // microseconds
    double listDuration = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1e6; // microseconds

    std::cout << "Time to process a range of " << vectorData.size() << " elements with std::vector : " << vectorDuration << " us" << std::endl;
    std::cout << "Time to process a range of " << listData.size() << " elements with std::list : " << listDuration << " us" << std::endl;
}


/*
void PmergeMe::insertionSort(std::vector<int>& arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > left && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

void PmergeMe::mergeSort(std::vector<int>& arr, size_t left, size_t right) {
    if (right - left + 1 <= INSERTION_SORT_THRESHOLD) {
        insertionSort(arr, left, right);
    } else {
        if (left < right) {
            size_t mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }
}

void PmergeMe::merge(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (size_t i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (size_t j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::insertionSort(std::list<int>& arr) {
    for (std::list<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        int key = *it;
        std::list<int>::iterator j = it;
        while (j != arr.begin() && *std::prev(j) > key) {
            *j = *std::prev(j);
            --j;
        }
        *j = key;
    }
}

void PmergeMe::sort(const std::vector<int>& input) {
    // Output unsorted data
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Sorting with std::vector
    std::vector<int> vectorData(input.begin(), input.end());
    clock_t startVector = clock();
    mergeSort(vectorData, 0, vectorData.size() - 1);
    clock_t endVector = clock();

    // Sorting with std::list
    std::list<int> listData(input.begin(), input.end());
    clock_t startList = clock();
    insertionSort(listData);
    clock_t endList = clock();

    // Output sorted data
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = vectorData.begin(); it != vectorData.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Timing results
    double vectorDuration = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC;
    double listDuration = static_cast<double>(endList - startList) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << vectorData.size() << " elements with std::vector : " << vectorDuration << " seconds" << std::endl;
    std::cout << "Time to process a range of " << listData.size() << " elements with std::list : " << listDuration << " seconds" << std::endl;
}
*/