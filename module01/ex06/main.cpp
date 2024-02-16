/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:41 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/16 18:09:18 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Usage: ./complain [DEBUG | INFO | WARNING | ERROR]" << std::endl;
	return (0);
}