/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:50:48 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/12 17:42:10 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) { }

RPN::RPN(std::string expr) {
	(void)expr;
}

RPN::~RPN(void) { }

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &src) {
	(void)src;
	return *this;
}

bool RPN::isOperator(const std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::performOperation(const std::string& operation, int a, int b) {
    if (operation == "+") return (a + b);
    if (operation == "-") return (a - b);
    if (operation == "*") return (a * b);
    if (operation == "/") {
        if (b == 0) {
			throw DivisionByZero();
		}
        return (a / b);
    }
    throw InvalidOperation();
}

void RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::istringstream stream(expression);
	std::string token;

	//std::cout << "Expression: " << expression << std::endl;
	while (stream >> token) {
		//std::cout << "Token: " << token << std::endl;
		if (isOperator(token)) {
			if (stack.size() < 2) {
				throw NotEnoughOperands();
			}
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			stack.push(performOperation(token, a, b));
		} else {
			std::istringstream tokenStream(token);
			int number;
			if (!(tokenStream >> number) || !tokenStream.eof()) {
				throw std::runtime_error("Error: invalid numeric argument");
			}
			//std::cout << "Number: " << number << std::endl;
			if (number > 10) {
				throw std::runtime_error("Error: numeric argument greater than 10 is not valid");
			}
			stack.push(number);
		}
	}
	if (stack.size() != 1) {
		throw InvalidExpression();
	}
	std::cout << stack.top() << std::endl;
}

/*
void RPN::evaluate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream stream(expression);
    std::string token;

	std::cout << "Expression: " << expression << std::endl;
    while (stream >> token) {
		std::cout << "Token: " << token << std::endl;
        if (isOperator(token)) {
            if (stack.size() < 2) {
                throw NotEnoughOperands();
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(performOperation(token, a, b));
        } else {
            int number = std::atoi(token.c_str());
			std::cout << "Number: " << number << std::endl;
            if (number > 10) {
				//print number
				std::cout << "Number: " << number << std::endl;
                throw std::runtime_error("Error: numeric argument greater than 10 is not valid");
            }
            stack.push(number);
        }
    }
    if (stack.size() != 1) {
        throw InvalidExpression();
    }
	std::cout << stack.top() << std::endl;
}
*/

//exceptions
const char* RPN::InvalidExpression::what() const throw() {
	return "Error: Invalid expression";
}

const char* RPN::DivisionByZero::what() const throw() {
	return "Error: Division by zero";
}

const char* RPN::NotEnoughOperands::what() const throw() {
	return "Error: Not enough operands";
}

const char* RPN::InvalidOperation::what() const throw() {
	return "Error: Invalid operation";
}
