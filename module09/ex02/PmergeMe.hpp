/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:54:25 by echavez-          #+#    #+#             */
/*   Updated: 2024/07/24 16:10:34 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

class PmergeMe {
public:
    void sort(const std::vector<int>& input);

private:
    static const size_t INSERTION_SORT_THRESHOLD = 10;

    // For std::vector
    void insertionSort(std::vector<int>& arr, size_t left, size_t right);
    void merge(std::vector<int>& arr, size_t left, size_t mid, size_t right);
    void mergeInsertSort(std::vector<int>& arr, size_t left, size_t right);

    // For std::list
    void insertionSort(std::list<int>& arr);
    void merge(std::list<int>& leftList, std::list<int>& rightList, std::list<int>& mergedList);
    void mergeInsertSort(std::list<int>& arr);
};

/*
class PmergeMe {
public:
    void sort(const std::vector<int>& input);
private:
    static const size_t INSERTION_SORT_THRESHOLD = 10;
    
    void insertionSort(std::vector<int>& arr, size_t left, size_t right);
    void mergeSort(std::vector<int>& arr, size_t left, size_t right);
    void merge(std::vector<int>& arr, size_t left, size_t mid, size_t right);

    void insertionSort(std::list<int>& arr);
};
*/

#endif