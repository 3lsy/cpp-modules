/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:32:04 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/11 22:53:22 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

// # include <iostream>
// # include <fstream>
// # include <sstream>
// # include <map>
// # include <string>
// # include <algorithm>

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>
#include <limits>
#include <cerrno>

#define DB "data.csv"

class BitcoinExchange {
	private:
		std::map<std::string, float> database;
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);
		BitcoinExchange &  operator=(BitcoinExchange const & rhs);

		void loadDatabase(void);
		void processInput(const std::string& filename);
};

#endif