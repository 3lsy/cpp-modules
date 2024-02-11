/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:31:59 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/11 16:56:35 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

class Weapon{
	private:
		std::string _type;
	public:
		Weapon(std::string type);
		~Weapon();
		const std::string &getType(void);
		void setType(std::string type);
};

#endif