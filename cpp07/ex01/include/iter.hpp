/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:21:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/16 16:23:03 by jfreitas      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

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

/*
 *** How to declare a pointer-to-function:
 *
 * return_type (* const function_name) (argument_list);
 *
 * return_type:            function return type.
 * const:                  the const keyword can be used (after the *).
 * function_name:  a name we'd like to call the pointer variable.
 * argument_list:          arguments to be sent to the funtion.
 *
 * OBS.: The parentheses around the function_name are necessary for
 * precedence reasons, as return_type * function_name() would be
 * interpreted as a forward declaration for a function named
 * function_name that takes no parameters and returns a pointer to
 * a return_type.
 *
 *** To assign a member function to the pointer, the syntax is:
 * return_type (*function_name)(){ &any_funtion };// function_name points to any_funtion
 * function_name = &any_funtion_2; // function_name now points to function any_funtion_2
 *
 *** Calling a function using a function pointer:
 * int (*fcnPtr)(int){ &foo }; // Initialize fcnPtr with function foo
 *   (*fcnPtr)(5);// call function foo(5) through fcnPtr.
 * OR with implicit dereference:
 *   fcnPtr(5);//some older compilers do not support the implicit dereference
 *               method, but all modern compilers should.
 */
template <typename T>
void iter(T &array, size_t const &length, void (* const func)(T)) {
	for (unsigned int i = 0; i < length; i++) {
		func(array[i]);
	}
}

#endif
