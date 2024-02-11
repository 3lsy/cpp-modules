/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:33:14 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/11 17:51:50 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void	HumanA::attack(void)
{
	if (this->_weapon.getType() != "")
		std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon to attack with" << std::endl;
}