/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 19:23:56 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Animal.hpp"

static void check_leaks() {
	std::cout << std::endl << RED << "Checking for leaks:" << std::endl << RESET;
	std::cout << "-------------------------" << std::endl;
	system("leaks Animal");
}

static void print_err_arg() {
	std::cout << "-------------------------" << std::endl;
	std::cout << "2 options for the argument: " << GREEN << "\"deep\" or \"ideas\"" << RESET << std::endl;
	std::cout << "-------------------------" << std::endl;
}

int main(int argc, char **argv) {
	atexit(check_leaks);

	if (argc == 2 && std::strcmp(argv[1], "deep") == 0) {
		/*
		 * A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test
		 * that your copies are deep copies!
		 *
		 * In general, if the variables of an object have been dynamically allocated,
		 * then it's required to do a Deep Copy in order to create a copy of the object.
		 */
		std::cout << BLUE << "Testing deep copy with Cat:" << std::endl << RESET << std::endl;
		Animal* deepCat = new Cat();
//	ClapTrap attacker2("Attacker 2");
//	ClapTrap attacker3(attacker2);
		std::cout << std::endl;
		//std::cout << deepCat->getType() << " ";
		//deepCat->makeSound();

		deepCat->setType("Deep");
		std::cout << "Joyce (deepCat) type: " << deepCat->getType() << std::endl;

		// The copy constructor IS implemented (deep copy)
		std::cout << "before copy assignment?" << std::endl;
		Animal* catCopy = deepCat;
		std::cout << "After copy assignment?" << std::endl;

		std::cout << "Joyce (deepCat) type: " << deepCat->getType() << std::endl;
		std::cout << "Joyce (catCopy) type before setting: " << catCopy->getType() << std::endl;

		catCopy->setType("CatCopy");
		std::cout << "Joyce (catCopy) type after setting: " << catCopy->getType() << std::endl;
		std::cout << "Joyce (deepCat) type AFTER copy: " << deepCat->getType() << std::endl;


		//std::cout << catCopy->getType() << " ";
		//catCopy->makeSound();// will output the Cat sound since this method is virtual. i.e. is overriten by the child class.
		std::cout << std::endl;
		std::cout << "Setting type of Cat to 'Deep', then the copy of it will not be of type 'Deep', it will keep the same type 'CatCopy':" << std::endl;
		std::cout << "Cat type: ";
		std::cout<< deepCat->getType();
		std::cout << std::endl;
		std::cout << "CatCopy type: ";
		std::cout<< catCopy->getType();// The type will stay the same since it was a deep copy
		std::cout << std::endl << std::endl;
		// delete will call the destructos
		delete deepCat;

		std::cout << std::endl << "-------------------------" << std::endl << BLUE << "Testing shallow copy with WrongCat:" << std::endl << RESET << std::endl;
		WrongAnimal* wrongCat = new WrongCat();
		std::cout << std::endl;

		wrongCat->setType("Shallow");
		// The copy constructor is not implemented, the compiler will provide default copy constructor (shallow copy).
		WrongAnimal* wrongCatCopy = wrongCat;
		wrongCatCopy->setType("WrongCatCopy");
		std::cout << std::endl;
		std::cout << "Setting type of WrongCat to 'Shallow', then the copy of it will also be of type 'Shallow':" << std::endl;
		std::cout << "WrongCat type: ";
		std::cout<< wrongCat->getType();
		std::cout << std::endl;
		std::cout << "WrongCatCopy type: ";
		std::cout<< wrongCatCopy->getType();// The type will be also Sha	std::cout << std::endl << "Checking for leaks after deleting a new Dog and Cat of type Animal:" << std::endl << std::endl;
		std::cout << std::endl << std::endl;
		// delete will call the destructos
		delete wrongCat;


		return 0;
	} else if (argc == 2 && std::strcmp(argv[1], "ideas") == 0) {
		/* create and fill an array of Animal objects. Half of it will be Dog
		 * objects and the other half will be Cat objects:
		 */
		int i = 0;
		Animal* cat_or_dog[NUMBER_OF_ANIMALS];
		while (i < NUMBER_OF_ANIMALS) {
			if (i < NUMBER_OF_ANIMALS/2) {
				cat_or_dog[i] = new Dog;;// also allocating their brain attribute
			} else {
				cat_or_dog[i] = new Cat();// also allocating their brain attribute
			}
			i++;
		}

		// Display some ideas before deleting the cat_or_dog
		std::string idea = "I have an idea:";
		std::cout << std::endl;
		for (int i_idea = 0; i_idea < NUMBER_OF_ANIMALS; i_idea++) {
			Brain* brain = cat_or_dog[i_idea]->getBrain();
			brain->ideas[i_idea] = idea + (char)(i_idea + 49);
			std::cout << cat_or_dog[i_idea]->getType() << ": " <<  cat_or_dog[i_idea]->getBrain()->ideas[i_idea] << std::endl;
		}

		// At the end of your program, loop over this array and delete every Animal.
		std::cout << std::endl;
		i = 0;
		while (i < NUMBER_OF_ANIMALS) {
			delete cat_or_dog[i];// deleting all Dogs and Cats, together with their brain attribute
			i++;
		}

		return 0;
	} else if (argc == 2) {
		print_err_arg();
		return 0;
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

	// delete will call the destructos
	delete meta;
	std::cout << "As the destructor is called by \"delete\" and the parent destructor is virtual, the child destructor is called first:" << std::endl;
	delete dog;//should not create a leak
	delete cat;//should not create a leak


	/* Making base class destructor virtual guarantees that the object of
	 * derived class is destructed properly, i.e., both base class and derived
	 * class destructors are called.
	 */

	//char* mal = (char*)malloc(sizeof(char) * 3);
	//mal[0] = 'j';
	//mal[1] = 'o';
	//mal[2] = 'y';
	//free(mal);
	//std::cout << RESET << std::endl << std::endl;
	return 0;
}
