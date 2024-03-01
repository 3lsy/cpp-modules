/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:30:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 16:50:54 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// int main( void )
// {
//     ClapTrap clap("A");
// 	ClapTrap clap2;

// 	clap2 = clap;

//     clap.attack("B");
// 	clap2.attack("A");
//     clap.takeDamage(10);
//     clap.beRepaired(5);
//     clap.attack("C");
//     clap.beRepaired(20);
//     clap.takeDamage(20);
//     return (0);
// }

int main() {
    std::cout << "Creating ClapTrap objects:" << std::endl;
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");

    std::cout << std::endl << "Attacking with ClapTrap objects:" << std::endl;
    clap1.attack("Target1");
    clap2.attack("Target2");

    std::cout << std::endl << "Taking damage with ClapTrap objects:" << std::endl;
    clap1.takeDamage(5);
    clap2.takeDamage(15);

    std::cout << std::endl << "Reparing ClapTrap objects:" << std::endl;
    clap1.beRepaired(3);
    clap2.beRepaired(7);

    std::cout << std::endl << "Assigning ClapTrap objects:" << std::endl;
	std::cout << "clap1 before assignment: " << clap1.getName() << ", HP: " << clap1.getHitPoints() << ", Energy: " << clap1.getEnergyPoints() << ", Attack Damage: " << clap1.getAttackDamage() << std::endl;
	std::cout << "clap2 before assignment: " << clap2.getName() << ", HP: " << clap2.getHitPoints() << ", Energy: " << clap2.getEnergyPoints() << ", Attack Damage: " << clap2.getAttackDamage() << std::endl;
    clap1 = clap2;
	std::cout << "clap1 after assignment: " << clap1.getName() << ", HP: " << clap1.getHitPoints() << ", Energy: " << clap1.getEnergyPoints() << ", Attack Damage: " << clap1.getAttackDamage() << std::endl;
	std::cout << "clap2 after assignment: " << clap2.getName() << ", HP: " << clap2.getHitPoints() << ", Energy: " << clap2.getEnergyPoints() << ", Attack Damage: " << clap2.getAttackDamage() << std::endl;

	std::cout << std::endl << "ClapTrap objects after further modifications:" << std::endl;
    clap1.attack("New Target");
    clap2.takeDamage(20);

    return 0;
}