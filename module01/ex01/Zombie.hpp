/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:37:06 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/19 16:42:00 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		void	announce(void);
		void	setName(std::string name);
		
		Zombie(void);
		~Zombie(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif