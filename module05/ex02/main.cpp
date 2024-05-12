/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 20:50:49 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 20:43:52 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try
    {
        Bureaucrat  *bureaucrat = new Bureaucrat("Bureaucrat", 5);
        AForm       *president = new PresidentialPardonForm("Form");
    	AForm       *robotomy = new RobotomyRequestForm("Form2");
        AForm       *shrubbery = new ShrubberyCreationForm("test");

		std::cout << "----STATUS----" << std::endl;
		std::cout << std::endl;
        std::cout << *bureaucrat << std::endl;
        std::cout << *president << std::endl;
        std::cout << *robotomy << std::endl;
        std::cout << *shrubbery << std::endl;

        std::cout << std::endl << "----SIGNING FORM----" << std::endl;
		std::cout << std::endl;
        bureaucrat->signForm(*president);
        bureaucrat->signForm(*robotomy);
        bureaucrat->signForm(*shrubbery);

		std::cout << std::endl;
        std::cout << "----STATUS----" << std::endl;
		std::cout << std::endl;
        std::cout << *bureaucrat << std::endl;
        std::cout << *president << std::endl;
        std::cout << *robotomy << std::endl;
        std::cout << *shrubbery << std::endl;

        std::cout << std::endl << "----EXECUTING FORM WHEN REQUISITES ARE OK----" << std::endl;
		std::cout << std::endl;
        std::cout <<  "---PresidentPardonForm---" <<std::endl;
        bureaucrat->executeForm(*president);
		std::cout << std::endl << "---RobotomyRequestForm---" << std::endl;
        bureaucrat->executeForm(*robotomy);
		std::cout << std::endl << "---ShrubberyCreationForm---" << std::endl;
        bureaucrat->executeForm(*shrubbery);

		std::cout << std::endl << "----EXECUTING FORM WHEN REQUISITES ARE NOT OK----" << std::endl;
		std::cout << std::endl;
		bureaucrat->setGrade(150);
		std::cout << "Setting bureaucrat grade to the lowest..." << std::endl;
		std::cout << *bureaucrat << std::endl;
		std::cout <<  "---PresidentPardonForm---" <<std::endl;
        bureaucrat->executeForm(*president);
		std::cout << std::endl << "---RobotomyRequestForm---" << std::endl;
        bureaucrat->executeForm(*robotomy);
		std::cout << std::endl << "---ShrubberyCreationForm---" << std::endl;
        bureaucrat->executeForm(*shrubbery);
    }
    catch(const std::exception& e)
    {
		std::cerr << "Error: " << e.what() << std::endl;
	}

    return (0);
}
