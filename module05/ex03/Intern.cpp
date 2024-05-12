/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:58:54 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 20:19:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &intern) {
	(void)intern;
	return *this;
}

AForm *createPresidentialPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm *createRobotomyRequestForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm *createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	AForm *form = NULL;
	AForm *(*formCreators[3])(std::string const &target) = {
		createPresidentialPardonForm,
		createRobotomyRequestForm,
		createShrubberyCreationForm
	};

	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Intern could not create " << formName << std::endl;
	return (NULL);
}

/*
AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
	if (formName == "robotomy request") {
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(target);
	} else if (formName == "presidential pardon") {
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(target);
	} else if (formName == "shrubbery creation") {
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(target);
	} else {
		std::cout << "Intern could not create " << formName << std::endl;
		return NULL;
	}
}
*/