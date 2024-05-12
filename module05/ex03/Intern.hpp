/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:58:35 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 20:23:54 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class RobotomyRequestForm;
class PresidentialPardonForm;
class ShrubberyCreationForm;

class Intern {
	private:
	public:
		Intern();
		Intern(const Intern &intern);
		~Intern();
		Intern &operator=(const Intern &intern);

		AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif