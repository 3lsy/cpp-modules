/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:19:12 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 19:16:57 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal " << this->_type << " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

std::string AAnimal::getType() const 
{
	return this->_type;
}
