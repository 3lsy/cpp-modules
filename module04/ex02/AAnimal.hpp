/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:15:45 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 19:16:54 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();

		AAnimal &operator=(const AAnimal &src);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif