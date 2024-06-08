/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:21:43 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 00:02:30 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint> // uintptr_t
# include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();
		Serializer & operator=(Serializer const & src);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

//cout Data
std::ostream & operator<<(std::ostream & o, Data const & i);

#endif