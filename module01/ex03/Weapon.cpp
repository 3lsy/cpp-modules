/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:31:16 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/11 17:48:56 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	//this->_type = type;
	this->setType(type);
	std::cout << this->_type << " weapon has been created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << this->_type << " weapon has been destroyed" << std::endl;
}

//Returning a reference allows the caller to access the actual string stored in the Weapon object without making a copy of it
const std::string &Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}