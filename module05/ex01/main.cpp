/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:50:49 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/02 13:59:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	// Test creating forms with valid and invalid grades
    try {
        Form defaultForm;  // Default constructor, valid
        std::cout << defaultForm << std::endl;

        Form highGradeForm("TopSecret", 1, 1);
        std::cout << highGradeForm << std::endl;

        Form lowGradeForm("Casual", 150, 150);
        std::cout << lowGradeForm << std::endl;

        Form invalidForm("Invalid", 0, 150);
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Form creation failed: " << e.what() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Form creation failed: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    // Test signing forms with Bureaucrats
    try {
        Bureaucrat chief("Chief", 5);
        Bureaucrat assistant("Assistant", 100);

        Form report("Quarterly Report", 10, 50);

        std::cout << report << std::endl;

        report.signForm(chief);  // Should work
        std::cout << report << std::endl;

        report.signForm(assistant);  // Should fail because assistant's grade is too low
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Bureaucrat error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Bureaucrat error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

	// Test the copy constructor
	try {
        Form form1("Form A", 100, 120);
        Bureaucrat chief("Chief", 5);

        form1.signForm(chief);
        
        std::cout << form1 << std::endl;

        Form formCopy(form1);
        std::cout << "Copy of Form A:" << std::endl;
        std::cout << formCopy << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }
    return 0;
}
