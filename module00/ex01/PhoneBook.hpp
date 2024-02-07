/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:18:31 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/07 21:41:34 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iomanip>

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