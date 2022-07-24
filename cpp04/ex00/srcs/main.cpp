/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/22 16:49:26 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"


int main(int argc, char **argv) {

	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	std::cout << std::endl << c->getType() << " ";
	c->makeSound(); //will output the cat sound!
	std::cout << d->getType() << " ";
	d->makeSound();
	std::cout << meta->getType() << " ";
	meta->makeSound();
	std::cout << std::endl;

	// delete will call the destructos
	delete meta;
	std::cout << "As the destructor is called by delete and the parent destructor is virtual, the child destructor is called first:" << std::endl;
	delete d;
	delete c;

	// trying to access the protected variable from the Animal Class will throw an arror
	// meta->type;

	if (argc == 2 && std::strcmp(argv[1], "wrong") == 0) {
		std::cout << std::endl << "---" << std::endl << "Testing with WrongAnimal and WrongCat:" << std::endl << std::endl;
		const WrongAnimal* wrong = new WrongAnimal();
		const WrongAnimal* cat = new WrongCat();
		std::cout  << std::endl << cat->getType() << " ";
		// will output the WrongAnimal sound since this method is not a virtual method. i.e. is not overriten by the child class.
		cat->makeSound();
		std::cout<< wrong->getType() << " ";
		wrong->makeSound();
		std::cout << std::endl;
		// delete will call the destructos
		delete wrong;
		std::cout << "As the destructor is called by 'delete' and the parent destructor is virtual, the child destructor is called first:" << std::endl;
		delete cat;
	}

	/* Making base class destructor virtual guarantees that the object of
	 * derived class is destructed properly, i.e., both base class and derived
	 * class destructors are called.
	 */

	return 0;
}
