/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 09:46:21 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#include "./Animal.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// i.e. Dog = child/derived class AND Animal = base/parent class
class Dog : public Animal {

	public:
		Dog(void);// Default (no args) constructor
		Dog(const Dog& src);// Overloaded Copy constructor
		Dog& operator=(const Dog& rhs);// Copy assignment operator
		~Dog(void);// Destructor

		void makeSound() const;//overrites the parent class method
};

#endif
