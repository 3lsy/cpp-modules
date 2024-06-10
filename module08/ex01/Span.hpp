/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:55:06 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/10 12:31:00 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <climits>
# include <limits>

class Span
{
	private:
		std::vector<int> numbers;
    	unsigned int max_size;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();
		Span & operator=(const Span &src) ;

		//member functions
		void addNumber(int n);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		// Custom exception for a full span
		class FullSpanException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
		// Custom exception for not enough numbers to find a span
		class NotEnoughNumbersException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
};

#endif