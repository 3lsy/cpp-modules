/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:41:31 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/08 13:34:55 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib> //to convert string to int, float, double
# include <string>
# include <climits>  // for INT_MAX and INT_MIN

# define NUMBER 1
# define CHAR 2
# define SPECIAL 3

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
		ScalarConverter & operator=(ScalarConverter const & src);
	public:
		static void convert(std::string str);
};

int	getInputType(std::string str);
void convertFromNumber(std::string str, int inputType);
void convertFromChar(std::string str);
//is printable
bool isPrintable(char c);
//calculate length
int strLength(std::string str);

#endif
