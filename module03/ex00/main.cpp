/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:30:40 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/29 13:34:16 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("A");

    clap.attack("B");
    clap.takeDamage(10);
    clap.beRepaired(5);
    clap.attack("C");
    clap.beRepaired(20);
    clap.takeDamage(20);
    return (0);
}