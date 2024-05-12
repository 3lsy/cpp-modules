/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:38:38 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 19:00:37 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm(form), _target(form._target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
	if (this != &form) {
		AForm::operator=(form);
		_target = form._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string ShrubberyCreationForm::getTarget() const {
	return (_target);
}

void ShrubberyCreationForm::setTarget(std::string target) {
	_target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::ofstream file(_target + "_shrubbery");
	if (file.is_open()) {
		file << "      /\\      " << std::endl;
		file << "     /\\*\\     " << std::endl;
		file << "    /\\O\\*\\    " << std::endl;
		file << "   /*/\\/\\/\\   " << std::endl;
		file << "  /\\O\\/\\*\\/\\  " << std::endl;
		file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << "      ||      " << std::endl;
		file << std::endl;
		file.close();
	} else {
		std::cerr << "Error: could not open file" << std::endl;
	}
}