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
		void    mergeList(std::list<int>& lst, std::list<int>& left, std::list<int>& right);
		void	mergeInsertSort(std::list<int>& lst);
};

#endif