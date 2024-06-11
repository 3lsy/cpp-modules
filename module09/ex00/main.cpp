/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:31:48 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/11 22:10:29 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }
    BitcoinExchange exchange;
    exchange.loadDatabase();
    exchange.processInput(argv[1]);
    return 0;
}