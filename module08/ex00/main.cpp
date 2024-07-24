/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:25:24 by echavez-          #+#    #+#             */
/*   Updated: 2024/07/24 11:28:46 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"

// Templated function to print elements of any container
template <typename Container>
void printContainer(const Container& container) {
    std::cout << "Container elements: {";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << ", ";
	}
	std::cout << "}";
	std::cout << std::endl;
}

int main() {
	//vector declaration
	std::vector<int>::iterator it;
	std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
	//list declaration
	std::list<int>::iterator it2;
	std::list<int> l;
	l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

	std::cout << "----- VECTOR TESTS -----" << std::endl;

	printContainer(v);
    try {
        it = easyfind(v, 3);
        std::cout << "[vector] Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "[vector] " << e.what() << std::endl;
    }
    try {
        it = easyfind(v, 6);
        std::cout << "[vector] Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "[vector] " << e.what() << std::endl;
    }

	std::cout << "----- LIST TESTS -----" << std::endl;

	printContainer(l);
	try {
		it2 = easyfind(l, 3);
		std::cout << "[list] Found: " << *it2 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "[list] " << e.what() << std::endl;
	}
	try {
		it2 = easyfind(l, 6);
		std::cout << "[list] Found: " << *it2 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "[list] " << e.what() << std::endl;
	}

    return 0;
}