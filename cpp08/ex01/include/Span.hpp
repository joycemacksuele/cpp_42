/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:17:58 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/24 17:22:25 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sstream>
#include <iomanip>
#include <vector>

#define RESET         "\033[0m"
#define RED           "\033[31m"
#define GREEN         "\033[32m"
#define YELLOW        "\033[33m"
#define BLUE          "\033[34m"
#define MAGENTA       "\033[35m"
#define CYAN          "\033[36m"
#define BOLD          "\x1B[1m"
#define CLEAR_SCREEN  "\033c"
#define ERASE_LINE    "\033[2K"
#define JUMP_ONE_LINE "\033[1B"

class Span {
	private:
		Span(void);// Default (no args) constructor
		unsigned int _spanSize;
		std::vector<int> _intVector;

	public:
		Span(unsigned int const & N);// Overloaded constructor
		Span(Span const & rhs);// Overloaded Copy constructor
		Span& operator=(Span const & rhs);// Assignment operator
		~Span(void);// Destructor

		/************************ getters and setters *************************/
		unsigned int const & getSpanSize() const;
		void setSpanSize(unsigned int const & spanSize);
		std::vector<int> const & getVector() const;
		void setIntVector(std::vector<int> const & intVector);

		/************************** member methods ****************************/
		void addNumber(int const & toAdd);
		int shortestSpan() const;
		int longestSpan() const;

		/************************* member variables ***************************/
		static bool verbose;
};

#endif
