/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:41 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/16 18:01:41 by echavez-         ###   ########.fr       */
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

/*
int	main(int ac, char **av)
{
	Harl	harl;

	if (ac == 1)
	{
		while (1)
		{
			std::cout << "Enter a level: ";
			std::string level;
			std::getline(std::cin, level);
			if (level == "EXIT")
				break ;
			harl.complain(level);
		}
	}
	else
		std::cout << "Usage: ./complain" << std::endl;
	return (0);
}
*/