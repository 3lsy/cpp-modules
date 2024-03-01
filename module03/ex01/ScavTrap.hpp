/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:52:03 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/01 18:24:22 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		// Copy constructor
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		// Assignment operator
		ScavTrap &operator=(ScavTrap const &src);

		void attack(std::string const & target);
		void guardGate();
};

#endif