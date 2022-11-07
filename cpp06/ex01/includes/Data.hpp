/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 13:08:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/07 15:49:44 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\x1B[1m"

// Create a non-empty (it means it has data members) Data structure.
struct Data {
	public:
		Data(const bool verbose);// Overloaded constructor
		Data(Data const &src);// Overloaded Copy constructor
		Data& operator=(Data const &rhs);// Copy assignment operator
		~Data(void);// Destructor

		// class member methods
		bool isVerbose() const;

	private:
		Data(void);// Default (no args) constructor
		bool _verbose;
};

#endif
