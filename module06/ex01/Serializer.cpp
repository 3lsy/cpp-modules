/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:22:15 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 00:05:20 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const & src) {
	*this = src;
}

Serializer::~Serializer() {}

Serializer & Serializer::operator=(Serializer const & src) {
	(void)src;
	return *this;
}

//Serialize & Deserialize
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

//cout Data
std::ostream & operator<<(std::ostream & o, Data const & i) {
	o << "ID: " << i.id << std::endl;
	o << "Name: " << i.name << std::endl;
	o << "Value: " << i.value;
	return o;
}