/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:22:31 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/19 17:59:41 by echavez-         ###   ########.fr       */
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
	std::string		s1 = this->_s1;
	std::string		s2 = this->_s2;
	std::string		line;

	std::ifstream	inputFile(this->_filename.c_str());
    if (!inputFile.is_open()) {
		std::cerr << "Failed to open the input file" << std::endl;
		return ;
	}
	// Check if the input file is empty
    inputFile.seekg(0, std::ios::end);
    if (inputFile.tellg() == 0) {
        std::cerr << "Input file is empty" << std::endl;
        return;
    }
	// Reset file pointer to the beginning
    inputFile.seekg(0, std::ios::beg);

	std::ofstream	outputFile((this->_filename + ".replace").c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Failed to create the output file" << std::endl;
		return ;
	}

	// Read the input file and replace the string
	while (std::getline(inputFile, line)) {
		if (!inputFile) {
            std::cerr << "Error occurred while reading input file" << std::endl;
            return;
        }
		size_t pos = 0;
		while (s1 != s2 && (pos = line.find(s1, pos)) != std::string::npos && s1.length() > 0) {
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outputFile << line << std::endl;
		if (!outputFile) {
            std::cerr << "Error occurred while writing to output file" << std::endl;
            return;
        }
	}
	inputFile.close();
	outputFile.close();
}

