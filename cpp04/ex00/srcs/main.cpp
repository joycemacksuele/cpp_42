/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/17 18:53:08 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main(void) {

	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << d->getType() << " ";
	d->makeSound(); //will output the cat sound!
	std::cout << c->getType() << " ";
	c->makeSound();
	std::cout << meta->getType() << " ";
	meta->makeSound();
	//...

	return 0;
}
