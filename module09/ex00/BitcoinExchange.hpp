/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:32:04 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/12 12:02:43 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream> //ifstream
#include <sstream> //istringstream
#include <map> //map
#include <string> //string

#define DB "data.csv"

class BitcoinExchange {
	private:
		std::map<std::string, float> database;
		bool isValidDate(const std::string& date);
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);
		BitcoinExchange &  operator=(BitcoinExchange const & rhs);

		void loadDatabase(void);
		void processInput(const std::string& filename);
};

#endif