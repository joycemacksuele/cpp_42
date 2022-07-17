/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/17 18:50:28 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class Animal {
	public:
		Animal(void);// Default (no args) constructor

		Animal(const std::string type);// Overloaded constructor (with one param)

		Animal(const Animal& src);// Overloaded Copy constructor
		Animal& operator=(const Animal& rhs);// Copy assignment operator
		// Important to return a reference to the class since we don't want a deep copy). ex: s2 = s1 is actually s2.operator=(s1);
		/* - Good to know: Move assignment operator is like the Copy one but the parameter
		 *   is a non const (since we will change it by null-ing it) r-value reference (aka ClassName&& rhs).
		 * - Move operator will make the current instance point to the value the rhs is pointing to,
		 *   then null the rhs pointer (so rhs pointer is lost/not accessible anymore).
		 * - Copy operator will delete what is inside the current instance, allocate a new
		 *   necessary space to it and copy what is inside the rhs to this memory just allocated
		 *   on the current instance (so the rhs pointer is still accessibe and still with the value
		 *   it had before (aka: now we have 2 addresses with the sam evalue in it)).
		 */
		~Animal(void);// Destructor

		virtual void makeSound() const;

		// getters
		std::string		getType() const;
		// setters
		void setType(std::string animalType);

	protected:
		std::string type;


};

#endif
