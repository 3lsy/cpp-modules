/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:41:17 by echavez-          #+#    #+#             */
/*   Updated: 2024/07/22 16:03:01 by echavez-         ###   ########.fr       */
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

void ScalarConverter::convert(std::string str) {
    int inputType = getInputType(str);
    if (inputType == NUMBER || inputType == SPECIAL) {
        convertFromNumber(str, inputType);
    } else if (inputType == CHAR) {
        convertFromChar(str);
    }
}

int getInputType(std::string str) {
    std::stringstream ss(str);
    int i;
    if (ss >> i) {
        return NUMBER;
    } else {
        if (str.length() == 1) {
            return CHAR;
        } else {
            return SPECIAL;
        }
    }
}

void convertFromNumber(std::string str, int inputType) {
    int i;
    double d;
    float f;
    char c;

    std::stringstream ss(str);
    try {
        ss >> i;
        if (ss.fail()) throw std::exception();

        c = static_cast<char>(i);
        if (isPrintable(c)) {
            std::cout << "char: " << c << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << i << std::endl;
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }

    try {
        if (inputType != SPECIAL) {
            std::stringstream ss(str);
            ss >> f;
            if (ss.fail()) throw std::exception();
            
            int intPartF = static_cast<int>(f);
            if (f - intPartF == 0) {
                std::cout << "float: " << f << ".0f" << std::endl;
            } else {
                std::cout << "float: " << f << "f" << std::endl;
            }

            std::stringstream ssD(str);
            ssD >> d;
            if (ssD.fail()) throw std::exception();

            int intPartD = static_cast<int>(d);
            if (d - intPartD == 0) {
                std::cout << "double: " << d << ".0" << std::endl;
            } else {
                std::cout << "double: " << d << std::endl;
            }
        } else {
            // Handle special cases like nanf, -inff, +inff
            if (str == "nan" || str == "nanf") {
                std::cout << "float: nanf" << std::endl;
                std::cout << "double: nan" << std::endl;
            } else if (str == "-inf" || str == "-inff") {
                std::cout << "float: -inff" << std::endl;
                std::cout << "double: -inf" << std::endl;
            } else if (str == "+inf" || str == "+inff") {
                std::cout << "float: +inff" << std::endl;
                std::cout << "double: +inf" << std::endl;
            } else {
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
            }
        }
    } catch (...) {
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

void convertFromChar(std::string str) {
    int i;
    double d;
    float f;
    char c;

    c = str[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;

    int intPartF = static_cast<int>(f);
    if (f - intPartF == 0) {
        std::cout << "float: " << f << ".0f" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }

    int intPartD = static_cast<int>(d);
    if (d - intPartD == 0) {
        std::cout << "double: " << d << ".0" << std::endl;
    } else {
        std::cout << "double: " << d << std::endl;
    }
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
