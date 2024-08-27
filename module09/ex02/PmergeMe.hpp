/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:54:25 by echavez-          #+#    #+#             */
/*   Updated: 2024/08/27 16:28:59 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <algorithm>
# include <ctime>
# include <iterator>
# include <set>
# include <cstdlib>

class PmergeMe {
	private:
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		//methods
		void	merge(std::vector<int>& vec, int left, int middle, int right);
		void	mergeInsertSort(std::vector<int>& vec, int left, int right);
		void	mergeInsertSort(std::vector<int>& vec);
		void	mergeList(std::list<int>::iterator leftStart, std::list<int>::iterator leftEnd,
               std::list<int>::iterator rightStart, std::list<int>::iterator rightEnd);
		void	mergeInsertSort(std::list<int>& lst);
};

#endif