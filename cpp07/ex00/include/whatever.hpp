/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:21:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/16 15:49:19 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>
#include <unistd.h>
#include <exception>
#include <sstream>

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

template <typename T>
void swap(T &arg1, T &arg2) {
	T temp;
	temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
T const &min(T const &arg1, T const &arg2) {
	return arg1 < arg2 ? arg1 : arg2;
}

template <typename T>
T const &max(T const &arg1, T const &arg2) {
	return arg1 > arg2 ? arg1 : arg2;
}

/* Templates:
 *
 *** Why can templates only be implemented in the header file?
 *   Templates are often used in headers because the compiler needs to instantiate 
 *   different versions of the code, depending on the parameters given/deduced
 *   for template parameters, and it's easier (as a programmer) to let the
 *   compiler recompile the same code multiple times and deduplicate later.
 *   - https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 *
 *** Default templantes: template <typename T = int>
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
