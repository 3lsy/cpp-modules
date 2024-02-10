/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:10:10 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/10 14:27:17 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address of the string using pointer: " << stringPTR << std::endl;
	std::cout << "Address of the string using reference: " << &stringREF << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "String using pointer: " << *stringPTR << std::endl;
	std::cout << "String using reference: " << stringREF << std::endl;
	return (0);
}