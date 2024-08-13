/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:53:11 by echavez-          #+#    #+#             */
/*   Updated: 2024/08/13 14:54:46 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: invalid number of arguments\n";
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i) {
        try {
            int value = std::stoi(argv[i]);
            if (value < 0) {
                std::cerr << "Error: negative values are not allowed\n";
                return 1;
            }
            input.push_back(value);
        } catch (...) {
            std::cerr << "Error: invalid input\n";
            return 1;
        }
    }

    PmergeMe sorter;
    sorter.sort(input);
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