/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:51:48 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 23:50:11 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " has been created!" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " has been destroyed" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	// this->_name = src._name;
	// this->_hitPoints = src._hitPoints;
	// this->_energyPoints = src._energyPoints;
	// this->_attackDamage = src._attackDamage;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		// this->_name = src._name;
		// this->_hitPoints = src._hitPoints;
		// this->_energyPoints = src._energyPoints;
		// this->_attackDamage = src._attackDamage;
	}
	std::cout << "FragTrap Assignation operator called" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << "FragTrap " << this->_name << " has no energy points to high five!" << std::endl;
        return ;
    }
    else if (this->_hitPoints <= 0)
    {
        std::cout << "FragTrap " << this->_name << " has no health to high five!" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " is asking for a high five!" << std::endl;
}