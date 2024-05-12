/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:50:49 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 20:41:02 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	// presidential pardon test
	std::cout << "----PRESIDENTIAL PARDON TEST----" << std::endl;
	try {
		Intern  someRandomIntern;
		AForm*   ppf;

		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		delete ppf;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// shrubbery creation test
	std::cout << "----SHRUBBERY CREATION TEST----" << std::endl;
	try {
		Intern  someRandomIntern;
		AForm*   scf;

		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		delete scf;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	// robotomy request test
	std::cout << "----ROBOTOMY REQUEST TEST----" << std::endl;
	try {
        Intern  someRandomIntern;
        AForm*   rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
    }
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// wrong form name test
	std::cout << "----WRONG FORM NAME TEST----" << std::endl;
	try {
		Intern  someRandomIntern;
		AForm*   rrf;

		rrf = someRandomIntern.makeForm("wrong form name", "Bender");
		delete rrf;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    return (0);
}
