/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:50:49 by echavez-          #+#    #+#             */
/*   Updated: 2024/04/29 00:31:12 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1;
        std::cout << b1;

        Bureaucrat b2("Alice", 1);
        std::cout << b2;

        Bureaucrat b3("Bob", 150);
        std::cout << b3;

        b2.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Charlie", 151);
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Diana", 2);
        std::cout << b3;
        b3.decrementGrade();
        std::cout << b3;
        b3.decrementGrade();
        std::cout << b3;

        for (int i = 0; i < 146; ++i) {
            b3.decrementGrade();
        }

        std::cout << b3;

        b3.decrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
