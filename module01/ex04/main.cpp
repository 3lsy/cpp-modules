/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:57:05 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/16 15:44:15 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		Replace	replace(av[1], av[2], av[3]);
		replace.replace();
	}
	else
	{
		std::cout << "Usage: ./replace [filename] [string to replace] [string to replace with]" << std::endl;
		return (1);
	}
	return (0);
}