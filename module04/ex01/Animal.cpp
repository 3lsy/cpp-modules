/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:19:12 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:28:18 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal " << this->_type << " constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string Animal::getType() const 
{
	return this->_type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
