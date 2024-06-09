/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:55:42 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 16:09:26 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _length;
		// Helper function to copy elements from another array
    	void copyElements(const Array& src);
		bool outOfBounds;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &src);
		Array &operator=(const Array &src);
		~Array();
		// accessors
		T &operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		// get size of array
		unsigned int size() const;
};

# include "Array.tpp"

#endif