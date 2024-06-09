/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 11:16:51 by echavez-          #+#    #+#             */
/*   Updated: 2024/06/09 11:49:10 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

Base* generate() {
    int random = rand() % 3; // generate random number between 0 and 2
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return nullptr;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
		std::cout << "Unknown" << std::endl;
	}
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for the random number generator

    const int numTests = 10;
    for (int i = 0; i < numTests; ++i) {
        Base* obj = generate();
        
        std::cout << "Test " << i + 1 << ": ";
        identify(obj); // Identify using pointer

        std::cout << "Test " << i + 1 << " (reference): ";
        identify(*obj); // Identify using reference

        delete obj;
    }

    // Test type identification with explicit instantiation
    std::cout << "\nExplicit instantiation tests:\n";

    Base* a = new A();
    Base* b = new B();
    Base* c = new C();

    std::cout << "Instance of A: ";
    identify(a);
    identify(*a);

    std::cout << "Instance of B: ";
    identify(b);
    identify(*b);

    std::cout << "Instance of C: ";
    identify(c);
    identify(*c);

    delete a;
    delete b;
    delete c;

    return 0;
}
