/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:23:07 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/29 18:13:05 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int _fixedPointValue;
		static const int _fractionalBits;
	public:
		// Default constructor
		Fixed();
		// Copy constructor
		Fixed(const Fixed &fixed);
		// Constructor with int value
		Fixed(const int value);
		// Constructor with float value
		Fixed(const float value);
		// Destructor
		~Fixed();

		//copy assignment operator overload
		Fixed &operator=(const Fixed &fixed);

		//getters and setters
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		// Convert to float and int
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif