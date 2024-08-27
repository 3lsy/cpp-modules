/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:53:11 by echavez-          #+#    #+#             */
/*   Updated: 2024/08/27 16:29:54 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Function to check for duplicates in a vector
bool hasDuplicates(const std::vector<int>& input) {
    std::set<int> uniqueElements;
    for (size_t i = 0; i < input.size(); ++i) {
        if (uniqueElements.find(input[i]) != uniqueElements.end()) {
            return true;
        }
        uniqueElements.insert(input[i]);
    }
    return false;
}

// Function to check for duplicates in a list
bool hasDuplicates(const std::list<int>& input) {
    std::set<int> uniqueElements;
    for (std::list<int>::const_iterator it = input.begin(); it != input.end(); ++it) {
        if (uniqueElements.find(*it) != uniqueElements.end()) {
            return true;
        }
        uniqueElements.insert(*it);
    }
    return false;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    std::vector<int> vecInput;
    std::list<int> listInput;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: All inputs must be positive integers." << std::endl;
            return 1;
        }
        vecInput.push_back(num);
        listInput.push_back(num);
    }
    if (hasDuplicates(vecInput)) {
        std::cerr << "Error: Duplicate elements detected in input." << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < vecInput.size(); ++i) {
        std::cout << vecInput[i] << " ";
    }
    std::cout << std::endl;

	PmergeMe sorter;
    clock_t startVec = std::clock();
    sorter.mergeInsertSort(vecInput);
    clock_t endVec = std::clock();

    clock_t startList = std::clock();
    sorter.mergeInsertSort(listInput);
    clock_t endList = std::clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vecInput.size(); ++i) {
        std::cout << vecInput[i] << " ";
    }
    std::cout << std::endl;

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double timeList = static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << vecInput.size() << " elements with std::vector: " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << listInput.size() << " elements with std::list: " << timeList << " us" << std::endl;

    return 0;
}

/*
//main to test 3000 elements
int main(int argc, char** argv) {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate 3000 random integers between 1 and 100000
    std::vector<int> input(3000);
    for (size_t i = 0; i < input.size(); ++i) {
        input[i] = std::rand() % 100000 + 1; // Random number between 1 and 100000
    }

    PmergeMe sorter;
    sorter.sort(input);
    return 0;
}
*/