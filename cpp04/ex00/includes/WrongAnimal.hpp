/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/19 19:46:00 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>
#include <unistd.h>

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

		//WrongAnimal(const std::string type);// Overloaded constructor (with one param)

		WrongAnimal(const WrongAnimal& src);// Overloaded Copy constructor
		WrongAnimal& operator=(const WrongAnimal& rhs);// Copy assignment operator
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
		~WrongAnimal(void);// Destructor

		virtual void makeSound() const;

		// getters
		std::string		getType() const;
		// setters
		void setType(std::string animalType);

	protected:
		std::string type;

};

#endif
