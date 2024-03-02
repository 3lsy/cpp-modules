/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:03:23 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 19:03:40 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog &Dog::operator=(const Dog &src)
{
	if (this != &src)
	{
		AAnimal::operator=(src);
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Dog assignation operator called" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

//getter
Brain *Dog::getBrain() const
{
	return (this->_brain);
}