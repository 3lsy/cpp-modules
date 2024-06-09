/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:15:11 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 12:30:31 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

//swap
template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

//min
template <typename T>
const T &min(const T &a, const T &b) {
	return (a < b) ? a : b;
}

//max
template <typename T>
const T &max(const T &a, const T &b) {
	return (a > b) ? a : b;
}

#endif