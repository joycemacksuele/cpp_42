/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 10:04:12 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <string>
#include <iostream>
#include <unistd.h>

#include "./WrongAnimal.hpp"
#include "./Brain.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// i.e. WrongCat = child/derived class AND Animal = base/parent class
class WrongCat : public WrongAnimal {

	public:
		WrongCat(void);// Default (no args) constructor
		WrongCat(const std::string& type);// Overloaded constructor (with one param)
		WrongCat(const WrongCat& src);// Overloaded Copy constructor
		WrongCat& operator=(const WrongCat& rhs);// Copy assignment operator
		~WrongCat(void);// Destructor

		void makeSound() const;
		// does not overrites the parent method since it is not virtual there

		Brain* getBrain() const;//overrites the parent class method

	private:
		Brain* _brain;
};

#endif
