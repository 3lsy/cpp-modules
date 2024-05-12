/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:39:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/12 17:31:21 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &form);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

		~PresidentialPardonForm();

		//getter and setter
		std::string getTarget() const;
		void setTarget(std::string target);

		void execute(Bureaucrat const & executor) const override;
};

#endif