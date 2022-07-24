/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/24 15:32:41 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Animal.hpp"


int main(int argc, char **argv) {

	if (argc == 2 && std::strcmp(argv[1], "shallow") == 0) {
		std::cout << "Testing shallow copy with WrongCat:" << std::endl << std::endl;
		WrongAnimal* wrongCat = new WrongCat();
		std::cout << std::endl;
		std::cout << wrongCat->getType() << " ";
		wrongCat->makeSound();
		// The copy constructor is not implemented, the compiler will provide default copy constructor (shallow copy).
		WrongAnimal* wrongCatCopy;
		wrongCatCopy = wrongCat;
		wrongCatCopy->setType("WrongCatCopy");
		std::cout << wrongCatCopy->getType() << " ";
		// will output the WrongAnimal sound since this method is not a virtual method. i.e. is not overriten by the child class.
		wrongCatCopy->makeSound();

		std::cout << std::endl;
		std::cout << "Setting type of WrongCat to 'Shallow', then the copy of it will also be of type 'Shallow'." << std::endl;
		wrongCat->setType("Shallow");
		std::cout << "WrongCat type: ";
		std::cout<< wrongCat->getType();
		std::cout << std::endl;
		std::cout << "WrongCatCopy type: ";
		std::cout<< wrongCatCopy->getType();// The type will be also Shallow
		std::cout << std::endl << std::endl;

		// delete will call the destructos
		delete wrongCat;
		//std::cout << "As the destructor is called by delete and the parent destructor is virtual, the child destructor is called first:" << std::endl;
		//delete wrongCatCopy;


		std::cout << std::endl << "---" << std::endl << "Testing deep copy with Cat:" << std::endl << std::endl;
		Animal* deepCat = new Cat();
		std::cout << std::endl;
		std::cout << deepCat->getType() << " ";
		deepCat->makeSound();
		// The copy constructor IS implemented (deep copy).
		Animal* catCopy = deepCat;
		catCopy->setType("CatCopy");
		std::cout << catCopy->getType() << " ";
		// will output the Cat sound since this method is virtual. i.e. is overriten by the child class.
		catCopy->makeSound();
 
		std::cout << std::endl;
		std::cout << "Setting type of Cat to 'Deep', then the copy of it will not be of type 'Deep', it will keep the same type 'CatCopy'." << std::endl;
		deepCat->setType("Deep");
		std::cout << "Cat type: ";
		std::cout<< deepCat->getType();
		std::cout << std::endl;
		std::cout << "CatCopy type: ";
		std::cout<< catCopy->getType();// The type will stay the same since it was a deep copy
		std::cout << std::endl << std::endl;

		// delete will call the destructos
		delete deepCat;

		return 0;
	}

	/* create and fill an array of Animal objects. Half of it will be Dog
	 * objects and the other half will be Cat objects:
	 */
	int i = 0;
	Animal* animals[NUMBER_OF_ANIMALS];
	while (i < NUMBER_OF_ANIMALS) {
		if (i < NUMBER_OF_ANIMALS / 2)
			animals[i] = new Dog();// also allocating their brain attribute
		else
			animals[i] = new Cat();// also allocating their brain attribute
		std::cout << animals[i]->getType() << std::endl;
		i++;
	}

	Brain* brain = animals[1]->getBrain();
	brain->ideas[0] = "I'm hungry";
	brain->ideas[1] = "That's a strange idea I'm having";
	brain->ideas[2] = "Ball!!!!!";
	brain->ideas[3] = "Squirrel!!!!!";
	std::cout << animals[3]->getBrain->ideas[0] << std::endl;
	*animals[2] = *animals[3];
	std::cout << animals[2]->getBrain->ideas[2] << std::endl;

	// At the end of your program, loop over this array and delete every Animal.
	i = 0;
	while (i < NUMBER_OF_ANIMALS) {
		delete animals[i];// also deleting their brain attribute
		i++;
	}

	
	/*const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;


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
		const WrongAnimal* wrongcat = new WrongCat();
		std::cout  << std::endl << wrongcat->getType() << " ";
		// will output the WrongAnimal sound since this method is not a virtual method. i.e. is not overriten by the child class.
		wrongcat->makeSound();
		std::cout << wrong->getType() << " ";
		wrong->makeSound();
		std::cout << std::endl;
		// delete will call the destructos
		delete wrong;
		std::cout << "As the destructor is called by delete and the parent destructor is virtual, the child destructor is called first:" << std::endl;
		delete wrongcat;
	}

	/* Making base class destructor virtual guarantees that the object of
	 * derived class is destructed properly, i.e., both base class and derived
	 * class destructors are called.i
	 */

	/*
	 * A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test
	 * that your copies are deep copies!
	 *
	 * In general, if the variables of an object have been dynamically allocated,
	 * then it's required to do a Deep Copy in order to create a copy of the object.
	 */



	return 0;
}
