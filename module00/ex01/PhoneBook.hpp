/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:18:31 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/19 14:02:17 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>

class PhoneBook
{
private:
	int i = 0;
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	
	void	display_contacts(void);
	void	add_contact(void);
	void	search_contact(int index);
public:
	PhoneBook(void);
	~PhoneBook(void);
};

std::string get_string_input(std::string &input);
bool	is_printable(const std::string &input);

#endif