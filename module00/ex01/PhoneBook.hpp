/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:18:31 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/06 23:44:42 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
private:
	/* data */
public:
	int	i = 0;
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	
	PhoneBook(void);
	~PhoneBook(void);

	/*add_contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);*/
	void	add_contact(void);
	void	search_contact(int index);
};

#endif