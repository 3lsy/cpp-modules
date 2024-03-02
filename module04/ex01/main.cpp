/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:30:53 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:36:59 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n-----------" << std::endl;
	std::cout << "Animal Test" << std::endl;
	std::cout << "-----------" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << "\n--------------" << std::endl;
	std::cout << "Deep copy test" << std::endl;
	std::cout << "--------------" << std::endl;

	Cat basic;
	basic.getBrain()->setIdea(0, "THIS IS MY BRAIN");
	{
		Cat tmp = basic;
		std::cout << "TMP: " << tmp.getBrain()->getIdea(0) << std::endl;
	}
	std::cout << "BASIC: " << basic.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n----------------" << std::endl;
	std::cout << "Animal list test" << std::endl;
	std::cout << "----------------" << std::endl;

    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }

	return 0;
}
