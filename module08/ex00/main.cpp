/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:25:24 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/10 10:46:42 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
	std::vector<int>::iterator it;
    std::vector<int> v = {1, 2, 3, 4, 5};
	std::list<int>::iterator it2;
	std::list<int> l = {1, 2, 3, 4, 5};

	std::cout << "----- VECTOR TESTS -----" << std::endl;

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