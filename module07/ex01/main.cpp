/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:05:49 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 13:22:45 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    // Test with int array and print function
    std::cout << "Int array: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    // Test with double array and print function
    std::cout << "Double array: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;

    return 0;
}