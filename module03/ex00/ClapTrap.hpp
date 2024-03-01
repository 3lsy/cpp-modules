/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:32:10 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 18:01:58 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		// Copy constructor
		ClapTrap(const ClapTrap &src);
		~ClapTrap();
		// Assignment operator
		ClapTrap &operator=(const ClapTrap &src);

		void attack(std::string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Getters
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
		};

#endif