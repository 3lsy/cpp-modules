/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 10:55:27 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 15:58:04 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);

		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif