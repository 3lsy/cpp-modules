/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:37:06 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/10 00:15:39 by echavez-         ###   ########.fr       */
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
		
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
	private:
		std::string name;
};

void randomChump( std::string name );
Zombie	*newZombie(std::string name);

#endif