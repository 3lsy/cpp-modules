/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:49:44 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 19:04:58 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *_brain;
	public:
		Dog();
		~Dog();

		Dog(const Dog &src);
		Dog &operator=(const Dog &src);

		void makeSound() const override;
		//getter
		Brain *getBrain() const;
};

#endif