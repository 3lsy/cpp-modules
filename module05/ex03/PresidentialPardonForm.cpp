/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:39:57 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 18:58:11 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form), _target(form._target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
	if (this != &form) {
		AForm::operator=(form);
		_target = form._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string PresidentialPardonForm::getTarget() const {
	return (_target);
}

void PresidentialPardonForm::setTarget(std::string target) {
	_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}


