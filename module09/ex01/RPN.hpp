/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:50:51 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/12 16:40:43 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN {
	private:
    	bool isOperator(const std::string& token);
    	int performOperation(const std::string& operation, int a, int b);
	public:
		RPN(void);
		RPN(std::string expr);
		~RPN(void);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		void evaluate(const std::string& expression);
		//exceptions
		class InvalidExpression : public std::exception {
			virtual const char* what() const throw();
		};
		class DivisionByZero : public std::exception {
			virtual const char* what() const throw();
		};
		class NotEnoughOperands : public std::exception {
			virtual const char* what() const throw();
		};
		class InvalidOperation : public std::exception {
			virtual const char* what() const throw();
		};
};

#endif