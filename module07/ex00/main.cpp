/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:18:07 by echavez-          #+#    #+#             */
/*   Updated: 2024/07/23 12:59:04 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	int x = 10, y = 20;

	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

	std::cout << "--------------------------------" << std::endl;

	std::string c = "string1", d = "string2";

	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	//test if equal
	std::cout << "--------------------------------" << std::endl;

	int a = 1, b = 1;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << "--------------------------------" << std::endl;
    int arr1[5] = {5, 2, 9, 1, 7};
    int arr2[5] = {3, 8, 6, 4, 0};

    // Demonstrate swap of whole arrays
    std::cout << "Before swap:" << std::endl;
    std::cout << "arr1: ";
    for (int i = 0; i < 5; ++i) std::cout << arr1[i] << " ";
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (int i = 0; i < 5; ++i) std::cout << arr2[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < 5; ++i) {
        swap(arr1[i], arr2[i]);
    }

    std::cout << "After swap:" << std::endl;
    std::cout << "arr1: ";
    for (int i = 0; i < 5; ++i) std::cout << arr1[i] << " ";
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (int i = 0; i < 5; ++i) std::cout << arr2[i] << " ";
    std::cout << std::endl;

    // Demonstrate min and max on swapped arrays
    int minVal = min(arr1[0], arr2[0]);
    std::cout << "Minimum of arr1[0] and arr2[0] is: " << minVal << std::endl;

    int maxVal = max(arr1[4], arr2[4]);
    std::cout << "Maximum of arr1[4] and arr2[4] is: " << maxVal << std::endl;

	return 0;
}
