/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 10:02:30 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#include "../includes/Brain.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

/*
 * Access specifiers:
 * public: members are accessible from outside the class
 * private: members cannot be accessed (or viewed) from outside the class
 * protected: members cannot be accessed from outside the class, however, they
 *            can be accessed in inherited classes.
 */
class WrongAnimal {
	public:
		WrongAnimal(void);// Default (no args) constructor
		WrongAnimal(const WrongAnimal& src);// Overloaded Copy constructor
		WrongAnimal& operator=(const WrongAnimal& rhs);// Copy assignment operator
		virtual ~WrongAnimal(void);// Destructor
		/* Deleting a derived class object using a pointer of base class type
		 * that has a non-virtual destructor results in undefined behavior.
		 * To correct this situation, the base class should be defined with
		 * a virtual destructor.
		 */

		void makeSound() const;
		// not virtual so the child class won't overrite it and so when this
		// method is called, it will execute this parent fuction.

		// getters and setters
		const std::string&	getType() const;
		void		setType(const std::string& animalType);

		//needed so the array of type Animal can access Cats' or Dogs' brains
		virtual Brain*		getBrain() const;// virtual method to be overriten by a child class
		// C++11 has the override special identifier

	protected:
		std::string type;
};

#endif
