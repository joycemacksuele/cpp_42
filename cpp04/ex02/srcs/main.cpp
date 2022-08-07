/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 20:33:34 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 18:20:32 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Animal.hpp"

static void check_leaks() {
	std::cout << std::endl << RED << "Checking for leaks:" << std::endl << RESET;
	std::cout << "-------------------------" << std::endl;
	system("leaks AAnimal");
}



int main(void) {
	atexit(check_leaks);

	//const AAnimal* meta = new AAnimal(); UNCOMMENT TO THE THE ERROR, It can't be instatiated since it's abstract
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	std::cout << std::endl << cat->getType() << " ";
	cat->makeSound(); //will output the cat sound!
	std::cout << dog->getType() << " ";
	dog->makeSound();
	//std::cout << meta->getType() << " ";
	//meta->makeSound();
	std::cout << std::endl;

	// delete will call the destructos
	//delete meta;
	delete dog;//should not create a leak
	delete cat;//should not create a leak

	/* Making base class destructor virtual guarantees that the object of
	 * derived class is destructed properly, i.e., both base class and derived
	 * class destructors are called.
	 */

	/*************************************************************************/

		/* create and fill an array of Animal objects. Half of it will be Dog
		 * objects and the other half will be Cat objects:
		 */
		std::cout << std::endl << "-------------------------" << std::endl << std::endl;
		int i = 0;
		AAnimal* cat_or_dog[NUMBER_OF_ANIMALS];
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
			std::cout << cat_or_dog[i_idea]->getType() << ": " << cat_or_dog[i_idea]->getBrain()->ideas[i_idea] << std::endl;
		}

		// At the end of your program, loop over this array and delete every Animal.
		std::cout << std::endl;
		i = 0;
		while (i < NUMBER_OF_ANIMALS) {
			delete cat_or_dog[i];// deleting all Dogs and Cats, together with their brain attribute
			i++;
		}

	return 0;
}
