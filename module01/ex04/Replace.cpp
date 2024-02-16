/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:22:31 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/16 16:44:31 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
{
	this->_filename = filename;
	this->_s1 = s1;
	this->_s2 = s2;
}

Replace::~Replace()
{
}

void	Replace::replace()
{
	std::ifstream	inputFile(this->_filename);
	std::ofstream	outputFile(this->_filename + ".replace");
	std::string		s1 = this->_s1;
	std::string		s2 = this->_s2;
	size_t			pos = 0;
	std::string		line;

	// Check if the input file is open
    if (!inputFile.is_open()) {
		std::cerr << "Failed to open the input file" << std::endl;
		return ;
	}
	// Check if the output file is open
	if (!outputFile.is_open()) {
		std::cerr << "Failed to create the output file" << std::endl;
		return ;
	}
	// Read the input file and replace the string
	while (std::getline(inputFile, line)) {
		while ((pos = line.find(s1)) != std::string::npos && s1.length() > 0) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	// Close the files
	inputFile.close();
	outputFile.close();
}