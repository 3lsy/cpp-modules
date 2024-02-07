/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:21:30 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/07 21:31:36 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::string	option;
	while (true)
	{
		std::cout << "--Menu--\n 1. ADD\n 2. SEARCH\n 3. EXIT\n";
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
				std::cout << "The contact must not have any empty fields\n";
				continue;
			}
			this->contacts[i % 8].add_contact(first_name, last_name, nickname, phone_number, darkest_secret);
			this->i++;
			continue;
		}
		else if (option.length() == 1 && option[0] == '2')
		{
			int index = 0;
			std::string index_str;
			std::cout << "Enter the index of the contact (0 - 7): ";
			std::getline(std::cin >> std::ws, index_str);
			if (index_str.length() > 1 || index_str[0] < '0' || index_str[0] > '7')
			{
				std::cout << "The index must be a number between 0 and 7\n";
				continue;
			}
			else
				index = index_str[0] - '0';
			if (this->contacts[index].first_name != "")
			{
				int spaces = 0;
				std::cout << "index     |first name|last name |nickname  " << std::endl;
				std::cout << index << "         |";
				if (this->contacts[index].first_name.length() < 10)
				{
					spaces = 10 - this->contacts[index].first_name.length();
					std::cout << this->contacts[index].first_name;
					for (int i = 0; i < spaces; i++)
						std::cout << " ";
					std::cout << "|";
				}
				else
					std::cout << this->contacts[index].first_name.substr(0, 9) << "." << "|";
				if (this->contacts[index].last_name.length() < 10)
				{
					spaces = 10 - this->contacts[index].last_name.length();
					std::cout << this->contacts[index].last_name;
					for (int i = 0; i < spaces; i++)
						std::cout << " ";
					std::cout << "|";
				}
				else
					std::cout << this->contacts[index].last_name.substr(0, 9) << "." << "|";
				if (this->contacts[index].nickname.length() < 10)
				{
					spaces = 10 - this->contacts[index].nickname.length();
					std::cout << this->contacts[index].nickname;
					for (int i = 0; i < spaces; i++)
						std::cout << " ";
				}
				else
					std::cout << this->contacts[index].nickname.substr(0, 9) << ".";
				std::cout << std::endl;
			}
			else
				std::cout << "The contact does not exist\n";
			continue;
		}
		else if (option.length() == 1 && option[0] == '3')
			break;
		else
			std::cout << "The command must be in the menu (1 - 3):\n";
	}
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called\n";
	return ;
}