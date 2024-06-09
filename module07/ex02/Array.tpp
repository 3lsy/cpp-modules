/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:09:59 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 16:12:35 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _length(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(NULL), _length(0)
{
	copyElements(src);
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete[] _array;
		_array = NULL;
		_length = 0;
		copyElements(src);
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _length;
}

// Subscript operator for accessing elements
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    try {
        if (index >= _length) {
            throw std::out_of_range("Index out of bounds");
        }
        return _array[index];
    } catch (const std::exception& e) {
        //std::cerr << "Exception: " << e.what() << std::endl;
        throw;
    }
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    try {
        if (index >= _length) {
            throw std::out_of_range("Index out of bounds");
        }
        return _array[index];
    } catch (const std::exception& e) {
        //std::cerr << "Exception: " << e.what() << std::endl;
        throw;
    }
}

// Helper function to copy elements from another array
template <typename T>
void Array<T>::copyElements(const Array& src) {
    _length = src._length;
    if (_length > 0) {
        _array = new T[_length];
        for (unsigned int i = 0; i < _length; ++i) {
            _array[i] = src._array[i];
        }
    }
}

#endif