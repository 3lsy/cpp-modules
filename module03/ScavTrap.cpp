/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:51:48 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 23:48:06 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " has been created!" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " has been destroyed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	// this->_name = src._name;
	// this->_hitPoints = src._hitPoints;
	// this->_energyPoints = src._energyPoints;
	// this->_attackDamage = src._attackDamage;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		// this->_name = src._name;
		// this->_hitPoints = src._hitPoints;
		// this->_energyPoints = src._energyPoints;
		// this->_attackDamage = src._attackDamage;
	}
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy points to attack!" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no health to attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
}