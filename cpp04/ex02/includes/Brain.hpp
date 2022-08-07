/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/12 16:10:30 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/07/29 18:43:53 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

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
class Brain {
	public:
		Brain(void);// Default (no args) constructor
		Brain(const Brain& src);// Overloaded Copy constructor
		Brain& operator=(const Brain& rhs);// Copy assignment operator
		virtual ~Brain(void);// Destructor
		/* Deleting a derived class object using a pointer of base class type
		 * that has a non-virtual destructor results in undefined behavior.
		 * To correct this situation, the base class should be defined with
		 * a virtual destructor.
		 */

		static const int _number_of_ideas = 100;
		std::string ideas[Brain::_number_of_ideas];
};

#endif
