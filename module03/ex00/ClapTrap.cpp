/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:33:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 12:51:36 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void ClapTrap::attack(std::string const& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no health points!" << std::endl;
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
		std::cout << "ClapTrap " << this->_name << " has no energy points!" << std::endl;
		return ;
	}
	else if (this->_hitPoints == 10)
	{
		std::cout << "ClapTrap " << this->_name << " has already full health!" << std::endl;
		return ;
	}
	else if ((this->_hitPoints + amount) > 10)
	{
		std::cout << "ClapTrap " << this->_name << " has been repaired for " << 10 - this->_hitPoints << " points!" << std::endl;
		this->_hitPoints = 10;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount << " points!" << std::endl;
	this->_energyPoints -= 1;
}