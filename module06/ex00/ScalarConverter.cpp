/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:41:17 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/15 16:39:10 by echavez-         ###   ########.fr       */
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

void ScalarConverter::convert(std::string str){
	/*
	if (str == "0" || str == "0.0" || str == "+0.0" || str == "-0.0")
		std::cout << "char: '0'" << std::endl;
	else if (str == "nan" || str == "-inff" || str == "+inff" || str == "-inf"
	|| str == "+inf" || str == "nanf")
		std::cout << "char: impossible" << std::endl;
	else {
		toChar(str);
		toInt(str);
		toFloat(str);
		toDouble(str);
	}
	*/
	toChar(str);
	toInt(str);
}

//functions to convert: check if the string is a char, then print it, using static_cast
void toChar(std::string str){
	if (isChar(str) == 3)
		std::cout << "char: '*'" << std::endl;
	else if (isChar(str) == 2)
		std::cout << "char: Non displayable" << std::endl;
	else if (isChar(str) == 1) {
		char c = static_cast<char>(str[0]); //convert string to char
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void toInt(std::string str){
	if (isFloat(str)) {
		//
	}
	char* endptr;
    long n = std::strtol(str.c_str(), &endptr, 10);

    if (n > INT_MAX || n < INT_MIN) {
        std::cout << "int: overflow or underflow" << std::endl;
    } else if (isInt(str)) {
        int intValue = static_cast<int>(n);
        std::cout << "int: " << intValue << std::endl;
    }
	else
		std::cout << "int: impossible" << std::endl;
}



//is digit
bool isDigit(char c){
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

//is printable
bool isPrintable(char c){
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

//is special
bool isSpecial(std::string str){
	if (str == "nanf" || str == "-inff" || str == "+inff" || str == "-inf"
	|| str == "+inf" || str == "nan")
		return true;
	return false;
}

//calculate length
int strLength(std::string str){
	int i = 0;
	while (str[i])
		i++;
	return i;
}

//verifications of the input string
int isChar(std::string str){
	if (strLength(str) == 1){
		if (!isDigit(str[0]) && isPrintable(str[0]))
			return (1);
		else if (!isPrintable(str[0]) || str[0] == '0')
			return (2);
	}
	else if (isFloat(str))
		return (3);
	return (0);
}
/*
//old version
int isChar(std::string str){
	if (str.length() == 1) {
		char c = static_cast<char>(str[0]); //convert string to char
		if (!isDigit(c) && isPrintable(c))
			return (1);
		else if (!isPrintable(c) || str[0] == '0')
			return (2);
		else if (isFloat(str))
			return (3);
	}
	return (0);
}
*/

//verify if the string is an int. Format: [+-]d+
int isInt(std::string str){
	int i = 0;
	int len = strLength(str);
	int digit = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i]) {
		if (!isDigit(str[i]))
			return (0);
		else
			digit++;
		i++;
	}
	return (1);
}

//verify if the string is a float. Format: d+.d+f
int isFloat(std::string str){
	int i = 0;
	int dot = 0;
	int dotIndex = 0;
	int f = 0;
	int len = strLength(str);
	while (str[i]) {
		if (str[i] == '.') {
			dotIndex = i;
			dot++;
		}
		else if (str[i] == 'f')
			f++;
		i++;
	}
	if (dot == 1 && f == 1 && isDigit(str[len - 2])
		&& isDigit(str[dotIndex - 1]) && isDigit(str[dotIndex + 1])
		&& str[len - 1] == 'f')
		return (1);
	return (0);
}
