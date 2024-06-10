/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:54:59 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/10 12:55:35 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	std::cout << "----- 10,000 TEST -----" << std::endl;
    try {
        Span sp(10000);
        std::vector<int> largeRange(10000);

        // Fill the vector with 10000 sequential numbers
        for (int i = 0; i < 10000; ++i) {
            largeRange[i] = i;
        }

        // Add the large range to the span
        sp.addRange(largeRange.begin(), largeRange.end());

        // Print the shortest and longest span
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

	std::cout << "----- EXCEPTION TEST -----" << std::endl;

	try {
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
	} catch (const std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "----- SUBJECT TEST -----" << std::endl;

	try {
		Span sp(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

    return 0;
}