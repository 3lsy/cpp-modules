/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:36:19 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/10 00:25:55 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie = newZombie("Gudetama");
	zombie->announce();
	delete zombie;
	//the zombie created inside the function randomChump is destroyed after the function ends
	randomChump("Franky");
	return (0);
}
