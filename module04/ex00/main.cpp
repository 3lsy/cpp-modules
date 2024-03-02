/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 02:30:53 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 18:42:22 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "\n-----Animal Test-----" << std::endl;
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

	std::cout << "\n------------------------" << std::endl;
	std::cout << "----WrongAnimal Test----" << std::endl;
	const WrongAnimal* wmeta = new WrongAnimal();
	const WrongAnimal* wi = new WrongCat();
	const WrongCat* used_as_WrongCat = new WrongCat();
	std::cout << wi->getType() << " " << std::endl;
	wi->makeSound(); //will not output the cat sound!
	wmeta->makeSound();
	used_as_WrongCat->makeSound();
	delete wmeta;
	delete wi;
	delete used_as_WrongCat;
	
	return 0;
}
