/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:31:48 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/12 10:47:14 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.loadDatabase();
    exchange.processInput(av[1]);
    return 0;
}