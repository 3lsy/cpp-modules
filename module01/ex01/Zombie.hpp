/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:37:06 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/10 01:01:06 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <string>
# include <iostream>

class Zombie
{
	public:
		void	announce(void);
		void	setName(std::string name);
		
		Zombie(void);
		~Zombie(void);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif