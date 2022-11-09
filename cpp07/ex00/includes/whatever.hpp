/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:21:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/09 17:31:06 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

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

template <typename T>
//void swap(T &arg1, T &arg2);
void swap(T &arg1, T &arg2) {
	T temp;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
//const T min(T &arg1, T &arg2);
T const &min(T const &arg1, T const &arg2) {
	return arg1 < arg2 ? arg1 : arg2;
}

template <typename T>
//const T max(T &arg1, T &arg2);
T const &max(T const &arg1, T const &arg2) {
	return arg1 > arg2 ? arg1 : arg2;
}

/* Templates:
 * 
 *
 * Default templantes: template <typename T = int>
 * it will use the default type if no type is sent to it (explicitally): funcOrClass<>
 *
 *** Important: A template is literally a template; a class/function template
 *   is not a class, it's a recipe for creating a new class/function for each
 *   T we encounter.
 *** I.e. A template cannot be compiled into code, only the result of
 *   instantiating the template can be compiled.
 *
 */
#endif
