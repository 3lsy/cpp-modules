/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:31:53 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/12 12:32:55 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &  BitcoinExchange::operator=(BitcoinExchange const & src) {
	if (this != &src) {
		this->database = src.database;
	}
	return *this;
}

void BitcoinExchange::loadDatabase(void) {
    std::ifstream file(DB);
    std::string line;
	std::string date;
	std::string rateStr;
	float rate;
    // Skip the header
    std::getline(file, line);
    while (std::getline(file, line)) {
		std::istringstream stream(line);
		if (std::getline(stream, date, ',') && std::getline(stream, rateStr)) {
        	rate = std::stof(rateStr);
        	database[date] = rate;
    	}
    }
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    // Skip the header
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream stream(line);
		std::string date;
		float value;
		char separator;
		if (stream >> date >> separator >> value) {
			if (!isValidDate(date)) {
				std::cerr << "Error: bad date => " << date << std::endl;
				continue;
			}
			std::map<std::string, float>::iterator it = database.lower_bound(date);
			if (it == database.end() || it->first != date) {
				if (it != database.begin()) {
					--it;
				}
			}
			if (it != database.end()) {
				if (value < 0)
					std::cerr << "Error: not a positive number." << std::endl;
				else if (value > 1000)
					std::cerr << "Error: too large number." << std::endl;
				else
					std::cout << date << " => " << value << " = " << value * it->second << std::endl;
			} else {
				std::cerr << "Error: date not found in database" << std::endl;
			}
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}
	for (size_t i = 0; i < date.size(); i++) {
		if (i == 4 || i == 7) {
			continue;
		}
		if (!std::isdigit(date[i])) {
			return false;
		}
	}
	//check with stoi that the date is valid
	int year = std::stoi(date.substr(0, 4));
	int month = std::stoi(date.substr(5, 2));
	int day = std::stoi(date.substr(8, 2));
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	//if february
	if (month == 2) {
		if (day > 29) {
			return false;
		}
		if (day == 29) {
			if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
				return false;
			}
		}
	}
	//if month has 30 days
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day == 31) {
			return false;
		}
	}
	return true;
}