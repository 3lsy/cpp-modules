/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:26:13 by echavez-          #+#    #+#             */
/*   Updated: 2024/07/02 13:31:04 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &form) : _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {
}

AForm &AForm::operator=(const AForm &form) {
	if (this != &form) {
		_signed = form._signed;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm " << _name << " has been destroyed" << std::endl;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

void AForm::setSigned(bool isSigned) {
	_signed = isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	else
		setSigned(true);
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	else
		std::cout << executor.getName() << " executes " << _name << std::endl;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "--- AForm Info ---" << std::endl;
	out << "Form name: " << form.getName() << std::endl;
	out << "Grade to sign: " << form.getGradeToSign() << std::endl;
	out << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed" << std::endl;
	else
		out << "not signed" << std::endl;
	return out;
}

//exceptions
const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}
