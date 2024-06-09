/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:18:07 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 12:49:42 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main() {
	int x = 10, y = 20;

	std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

	std::cout << "min(x, y) = " << min(x, y) << std::endl;
    std::cout << "max(x, y) = " << max(x, y) << std::endl;

	std::cout << "--------------------------------" << std::endl;

	std::string c = "string1", d = "string2";

	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    swap(x, y);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	//test if equal
	std::cout << "--------------------------------" << std::endl;

	int a = 1, b = 1;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

	std::cout << "min(a, b) = " << min(a, b) << std::endl;
    std::cout << "max(a, b) = " << max(a, b) << std::endl;

	return 0;
}
