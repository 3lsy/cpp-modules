/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:00:12 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/06 15:30:09 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_is_lower_case(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		int	i = 1;
		while (av[i])
		{
			int	j = 0;
			while (av[i][j])
			{
				if (ft_is_lower_case(av[i][j]))
					av[i][j] = av[i][j] - 32;
				std::cout << av[i][j];
				j++;
			}
			i++;
		}
	}
	else if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
	return (0);
}