/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:36:58 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/10 00:14:31 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << "<" << this->name << "> has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}