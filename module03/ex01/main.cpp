/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:30:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 00:24:43 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include "ScavTrap.hpp"

int main() {
    // Test default constructor
	std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Creating ScavTrap using default constructor:" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
    ScavTrap scavTrap1;
	std::cout << "scav1 attributes: Name: " << scavTrap1.getName() << ", HP: " << scavTrap1.getHitPoints() << ", Energy: " << scavTrap1.getEnergyPoints() << ", Attack Damage: " << scavTrap1.getAttackDamage() << std::endl;
    scavTrap1.attack("Target");
    scavTrap1.takeDamage(10);
    scavTrap1.beRepaired(5);
    scavTrap1.guardGate();
    std::cout << std::endl;

    // Test parameterized constructor
	std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Creating ScavTrap using parameterized constructor:" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
    ScavTrap scavTrap2("Enemy");
	std::cout << "scav2 attributes: Name: " << scavTrap2.getName() << ", HP: " << scavTrap2.getHitPoints() << ", Energy: " << scavTrap2.getEnergyPoints() << ", Attack Damage: " << scavTrap2.getAttackDamage() << std::endl;
    scavTrap2.attack("Target");
    scavTrap2.takeDamage(20);
    scavTrap2.beRepaired(10);
    scavTrap2.guardGate();
	scavTrap2.takeDamage(20);
    scavTrap2.guardGate();
    std::cout << std::endl;

    // Test copy constructor
	std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Creating ScavTrap using copy constructor:" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	ScavTrap scavTrap3(scavTrap2);
	std::cout << "scav2 attributes: Name: " << scavTrap2.getName() << ", HP: " << scavTrap2.getHitPoints() << ", Energy: " << scavTrap2.getEnergyPoints() << ", Attack Damage: " << scavTrap2.getAttackDamage() << std::endl;
	std::cout << "scav3 attributes: Name: " << scavTrap3.getName() << ", HP: " << scavTrap3.getHitPoints() << ", Energy: " << scavTrap3.getEnergyPoints() << ", Attack Damage: " << scavTrap3.getAttackDamage() << std::endl;
	scavTrap3.attack("Target");
	scavTrap3.takeDamage(30);
	scavTrap3.beRepaired(15);
	scavTrap3.guardGate();
	std::cout << "scav3 after fight: Name: " << scavTrap3.getName() << ", HP: " << scavTrap3.getHitPoints() << ", Energy: " << scavTrap3.getEnergyPoints() << ", Attack Damage: " << scavTrap3.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
    // Test assignment operator
	std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Assigning ScavTrap using assignment operator:" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
    ScavTrap scavTrap4;
	std::cout << "scav4 before assignment: Name: " << scavTrap4.getName() << ", HP: " << scavTrap4.getHitPoints() << ", Energy: " << scavTrap4.getEnergyPoints() << ", Attack Damage: " << scavTrap4.getAttackDamage() << std::endl;
	std::cout << "scav3 before assignment: Name: " << scavTrap3.getName() << ", HP: " << scavTrap3.getHitPoints() << ", Energy: " << scavTrap3.getEnergyPoints() << ", Attack Damage: " << scavTrap3.getAttackDamage() << std::endl;
    scavTrap4 = scavTrap3;
	std::cout << "scav4 after assignment: Name: " << scavTrap4.getName() << ", HP: " << scavTrap4.getHitPoints() << ", Energy: " << scavTrap4.getEnergyPoints() << ", Attack Damage: " << scavTrap4.getAttackDamage() << std::endl;
	std::cout << "scav3 after assignment: Name: " << scavTrap3.getName() << ", HP: " << scavTrap3.getHitPoints() << ", Energy: " << scavTrap3.getEnergyPoints() << ", Attack Damage: " << scavTrap3.getAttackDamage() << std::endl;
    scavTrap4.attack("Target");
    scavTrap4.takeDamage(60);
    scavTrap4.beRepaired(20);
    scavTrap4.guardGate();
    std::cout << std::endl;

    return 0;
}