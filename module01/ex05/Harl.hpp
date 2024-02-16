/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:57:17 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/16 17:55:46 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

		void (Harl::*fptrs[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	public:
		Harl();
		~Harl();
		
		void	complain( std::string level );
};

#endif