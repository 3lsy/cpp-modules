/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:23:07 by echavez-          #+#    #+#             */
/*   Updated: 2024/05/14 20:27:07 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}