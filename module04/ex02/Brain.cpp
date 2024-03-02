/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:55:17 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 16:21:52 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	}
	return *this;
}

void Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	return this->ideas[index];
}