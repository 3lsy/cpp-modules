/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:24:13 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/29 23:45:09 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

/*
int main(void) 
{
	std::cout << "-------------------" << std::endl;
	Fixed c(1);
	Fixed d(3);

	std::cout << "The max between " << c << " and " << d << " is: " << Fixed::max(c, d) << std::endl;
	std::cout << "The min between " << c << " and " << d << " is: " << Fixed::min(c, d) << std::endl;
	std::cout << "The division between " << c << " and " << d << " is: " << c / d << std::endl;
	std::cout << "The division between " << d << " and " << c << " is: " << d / c << std::endl;
	std::cout << "The multiplication between " << c << " and " << d << " is: " << c * d << std::endl;
	std::cout << "The subtraction between " << c << " and " << d << " is: " << c - d << std::endl;
	std::cout << "The subtraction between " << d << " and " << c << " is: " << d - c << std::endl;
	std::cout << "The addition between " << c << " and " << d << " is: " << c + d << std::endl;
	std::cout << "-------------------" << std::endl;

	Fixed e(2);
	Fixed f(0);
	std::cout << "The division between " << e << " and " << f << " is: " << e / f << std::endl;

	return 0;
}
*/