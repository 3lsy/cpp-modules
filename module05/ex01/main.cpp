/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:50:49 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 16:35:42 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
	// Test creating forms with valid and invalid grades
	std::cout << "----FORMS WITH VALID & INVALID GRADES----" << std::endl;
	std::cout << std::endl;
    try {
        Form defaultForm;
        std::cout << defaultForm << std::endl;

        Form highGradeForm("TopSecret", 1, 1);
        std::cout << highGradeForm << std::endl;

        Form lowGradeForm("Casual", 150, 150);
        std::cout << lowGradeForm << std::endl;

        Form invalidForm("Invalid", 0, 150);
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

	std::cout << std::endl << "----SIGN FORM TESTS----" << std::endl;
	std::cout << std::endl;

    // Create two bureaucrats with different grades and names
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 150);

    // Print out initial bureaucrat info
    std::cout << "Initial Bob: ";
    std::cout << bob;

    std::cout << "Initial Alice: ";
    std::cout << alice;
    std::cout << std::endl;

    // Create a form with a specific grade requirement for signing
    Form salesContract("Sales Contract", 120, 150);

    // Bob should be able to sign the form
    try {
        bob.signForm(salesContract);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Alice shouldn't be able to sign the form because her grade is too low
    try {
        alice.signForm(salesContract);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

	// Increment Alice's grade so she can sign the form
	std::cout << "Incrementing Alice's grade..." << std::endl;
	while (alice.getGrade() >= salesContract.getGradeToSign()) {
		alice.incrementGrade();
	}

	// Alice should now be able to sign the form
	try {
		alice.signForm(salesContract);
	} catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	//show the status of the form
	std::cout << salesContract << std::endl;
    return 0;
}
