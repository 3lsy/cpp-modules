/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 01:58:14 by echavez-          #+#    #+#             */
/*   Updated: 2024/03/02 19:04:18 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain *_brain;
public:
	Cat();
	~Cat();

	Cat(const Cat &src);
	Cat &operator=(const Cat &src);

	void makeSound() const override;
	//getter
	Brain *getBrain() const;
};

#endif