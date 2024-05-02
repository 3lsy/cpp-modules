/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:26:13 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/02 14:00:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &form) : _name(form._name), _signed(form._signed), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute) {
}

Form::~Form() {
	std::cout << "Form " << _name << " has been destroyed" << std::endl;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSigned() const {
	return _signed;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

void Form::signForm(const Bureaucrat &bureaucrat) {
	try {
		beSigned(bureaucrat);
		std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	} catch (std::exception &e) {
		std::cout << bureaucrat.getName() << " cannot sign " << _name << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "--- Form Info ---" << std::endl;
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