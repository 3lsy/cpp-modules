/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:37:06 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/19 16:31:57 by echavez-         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
};

void randomChump( std::string name );
Zombie	*newZombie(std::string name);

#endif