/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jfreitas <jfreita@student.codam.nl>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 17:21:27 by jfreitas      #+#    #+#                 */
/*   Updated: 2022/11/08 17:27:36 by jfreitas      ########   odam.nl         */
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

/* Conditions for the type of the argument:
 * 1. The two arguments have the same typename.
 * 2. The two arguments support all comparison operators.
 */

//swap: Swaps the values of two arguments. Does not return anything.
template <typename T>
void swap(T &arg1, T &arg2);

// min: Compares the two arguments and returns the smallest one.
// If the two arguments are equal, then it returns the second one.
template <typename T>
const T min(T &arg1, T &arg2);

//max: Compares the two arguments and returns the biggest one.
//If the two arguments are equal, then it returns the second one.
template <typename T>
const T max(T &arg1, T &arg2);

#endif
