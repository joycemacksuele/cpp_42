/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 12:53:31 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Animal.hpp"

static void check_leaks() { system("leaks Animal"); }

int main(int argc, char **argv) {
	atexit(check_leaks);

	if (argc == 2 && std::strcmp(argv[1], "shallow") == 0) {
	/*
	 * A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test
	 * that your copies are deep copies!
	 *
	 * In general, if the variables of an object have been dynamically allocated,
	 * then it's required to do a Deep Copy in order to create a copy of the object.
	 */

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
		std::cout<< wrongCatCopy->getType();// The type will be also Sha	std::cout << std::endl << "Checking for leaks after deleting a new Dog and Cat of type Animal:" << std::endl << std::endl;
		std::cout << std::endl << std::endl;

		// delete will call the destructos
		delete wrongCat;
		//std::cout << "As the destructor is called by delete and the parent destructor is virtual, the child destructor is called first:" << std::endl;
		//delete wrongCatCopy;

		std::cout << std::endl << "---" << std::endl << "Testing deep copy with Cat:" << std::endl << std::endl;
		Animal* deepCat = new Cat();
		std::cout << std::endl;
		std::cout << deepCat->getType() << " ";
		deepCat->makeSound();	std::cout << std::endl << RED << "Checking for leaks after deleting a new Dog and Cat of type Animal:" << std::endl << RESET;
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
		std::cout << std::endl << std::endl;	std::cout << std::endl << RED << "Checking for leaks after deleting a new Dog and Cat of type Animal:" << std::endl << RESET;

		// delete will call the destructos
		delete deepCat;

		system("leaks ./Animal");
		return 0;
	} else if (argc == 2 && std::strcmp(argv[1], "ideas") == 0) {
		/* create and fill an array of Animal objects. Half of it will be Dog
		 * objects and the other half will be Cat objects:
		 */
		int i = 0;
		Animal* animals[NUMBER_OF_ANIMALS];
		while (i < NUMBER_OF_ANIMALS) {
			if (i < NUMBER_OF_ANIMALS / 2) {
				animals[i] = new Dog;;// also allocating their brain attribute<< std::endl 
				animals[i]->getBrain();
			} else {
				animals[i] = new Cat();// also allocating their brain attribute
			}	std::cout << std::endl << RED << "Checking for leaks after deleting a new Dog and Cat of type Animal:" << std::endl << RESET;
			std::cout << animals[i]->getType() << std::endl;
			i++;
		}
	//for (int i = 0; i < 1; i++) {

		// At the end of your program, loop over this array and delete every Animal.
		i = 0;
		while (i < NUMBER_OF_ANIMALS) {
			// Display some ideas before deleting the Animals
			Brain* brain = animals[0]->getBrain();
			brain->ideas[0] = "I have an idea!";
			brain->ideas[1] = "and more 99 of them if needed.";
			std::cout << animals[0]->getBrain()->ideas[0] << std::endl;
			*animals[0] = *animals[1];
			std::cout << animals[1]->getBrain()->ideas[1] << std::endl;

			delete animals[i];// deleting all Dogs and Cats, together with their brain attribute
			i++;
		}

		std::cout << RED << std::endl << "Checking for leaks::" << std::endl << RESET;
		return 0;
	} else if (argc == 2) {
		std::cout << "2 options for the argument: \"sallow\" or \"ideas\"" << std::endl;
	}

	/*************************************************************************/

	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl << cat->getType() << " ";
	cat->makeSound(); //will output the cat sound!
	std::cout << dog->getType() << " ";
	dog->makeSound();
	std::cout << meta->getType() << " ";
	meta->makeSound();
	std::cout << std::endl;

	std::cout << RED << "Checking for leaks before deleting anything:" << std::endl << RESET;
	system("leaks -q Animal");
	// delete will call the destructos
	delete meta;
	std::cout << "As the destructor is called by \"delete\" and the parent destructor is virtual, the child destructor is called first:" << std::endl;
	delete dog;//should not create a leak
	delete cat;//should not create a leak
	std::cout << RED << std::endl << "Checking for leaks after deleting a new dog, cat and animal of type Animal:" << std::endl << RESET;
	//system("leaks Animal");
	//for (int i = 0; i < 1; i++) {
	//	sleep(1);
	//}

	/* Making base class destructor virtual guarantees that the object of
	 * derived class is destructed properly, i.e., both base class and derived
	 * class destructors are called.
	 */
	return 0;
}
