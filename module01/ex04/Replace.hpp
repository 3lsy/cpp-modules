/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:13:08 by echavez-          #+#    #+#             */
/*   Updated: 2024/02/11 18:23:32 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

class Replace
{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;
	public:
		Replace(std::string filename, std::string s1, std::string s2);
		~Replace();
		void	replace();
};