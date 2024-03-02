/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:30:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 00:59:12 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    // Test default constructor
	std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Creating FragTrap using default constructor:" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
    FragTrap fragTrap1;
	std::cout << "frag1 attributes: Name: " << fragTrap1.getName() << ", HP: " << fragTrap1.getHitPoints() << ", Energy: " << fragTrap1.getEnergyPoints() << ", Attack Damage: " << fragTrap1.getAttackDamage() << std::endl;
    fragTrap1.attack("Target");
    fragTrap1.takeDamage(10);
    fragTrap1.beRepaired(5);
    fragTrap1.highFivesGuys();
    std::cout << std::endl;

    // Test parameterized constructor
	std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Creating FragTrap using parameterized constructor:" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
    FragTrap fragTrap2("Enemy");
	std::cout << "frag2 attributes: Name: " << fragTrap2.getName() << ", HP: " << fragTrap2.getHitPoints() << ", Energy: " << fragTrap2.getEnergyPoints() << ", Attack Damage: " << fragTrap2.getAttackDamage() << std::endl;
    fragTrap2.attack("Target");
    fragTrap2.takeDamage(20);
    fragTrap2.beRepaired(10);
    fragTrap2.highFivesGuys();
	fragTrap2.takeDamage(20);
    fragTrap2.highFivesGuys();
    std::cout << std::endl;

    // Test copy constructor
	std::cout << "-----------------------------------------" << std::endl;
    std::cout << "Creating FragTrap using copy constructor:" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	FragTrap fragTrap3(fragTrap2);
	std::cout << "frag2 attributes: Name: " << fragTrap2.getName() << ", HP: " << fragTrap2.getHitPoints() << ", Energy: " << fragTrap2.getEnergyPoints() << ", Attack Damage: " << fragTrap2.getAttackDamage() << std::endl;
	std::cout << "frag3 attributes: Name: " << fragTrap3.getName() << ", HP: " << fragTrap3.getHitPoints() << ", Energy: " << fragTrap3.getEnergyPoints() << ", Attack Damage: " << fragTrap3.getAttackDamage() << std::endl;
	fragTrap3.attack("Target");
	fragTrap3.takeDamage(30);
	fragTrap3.beRepaired(15);
	fragTrap3.highFivesGuys();
	std::cout << "frag3 after fight: Name: " << fragTrap3.getName() << ", HP: " << fragTrap3.getHitPoints() << ", Energy: " << fragTrap3.getEnergyPoints() << ", Attack Damage: " << fragTrap3.getAttackDamage() << std::endl;
	std::cout << std::endl;
	
    // Test assignment operator
	std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Assigning FragTrap using assignment operator:" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
    FragTrap fragTrap4;
	std::cout << "frag4 before assignment: Name: " << fragTrap4.getName() << ", HP: " << fragTrap4.getHitPoints() << ", Energy: " << fragTrap4.getEnergyPoints() << ", Attack Damage: " << fragTrap4.getAttackDamage() << std::endl;
	std::cout << "frag3 before assignment: Name: " << fragTrap3.getName() << ", HP: " << fragTrap3.getHitPoints() << ", Energy: " << fragTrap3.getEnergyPoints() << ", Attack Damage: " << fragTrap3.getAttackDamage() << std::endl;
    fragTrap4 = fragTrap3;
	std::cout << "frag4 after assignment: Name: " << fragTrap4.getName() << ", HP: " << fragTrap4.getHitPoints() << ", Energy: " << fragTrap4.getEnergyPoints() << ", Attack Damage: " << fragTrap4.getAttackDamage() << std::endl;
	std::cout << "frag3 after assignment: Name: " << fragTrap3.getName() << ", HP: " << fragTrap3.getHitPoints() << ", Energy: " << fragTrap3.getEnergyPoints() << ", Attack Damage: " << fragTrap3.getAttackDamage() << std::endl;
    fragTrap4.attack("Target");
    fragTrap4.takeDamage(60);
    fragTrap4.beRepaired(20);
    fragTrap4.highFivesGuys();
    std::cout << std::endl;

    return 0;
}