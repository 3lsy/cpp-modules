/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:41:17 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/08 13:30:29 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {
	(void)src;
	return *this;
}

// inputType = {1: number, 2: char, 3: special}
void ScalarConverter::convert(std::string str){
	int 	i;
	double	d;
	float	f;
	char	c;
	int		inputType;
	
	inputType = getInputType(str);
	if (inputType == NUMBER || inputType == SPECIAL) {
		convertFromNumber(str, inputType);
	}
	else if (inputType == CHAR) {
		convertFromChar(str);
	}
}

// inputType = {1: number, 2: char, 3: special}
int	getInputType(std::string str) {
	try {
		int i = std::stoi(str);
		return (NUMBER);
	}
	catch (std::exception & e) {
		if (strLength(str) == 1)
			return (CHAR);
		else
			return (SPECIAL);
	}
}

void	convertFromNumber(std::string str, int inputType) {
	int 	i;
	double	d;
	float	f;
	char	c;
	try {
		i = static_cast<int>(std::stoi(str));
		c = static_cast<char>(i);
		if (isPrintable(c)) {
			std::cout << "char: " << c << std::endl;
		}
		else {
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << i << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	try {
		if (inputType != SPECIAL) {
			f = static_cast<float>(std::stof(str));
			int intPartF = static_cast<int>(f);
			if (f - intPartF == 0)
				std::cout << "float: " << f << ".0f" << std::endl;
			else
				std::cout << "float: " << f << "f" << std::endl;

			d = static_cast<double>(std::stod(str));
			int intPartD = static_cast<int>(d);
			if (d - intPartD == 0)
				std::cout << "double: " << d << ".0" << std::endl;
			else
				std::cout << "double: " << d << std::endl;

		}
		else {
			//nanf, -inff, +inff
			if (str == "nan" || str == "nanf") {
				std::cout << "float: nanf" << std::endl;
				std::cout << "double: nan" << std::endl;
			}
			else if (str == "-inf" || str == "-inff") {
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			else if (str == "+inf" || str == "+inff") {
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			}
			else
				throw std::exception();
		}
	}
	catch (std::exception & e) {
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}

}

void	convertFromChar(std::string str) {
	int 	i;
	double	d;
	float	f;
	char	c;

	c = str[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	f = static_cast<float>(c);
	int intPartF = static_cast<int>(f);
	if (f - intPartF == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	d = static_cast<double>(c);
	int intPartD = static_cast<int>(d);
	if (d - intPartD == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;

}

bool isPrintable(char c){
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

int strLength(std::string str){
	int i = 0;
	while (str[i])
		i++;
	return i;
}
