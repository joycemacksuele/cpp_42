/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/19 19:50:19 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"


int main(int argc, char **argv) {

	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << c->getType() << " ";
	c->makeSound(); //will output the cat sound!
	std::cout << d->getType() << " ";
	d->makeSound();
	std::cout << meta->getType() << " ";
	meta->makeSound();

	// trying to access the protected variable from the Animal Class will throw an arror
	// meta->type;

	if (argc == 2 && std::strcmp(argv[1], "wrong") == 0) {
		std::cout << std::endl << "Testing with WrongAnimal and WrongCat:" << std::endl << std::endl;
		const WrongAnimal* wrong = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		std::cout << cat->getType() << " ";
		cat->makeSound(); //will output the WrongAnimal sound!
		std::cout << wrong->getType() << " ";
		wrong->makeSound();
	}

	return 0;
}
