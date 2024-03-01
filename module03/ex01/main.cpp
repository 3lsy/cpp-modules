/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:30:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 18:52:36 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavTrap1("Lebron James");
	ScavTrap scavTrap2("Victor Wembanyama");
	scavTrap1.attack("Victor Wembanyama");
	scavTrap2.takeDamage(20);
	scavTrap2.beRepaired(3);
	scavTrap2.attack("Lebron James");
	scavTrap1.takeDamage(20);
	scavTrap2.attack("Lebron James");
	scavTrap1.takeDamage(20);
	scavTrap2.attack("Lebron James");
	scavTrap1.takeDamage(20);
	scavTrap2.attack("Lebron James");
	scavTrap1.takeDamage(20);
	scavTrap2.attack("Lebron James");
	scavTrap1.takeDamage(20);
	scavTrap1.beRepaired(10);
	scavTrap1.guardGate();
	return 0;
}