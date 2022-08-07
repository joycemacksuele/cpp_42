/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/08/07 16:05:52 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#include "../includes/Brain.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#define NUMBER_OF_ANIMALS 4

/*
 * Access specifiers:
 * public: members are accessible from outside the class
 * private: members cannot be accessed (or viewed) from outside the class
 * protected: members cannot be accessed from outside the class, however, they
 *            can be accessed in inherited classes.
 */
class Animal {
	public:
		Animal(void);// Default (no args) constructor
		Animal(const Animal& src);// Overloaded Copy constructor
		virtual Animal& operator=(const Animal& rhs);// Copy assignment operator
		/* Good to know:
		 * - Move assignment operator is like the Copy assignment one, but the
		 *   parameter is a non const (since we will change it by null-ing it)
		 *   r-value reference (aka ClassName&& rhs).
		 *
		 * - Move assignment operator: will make the current instance point to
		 *   the value the rhs is pointing to, then null the rhs pointer (so rhs
		 *   pointer is lost/not accessible anymore).
		 *
		 * - Copy assignment operator will delete what is inside the current
		 *   instance, allocate a new necessary space to it and copy what is
		 *   inside the rhs to this memory just allocated on the current
		 *   instance (so the rhs pointer is still accessibe and still with the
		 *   value it had before (aka: now we have 2 addresses with the same
		 *   value in it)).
		 *   Important: to return a reference to the class since we don't want
		 *   a deep copy). -> ex: s2 = s1 is actually s2.operator=(s1);
		 */
		virtual ~Animal(void);// Destructor
		/* Deleting a derived class object using a pointer of base class type
		 * that has a non-virtual destructor results in undefined behavior.
		 * To correct this situation, the base class should be defined with
		 * a virtual destructor.
		 */

		virtual void		makeSound() const;// virtual method to be overriten by a child class

		// getters and setters
		const std::string&	getType() const;
		void				setType(const std::string& animalType);

		//needed so the array of type Animal can access Cats' or Dogs' brains
		virtual Brain*		getBrain() const;// virtual method to be overriten by a child class
		// C++11 has the override special identifier

	protected:
		std::string* type;// a pointer to test if its deep copy or not against WrongCat
};

#endif
