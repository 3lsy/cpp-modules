/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:33:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 16:54:18 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points to attack!" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no health to attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already defeated!" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= amount || (this->_hitPoints - amount) < 0)
	{
		std::cout << "ClapTrap " << this->_name << " has taken all the damage!" << std::endl;
		this->_hitPoints = 0;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has taken " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points to heal!" << std::endl;
		return ;
	}
	else if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't be repaired because it's already defeated!" << std::endl;
		return ;
	}
	else if (this->_hitPoints == 10)
	{
		std::cout << "ClapTrap " << this->_name << " has already full health!" << std::endl;
		return ;
	}
	else if ((this->_hitPoints + amount) > 10)
	{
		std::cout << "ClapTrap " << this->_name << " has been completely repaired!" << std::endl;
		this->_hitPoints = 10;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount << " points!" << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
}

// Getters
std::string ClapTrap::getName() const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}