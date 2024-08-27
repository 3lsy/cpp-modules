/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:54:05 by echavez-          #+#    #+#             */
/*   Updated: 2024/08/27 16:30:41 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {
}

// Merge function for merging two sorted halves for std::vector
void PmergeMe::merge(std::vector<int>& vec, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftVec(n1);
    std::vector<int> rightVec(n2);

    for (int i = 0; i < n1; ++i)
        leftVec[i] = vec[left + i];
    for (int i = 0; i < n2; ++i)
        rightVec[i] = vec[middle + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];
            i++;
        } else {
            vec[k] = rightVec[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

// Merge-Insertion Sort function for std::vector
void PmergeMe::mergeInsertSort(std::vector<int>& vec, int left, int right) {
    if (left < right) {
        if (right - left < 10) {  // Insertion sort for small segments
            for (int i = left + 1; i <= right; ++i) {
                int key = vec[i];
                int j = i - 1;
                while (j >= left && vec[j] > key) {
                    vec[j + 1] = vec[j];
                    j--;
                }
                vec[j + 1] = key;
            }
        } else {
            int middle = left + (right - left) / 2;
            mergeInsertSort(vec, left, middle);
            mergeInsertSort(vec, middle + 1, right);
            merge(vec, left, middle, right);
        }
    }
}

void PmergeMe::mergeInsertSort(std::vector<int>& vec) {
    mergeInsertSort(vec, 0, vec.size() - 1);
}

// Merge function for merging two sorted halves for std::list
void PmergeMe::mergeList(std::list<int>::iterator leftStart, std::list<int>::iterator leftEnd,
               std::list<int>::iterator rightStart, std::list<int>::iterator rightEnd) {
    std::list<int> mergedList;
    std::list<int>::iterator left = leftStart;
    std::list<int>::iterator right = rightStart;

    while (left != leftEnd && right != rightEnd) {
        if (*left <= *right) {
            mergedList.push_back(*left);
            ++left;
        } else {
            mergedList.push_back(*right);
            ++right;
        }
    }
    while (left != leftEnd) {
        mergedList.push_back(*left);
        ++left;
    }
    while (right != rightEnd) {
        mergedList.push_back(*right);
        ++right;
    }
    std::copy(mergedList.begin(), mergedList.end(), leftStart);
}

// Merge-Insertion Sort function for std::list
void PmergeMe::mergeInsertSort(std::list<int>& lst) {
    if (lst.size() <= 1) return;

    if (lst.size() < 10) {  // Insertion sort for small lists
        for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it) {
            int key = *it;
            std::list<int>::iterator j = it;
            --j;
            while (j != lst.begin() && *j > key) {
                std::list<int>::iterator next = j;
                ++next;
                *next = *j;
                --j;
            }
            if (j == lst.begin() && *j > key) {
                *it = *j;
                *j = key;
            } else {
                std::list<int>::iterator next = j;
                ++next;
                *next = key;
            }
        }
    } else {
        std::list<int>::iterator middle = lst.begin();
        std::advance(middle, lst.size() / 2);
        std::list<int> left(lst.begin(), middle);
        std::list<int> right(middle, lst.end());

        mergeInsertSort(left);
        mergeInsertSort(right);

        mergeList(left.begin(), left.end(), right.begin(), right.end());
        lst.clear();
        lst.splice(lst.begin(), left);
        lst.splice(lst.end(), right);
    }
}
