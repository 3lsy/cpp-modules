/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:21:30 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/17 12:35:51 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::string	option;
	while (true)
	{
		std::cout << "--Menu--\n 1. ADD: Save a new contact\n "
		"2. SEARCH: Display a specific contact\n 3. EXIT\n";
		std::cout << "Enter one option: ";
		std::getline(std::cin >> std::ws, option);
		if (option.length() == 1 && option[0] == '1')
		{
			std::string first_name;
			std::cout << "Enter the first name: ";
			std::getline(std::cin >> std::ws, first_name);

			std::string last_name;
			std::cout << "Enter the last name: ";
			std::getline(std::cin >> std::ws, last_name);

			std::string nickname;
			std::cout << "Enter the nickname: ";
			std::getline(std::cin >> std::ws, nickname);

			std::string phone_number;
			std::cout << "Enter the phone number: ";
			std::getline(std::cin >> std::ws, phone_number);

			std::string darkest_secret;
			std::cout << "Enter the darkest secret: ";
			std::getline(std::cin >> std::ws, darkest_secret);
			if(first_name == "" || last_name == "" || nickname == "" || phone_number == "" || darkest_secret == "")
			{
				std::cerr << "The contact must not have any empty fields\n" << std::endl;
				continue;
			}
			this->contacts[i % 8].add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
			std::cout << first_name << " " << last_name << " contact has been added\n" << std::endl;
			this->i++;
			continue;
		}
		else if (option.length() == 1 && option[0] == '2')
		{
			//Display the contacts
			int i = 0;
			std::cout << "index     |first name|last name |nickname  " << std::endl;
			while (i < 8 && this->contacts[i].first_name != "")
			{
				std::cout << i << "         |";
				if (this->contacts[i].first_name.length() < 10)
					std::cout << std::left << std::setfill(' ') << std::setw(10) << this->contacts[i].first_name << "|";
				else
					std::cout << this->contacts[i].first_name.substr(0, 9) << "." << "|";
				if (this->contacts[i].last_name.length() < 10)
					std::cout << std::left << std::setfill(' ') << std::setw(10) << this->contacts[i].last_name << "|";
				else
					std::cout << this->contacts[i].last_name.substr(0, 9) << "." << "|";
				if (this->contacts[i].nickname.length() < 10)
					std::cout << std::left << std::setfill(' ') << std::setw(10) << this->contacts[i].nickname;
				else
					std::cout << this->contacts[i].nickname.substr(0, 9) << ".";
				std::cout << std::endl;
				i++;
			}
			std::cout << std::endl;
			//Display the specific contact
			int index = 0;
			std::string index_str;
			std::cout << "Enter the index of the contact (0 - 7): ";
			std::getline(std::cin >> std::ws, index_str);
			if (index_str.length() > 1 || index_str[0] < '0' || index_str[0] > '7')
			{
				std::cout << "The index must be a number between 0 and 7\n" << std::endl;
				continue;
			}
			else
				index = index_str[0] - '0';
			if (this->contacts[index].first_name != "")
			{
				std::cout << "First name: " << this->contacts[index].first_name << std::endl;
				std::cout << "Last name: " << this->contacts[index].last_name << std::endl;
				std::cout << "Nickname: " << this->contacts[index].nickname << std::endl;
				std::cout << "Phone number: " << this->contacts[index].phone_number << std::endl;
				std::cout << "Darkest secret: " << this->contacts[index].darkest_secret << std::endl;
			}
			else
				std::cout << "The contact does not exist\n";
			std::cout << std::endl;
			continue;
		}
		else if (option.length() == 1 && option[0] == '3')
			break;
		else
			std::cout << "The command must be in the menu (1 - 3):\n" << std::endl;
	}
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called\n";
	return ;
}