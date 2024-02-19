/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:21:30 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/19 14:12:21 by echavez-         ###   ########.fr       */
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
		option = get_string_input(option);
		if ((option.length() == 1 && option[0] == '1') || option == "ADD")
		{
			std::string first;
			std::cout << "Enter the first name: ";
			first = get_string_input(first);

			std::string last;
			std::cout << "Enter the last name: ";
			last = get_string_input(last);

			std::string nick;
			std::cout << "Enter the nickname: ";
			nick = get_string_input(nick);

			std::string phone;
			std::cout << "Enter the phone number: ";
			phone = get_string_input(phone);

			std::string dark;
			std::cout << "Enter the darkest secret: ";
			dark = get_string_input(dark);
			if(first == "" || last == "" || nick == "" || phone == "" || dark == "")
			{
				std::cerr << "The contact must not have any empty fields\n" << std::endl;
				continue;
			}
			this->contacts[i % 8].add_contact(first, last, nick, phone, dark);
			std::cout << first << " " << last << " contact has been added\n" << std::endl;
			this->i++;
			continue;
		}
		else if ((option.length() == 1 && option[0] == '2') || option == "SEARCH")
		{
			//Display the contacts
			int i = 0;
			std::cout << "index     |first name|last name |nickname  " << std::endl;
			while (i < 8 && this->contacts[i].get_first_name() != "")
			{
				std::cout << i << "         |";
				if (this->contacts[i].get_first_name().length() < 10)
					std::cout << std::left << std::setfill(' ') << std::setw(10) << this->contacts[i].get_first_name() << "|";
				else
					std::cout << this->contacts[i].get_first_name().substr(0, 9) << "." << "|";
				if (this->contacts[i].get_last_name().length() < 10)
					std::cout << std::left << std::setfill(' ') << std::setw(10) << this->contacts[i].get_last_name() << "|";
				else
					std::cout << this->contacts[i].get_last_name().substr(0, 9) << "." << "|";
				if (this->contacts[i].get_nickname().length() < 10)
					std::cout << std::left << std::setfill(' ') << std::setw(10) << this->contacts[i].get_nickname();
				else
					std::cout << this->contacts[i].get_nickname().substr(0, 9) << ".";
				std::cout << std::endl;
				i++;
			}
			std::cout << std::endl;
			//Display the specific contact
			int index = 0;
			std::string index_str;
			std::cout << "Enter the index of the contact (0 - 7): ";
			index_str = get_string_input(index_str);
			if (index_str.length() > 1 || index_str[0] < '0' || index_str[0] > '7')
			{
				std::cerr << "The index must be a number between 0 and 7\n" << std::endl;
				continue;
			}
			else
				index = index_str[0] - '0';
			if (this->contacts[index].get_first_name() != "")
			{
				std::cout << "First name: " << this->contacts[index].get_first_name() << std::endl;
				std::cout << "Last name: " << this->contacts[index].get_last_name() << std::endl;
				std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
				std::cout << "Phone number: " << this->contacts[index].get_phone_number() << std::endl;
				std::cout << "Darkest secret: " << this->contacts[index].get_darkest_secret() << std::endl;
			}
			else
				std::cerr << "The contact does not exist\n";
			std::cout << std::endl;
			continue;
		}
		else if ((option.length() == 1 && option[0] == '3') || option == "EXIT")
			break;
		else
			std::cerr << "The command must be in the menu (1 - 3):\n" << std::endl;
	}
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called\n";
	return ;
}

bool	is_printable(const std::string &input) {
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] < 32 || input[i] == 127) { // Check for control characters and DEL
            return (false);
        }
    }
    return (true);
}

std::string get_string_input(std::string &input) {
    while (true) {
        std::getline(std::cin >> std::ws, input);
        if (std::cin.eof()) {
            std::cerr << "EOF encountered. Exiting." << std::endl;
            exit(1);
        } else if (std::cin.fail()) {
            std::cerr << "Error reading input. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        } else {
            if (!is_printable(input)) {
                std::cerr << "Input contains non printable characters. Please try again:" << std::endl;
                continue;
            }
            break;
        }
    }
    return input;
}
