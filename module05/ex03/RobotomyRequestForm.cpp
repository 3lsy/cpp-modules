/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:39:33 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 20:34:10 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form), _target(form._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
	if (this != &form) {
		AForm::operator=(form);
		_target = form._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string RobotomyRequestForm::getTarget() const {
	return (_target);
}

void RobotomyRequestForm::setTarget(std::string target) {
	_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);
    std::cout << "Bzzzzzz... Bzzzzzz... Bzzzzzz..." << std::endl;
	srand(time(0));
    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomization of " << _target << " has failed." << std::endl;
    }
}