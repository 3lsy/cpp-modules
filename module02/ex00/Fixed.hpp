/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:23:07 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/29 16:40:54 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _fixedPointValue;
		static const int _fractionalBits;
	public:
		// Default constructor
		Fixed();
		// Copy constructor
		Fixed(const Fixed &fixed);
		// Destructor
		~Fixed();
		//copy assignment operator overload
		Fixed &operator=(const Fixed &fixed);
		//getters and setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif