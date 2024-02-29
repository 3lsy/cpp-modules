/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:24:13 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 00:44:23 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
int main(void) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}
*/

// Testing min function
void testMin() {
    Fixed a(5.5f);
    Fixed b(3.3f);

    std::cout << "Testing min function:\n";
    std::cout << "Min of " << a << " and " << b << " is ";
    std::cout << Fixed::min(a, b) << std::endl;
}

// Testing const min function
void testConstMin() {
    const Fixed a(5.5f);
    const Fixed b(3.3f);

    std::cout << "Testing const min function:\n";
    std::cout << "Min of " << a << " and " << b << " is ";
    std::cout << Fixed::min(a, b) << std::endl;
}

// Testing max function
void testMax() {
    Fixed a(-1.5f);
    Fixed b(2.2f);

    std::cout << "Testing max function:\n";
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << Fixed::max(a, b) << std::endl;
}

// Testing const max function
void testConstMax() {
    const Fixed a(-1.5f);
    const Fixed b(2.2f);

    std::cout << "Testing const max function:\n";
    std::cout << "Max of " << a << " and " << b << " is ";
    std::cout << Fixed::max(a, b) << std::endl;
}

// Testing comparison operators
void testComparisonOperators() {
    Fixed a(5.5f);
    Fixed b(3.3f);

    std::cout << "Testing comparison operators:\n";
    std::cout << "a: " << a << ", b: " << b << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
}

int main(void) 
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "Increment and decrement operations" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	Fixed a;
	std::cout << "Increment" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "Decrement" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "Min and max operations" << std::endl;
	std::cout << "---------------------" << std::endl;
	testMin();
    testConstMin();
    testMax();
    testConstMax();
	std::cout << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "Comparison operations" << std::endl;
	std::cout << "---------------------" << std::endl;
	testComparisonOperators();
	std::cout << std::endl;

	Fixed c(20);
	Fixed d(10);
	std::cout << "---------------------" << std::endl;
	std::cout << "Arithmetic operations" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "The division between " << c << " and " << d << " is: " << c / d << std::endl;
	std::cout << "The division between " << d << " and " << c << " is: " << d / c << std::endl;
	std::cout << "The multiplication between " << c << " and " << d << " is: " << c * d << std::endl;
	std::cout << "The subtraction between " << c << " and " << d << " is: " << c - d << std::endl;
	std::cout << "The subtraction between " << d << " and " << c << " is: " << d - c << std::endl;
	std::cout << "The addition between " << c << " and " << d << " is: " << c + d << std::endl;
	std::cout << std::endl;

	Fixed e(2);
	Fixed f(0);
	std::cout << "The division between " << e << " and " << f << " is: " << e / f << std::endl;

	return 0;
}