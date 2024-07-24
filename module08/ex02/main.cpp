/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:58:38 by echavez-          #+#    #+#             */
/*   Updated: 2024/07/24 12:28:47 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "MutantStack.hpp"

//subject main
int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // [...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    return 0;
}

//replacing with list
/*
int main() {
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    // [...]
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // std::stack<int> s(mlist); // This line is not needed for std::list

    return 0;
}
*/

/*
//My main
int main() {
    // Create a MutantStack of integers using default constructor
    MutantStack<int> mutantStack;

    // Push some elements onto the stack
    mutantStack.push(10);
    mutantStack.push(20);
    mutantStack.push(30);
    mutantStack.push(40);

    std::cout << "Iterating over MutantStack (forward): ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating over MutantStack (reverse): ";
    for (MutantStack<int>::reverse_iterator rit = mutantStack.rbegin(); rit != mutantStack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

	std::cout << "Modifiying the second element of the mutantStack..." << std::endl;
    MutantStack<int>::iterator it = mutantStack.begin();
    ++it; // Move iterator to the second element
    *it = 25; // Modify the second element

    std::cout << "Modified MutantStack (forward): ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Display the modified stack using reverse iterators
    std::cout << "Modified MutantStack (reverse): ";
    for (MutantStack<int>::reverse_iterator rit = mutantStack.rbegin(); rit != mutantStack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Copy constructor
    MutantStack<int> copiedStack(mutantStack);
    std::cout << "Copied MutantStack (forward): ";
    for (MutantStack<int>::iterator it = copiedStack.begin(); it != copiedStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Assignment operator
    MutantStack<int> assignedStack;
    assignedStack = mutantStack;
    std::cout << "Assigned MutantStack (forward): ";
    for (MutantStack<int>::iterator it = assignedStack.begin(); it != assignedStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

	//const test
	const MutantStack<int> constStack(mutantStack);
	std::cout << "Const MutantStack (forward): ";
	for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

    return 0;
}
*/