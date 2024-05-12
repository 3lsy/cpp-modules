/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:31:44 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 16:50:52 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &form);
		AForm &operator=(const AForm &form);
		virtual ~AForm();

		virtual void execute(Bureaucrat const & executor) const = 0;
		
		//getters
		std::string getName() const;
		bool getSigned() const;
		void setSigned(bool isSigned);
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too high";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Grade is too low";
				}
		};
		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return "Form is not signed";
				}
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif