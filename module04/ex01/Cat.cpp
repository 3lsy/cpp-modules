/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:02:43 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:27:53 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat &Cat::operator=(const Cat &src)
{
	if (this != &src)
	{
		Animal::operator=(src);
		this->_brain = new Brain(*src._brain);
	}
	std::cout << "Cat assignation operator called" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

//getter
Brain *Cat::getBrain() const
{
	return (this->_brain);
}