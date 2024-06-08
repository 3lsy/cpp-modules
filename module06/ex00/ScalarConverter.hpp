/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:41:31 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/15 16:27:08 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib> //to convert string to int, float, double
# include <string>
# include <climits>  // for INT_MAX and INT_MIN

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & src);
	public:
		static void convert(std::string str);
};

//functions to convert
void toChar(std::string str);
void toInt(std::string str);
void toFloat(std::string str);
void toDouble(std::string str);
//is digit
bool isDigit(char c);
//is printable
bool isPrintable(char c);
//is special
bool isSpecial(std::string str);
//calculate length
int strLength(std::string str);
//verification of the input string
int isChar(std::string str);
int isInt(std::string str);
int isFloat(std::string str);
int isDouble(std::string str);

std::ostream & operator<<(std::ostream & o, ScalarConverter const & src);

#endif